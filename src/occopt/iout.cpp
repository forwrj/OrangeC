/* Software License Agreement
 *
 *     Copyright(C) 1994-2019 David Lindauer, (LADSoft)
 *
 *     This file is part of the Orange C Compiler package.    }
 *
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 *
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 *
 */

/*
 * iout.c
 *
 * output routines for icode code gen->  Used only in optimizer tests.
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "iexpr.h"
#include "beinterf.h"
#include "CmdSwitch.h"
#include "ildata.h"

/*      variable initialization         */
extern int registersAssigned;

extern int tempCount;
extern BITINT bittab[BITINTBITS];
extern COMPILER_PARAMS cparams;
extern ARCH_ASM* chosenAssembler;
extern QUAD* intermed_head;
extern int cachedTempCount;
extern TEMP_INFO** tempInfo;
extern LIST *localfuncs, *localdata;
extern FILE* icdFile;
extern int nextLabel;
extern SimpleSymbol* currentFunction;
extern unsigned termCount;
extern QUAD* criticalThunks;
extern int cachedTempCount;
extern CmdSwitchString prm_output;
extern std::vector<SimpleSymbol*> temporarySymbols;
extern std::vector<SimpleSymbol*> functionVariables;
extern std::deque<BaseData*> baseData;
extern std::vector<SimpleSymbol*> externals;

extern int gentype; /* Current DC type */
extern int curseg;  /* Current seg */
extern int outcol;      /* Curront col (roughly) */
static char dataname[40];   /* Name of last label */

static int virtual_mode;
//static STRING* strtab;
static int newlabel;
static bool virtualMode;

void putamode(QUAD* q, IMODE* ap);
void nl(void);
void xstringseg(void);

/* Init module */
void ioutini(void)
{
    gentype = nogen;
    curseg = noseg;
    outcol = 0;
    virtual_mode = 0;
    newlabel = false;
//    strtab = nullptr;
}
static void iop_nop(QUAD* q)
{
    (void)q;
    oprintf(icdFile, "\tNOP");
}
static void iop_phi(QUAD* q)
{
    PHIDATA* phi = q->dc.v.phi;
    struct _phiblock* pb = phi->temps;
    SimpleExpression* enode = tempInfo[phi->T0]->enode;
    if (enode->right)
        oprintf(icdFile, "\tT%d[%s] = PHI(", phi->T0, ((SimpleSymbol*)(enode->right))->name);
    else
        oprintf(icdFile, "\tT%d = PHI(", phi->T0);
    while (pb)
    {
        oprintf(icdFile, "T%d(%d),", pb->Tn, pb->block->blocknum + 1);
        pb = pb->next;
    }
    oprintf(icdFile, ")\n");
}
/*
 * ICODE op display handlers
 */
static void iop_line(QUAD* q)
{
    if (cparams.prm_lines)
    {
        LINEDATA* ld = (LINEDATA*)q->dc.left;
        while (ld)
        {
            oprintf(icdFile, "; Line %d:\t%s\n", ld->lineno, ld->line);
            ld = ld->next;
        }
    }
}

/*-------------------------------------------------------------------------*/

static void iop_passthrough(QUAD* q)
{
    oprintf(icdFile, "%s\n", (char*)q->dc.left);
}
static void iop_datapassthrough(QUAD* q)
{
    oprintf(icdFile, "ASM DATA\n");
}
static void iop_skipcompare(QUAD* q) { oprintf(icdFile, "\tskipcompare %d\n", q->dc.v.label); }
/*-------------------------------------------------------------------------*/

static void iop_label(QUAD* q)
{
    nl();
    oprintf(icdFile, "L_%d:", q->dc.v.label);
    gentype = nogen;
}

/*-------------------------------------------------------------------------*/

static void putsingle(QUAD* q, IMODE* ap, const char* string)
{
    oprintf(icdFile, "\t%s", string);
    if (ap)
    {
        oputc('\t', icdFile);
        putamode(q, ap);
    }
}

/*-------------------------------------------------------------------------*/

static void iop_asmgoto(QUAD* q) { oprintf(icdFile, "\tASMGOTO\tL_%d:PC", q->dc.v.label); }
/*-------------------------------------------------------------------------*/

static void iop_goto(QUAD* q)
{
    oprintf(icdFile, "\tGOTO\tL_%d:PC", q->dc.v.label);
}
static void iop_directbranch(QUAD* q)
{
    putsingle(q, q->dc.left, "GOTO");
}

/*-------------------------------------------------------------------------*/

static void iop_gosub(QUAD* q)
{
    putsingle(q, q->dc.left, "GOSUB");
}

static void iop_fargosub(QUAD* q)
{
    putsingle(q, q->dc.left, "FARGOSUB");
}
/*-------------------------------------------------------------------------*/

static void iop_trap(QUAD* q)
{
    putsingle(q, q->dc.left, "TRAP");
}

/*-------------------------------------------------------------------------*/

static void iop_int(QUAD* q)
{
    putsingle(q, q->dc.left, "INT");
}

/*-------------------------------------------------------------------------*/

static void iop_ret(QUAD* q)
{
    oprintf(icdFile, "\tRET\t");
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void iop_fret(QUAD* q)
{
    oprintf(icdFile, "\tFRET\t");
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void iop_rett(QUAD* q)
{
    oprintf(icdFile, "\tRETT\n");
}

/*-------------------------------------------------------------------------*/

static void putbin(QUAD* q, const char* str)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    putamode(q, q->dc.left);
    oprintf(icdFile, " %s ", str);
    putamode(q, q->dc.right);
}

/*-------------------------------------------------------------------------*/

static void iop_add(QUAD* q)
{
    putbin(q, "+");
}

/*-------------------------------------------------------------------------*/

static void iop_sub(QUAD* q)
{
    putbin(q, "-");
}

/*-------------------------------------------------------------------------*/

static void iop_udiv(QUAD* q)
{
    putbin(q, "U/");
}

/*-------------------------------------------------------------------------*/

static void iop_umod(QUAD* q)
{
    putbin(q, "U%");
}

/*-------------------------------------------------------------------------*/

static void iop_sdiv(QUAD* q)
{
    putbin(q, "S/");
}

/*-------------------------------------------------------------------------*/

static void iop_smod(QUAD* q)
{
    putbin(q, "S%");
}

/*-------------------------------------------------------------------------*/
static void iop_muluh(QUAD* q)
{
    putbin(q, "U*H");
}
static void iop_mulsh(QUAD* q)
{
    putbin(q, "S*H");
}

static void iop_mul(QUAD* q)
{
    putbin(q, "*");
}

/*-------------------------------------------------------------------------*/

static void iop_lsl(QUAD* q)
{
    putbin(q, "<<");
}

/*-------------------------------------------------------------------------*/

static void iop_lsr(QUAD* q)
{
    putbin(q, "U>>");
}

/*-------------------------------------------------------------------------*/

static void iop_asr(QUAD* q)
{
    putbin(q, "S>>");
}

/*-------------------------------------------------------------------------*/

static void iop_and(QUAD* q)
{
    putbin(q, "&");
}

/*-------------------------------------------------------------------------*/

static void iop_or(QUAD* q)
{
    putbin(q, "|");
}

/*-------------------------------------------------------------------------*/

static void iop_eor(QUAD* q)
{
    putbin(q, "^");
}

/*-------------------------------------------------------------------------*/

static void putunary(QUAD* q, const char* str)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    oprintf(icdFile, " %s ", str);
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void putasunary(QUAD* q, const char* str)
{
    oputc('\t', icdFile);
    if (q->ans)
        putamode(q, q->ans);
    oprintf(icdFile, " %s ", str);
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void iop_neg(QUAD* q)
{
    putunary(q, "-");
}

/*-------------------------------------------------------------------------*/

static void iop_not(QUAD* q)
{
    putunary(q, "~");
}

/*-------------------------------------------------------------------------*/

static void iop_assn(QUAD* q)
{
    putunary(q, "");
}

/*-------------------------------------------------------------------------*/

static void iop_genword(QUAD* q)
{
    putsingle(q, q->dc.left, "genword");
}

/*-------------------------------------------------------------------------*/

static void iop_coswitch(QUAD* q)
{
    oprintf(icdFile, "\tCOSWITCH(");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->ans);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
    oputc(',', icdFile);
    oprintf(icdFile, "L_%d:PC)", q->dc.v.label);
}
static void iop_swbranch(QUAD* q)
{
    oprintf(icdFile, "\tSWBRANCH(");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    oprintf(icdFile, "L_%d:PC)", q->dc.v.label);
}

/*-------------------------------------------------------------------------*/

static void iop_array(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    oprintf(icdFile, " ARRAY ");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}

/*-------------------------------------------------------------------------*/

static void iop_arrayindex(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    oprintf(icdFile, " ARRIND ");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
/*-------------------------------------------------------------------------*/

static void iop_arraylsh(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    oprintf(icdFile, " ARR<< ");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
static void iop_struct(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    oprintf(icdFile, " STRUCT ");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
/*-------------------------------------------------------------------------*/

static void iop_assnblock(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->dc.left);
    oprintf(icdFile, " BLOCK= ");
    putamode(q, q->dc.right);
    oprintf(icdFile, "(");
    putamode(q, q->ans);
    oprintf(icdFile, ")");
}

/*-------------------------------------------------------------------------*/

static void iop_clrblock(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->dc.left);
    oprintf(icdFile, " BLKCLR ");
    oprintf(icdFile, "(");
    putamode(q, q->dc.right);
    oprintf(icdFile, ")");
}
static void iop_cmpblock(QUAD* q)
{
    oputc('\t', icdFile);
    oprintf(icdFile, " BLKCOMPARE:L_%d:PC, ", q->dc.v.label);
    putamode(q, q->dc.left);
    oprintf(icdFile, " != ");
    putamode(q, q->dc.right);
}
static void iop_initblk(QUAD* q)
{
    oputc('\t', icdFile);
    oprintf(icdFile, "initblk");
}
static void iop_cpblk(QUAD* q)
{
    oputc('\t', icdFile);
    oprintf(icdFile, "cpblk");
}
/*-------------------------------------------------------------------------*/

static void iop_asmcond(QUAD* q) { oprintf(icdFile, "\tASMCOND\tL_%d:PC", q->dc.v.label); }
/*-------------------------------------------------------------------------*/

static void putjmp(QUAD* q, const char* str)
{
    oprintf(icdFile, "\tCONDGO\tL_%d:PC ; ", q->dc.v.label);
    if (q->dc.left)
        putamode(q, q->dc.left);
    oprintf(icdFile, " %s ", str);
    if (q->dc.right)
        putamode(q, q->dc.right);
}

/*-------------------------------------------------------------------------*/

static void putset(QUAD* q, const char* str)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " = ");
    putamode(q, q->dc.left);
    oprintf(icdFile, " %s ", str);
    putamode(q, q->dc.right);
}

/*-------------------------------------------------------------------------*/

static void iop_jc(QUAD* q)
{
    putjmp(q, "U<");
}

/*-------------------------------------------------------------------------*/

static void iop_ja(QUAD* q)
{
    putjmp(q, "U>");
}

/*-------------------------------------------------------------------------*/

static void iop_je(QUAD* q)
{
    putjmp(q, "==");
}

/*-------------------------------------------------------------------------*/

static void iop_jnc(QUAD* q)
{
    putjmp(q, "U>=");
}

/*-------------------------------------------------------------------------*/

static void iop_jbe(QUAD* q)
{
    putjmp(q, "U<=");
}

/*-------------------------------------------------------------------------*/

static void iop_jne(QUAD* q)
{
    putjmp(q, "!=");
}

/*-------------------------------------------------------------------------*/

static void iop_jl(QUAD* q)
{
    putjmp(q, "S<");
}

/*-------------------------------------------------------------------------*/

static void iop_jg(QUAD* q)
{
    putjmp(q, "S>");
}

/*-------------------------------------------------------------------------*/

static void iop_jle(QUAD* q)
{
    putjmp(q, "S<=");
}

/*-------------------------------------------------------------------------*/

static void iop_jge(QUAD* q)
{
    putjmp(q, "S>=");
}

/*-------------------------------------------------------------------------*/

static void iop_setc(QUAD* q)
{
    putset(q, "U<");
}

/*-------------------------------------------------------------------------*/

static void iop_seta(QUAD* q)
{
    putset(q, "U>");
}

/*-------------------------------------------------------------------------*/

static void iop_sete(QUAD* q)
{
    putset(q, "==");
}

/*-------------------------------------------------------------------------*/

static void iop_setnc(QUAD* q)
{
    putset(q, "U>=");
}

/*-------------------------------------------------------------------------*/

static void iop_setbe(QUAD* q)
{
    putset(q, "U<=");
}

/*-------------------------------------------------------------------------*/

static void iop_setne(QUAD* q)
{
    putset(q, "!=");
}

/*-------------------------------------------------------------------------*/

static void iop_setl(QUAD* q)
{
    putset(q, "S<");
}

/*-------------------------------------------------------------------------*/

static void iop_setg(QUAD* q)
{
    putset(q, "S>");
}

/*-------------------------------------------------------------------------*/

static void iop_setle(QUAD* q)
{
    putset(q, "S<=");
}

/*-------------------------------------------------------------------------*/

static void iop_setge(QUAD* q)
{
    putset(q, "S>=");
}

/*-------------------------------------------------------------------------*/

static void iop_parm(QUAD* q)
{
    // for fastcall, the moves generated before the push are sufficient.
    if (q->fastcall)
        return;
    oprintf(icdFile, "\tPARM\t");
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void iop_parmadj(QUAD* q)
{
    oprintf(icdFile, "\tPARMADJ\t");
    putamode(q, q->dc.left);
}

/*-------------------------------------------------------------------------*/

static void iop_parmblock(QUAD* q)
{
    oprintf(icdFile, "\tPARMBLOCK");
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}

/*-------------------------------------------------------------------------*/

static void iop_cppini(QUAD* q)
{
    oprintf(icdFile, "\tCPPINI");
}

/*-------------------------------------------------------------------------*/
static void iop_dbgblock(QUAD* q)
{
    oprintf(icdFile, "\tDBG BLOCK START");
}

/*-------------------------------------------------------------------------*/

static void iop_dbgblockend(QUAD* q)
{
    oprintf(icdFile, "\tDBG BLOCK END");
}
static void iop_block(QUAD* q) { oprintf(icdFile, "\tBLOCK %d", q->dc.v.label + 1); }

/*-------------------------------------------------------------------------*/

static void iop_blockend(QUAD* q)
{
    oprintf(icdFile, "\tBLOCK END");
    /*
    if (q->dc.v.data)
    {
        int i, j;
        BITINT* p;
        oprintf(icdFile, "\n;\tLive: ");
        p = (BITINT*)q->dc.v.data;

        for (i = 0; i < (tempCount + BITINTBITS - 1) / BITINTBITS; i++, p++)
            if (*p)
                for (j = 0; j < BITINTBITS; j++)
                    if ((*p) & (1 << j))
                        oprintf(icdFile, "TEMP%d, ", i * BITINTBITS + j);
    }
    */
}

static void iop_varstart(QUAD* q)
{
    oprintf(icdFile, "\tVAR START\t%s", q->dc.left->offset->sp->name);
}
static void iop_func(QUAD* q)
{
}
/*-------------------------------------------------------------------------*/

static void iop_livein(QUAD* q)
{
    (void)q;
    diag("op_livein: propogated live-in node");
}

/*-------------------------------------------------------------------------*/

static void iop_icon(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " C= #%llX", q->dc.v.i);
}

/*-------------------------------------------------------------------------*/

static void iop_fcon(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " C= #%s", ((std::string)q->dc.v.f).c_str());
}
static void iop_imcon(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " C= #%s", ((std::string)q->dc.v.f).c_str());
}
static void iop_cxcon(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, " C= #%s + %s * I", ((std::string)q->dc.v.c.r).c_str(), ((std::string)q->dc.v.c.i).c_str());
}
static void iop_prologue(QUAD* q)
{
    oprintf(icdFile, "\tPROLOGUE");
    oputc('\t', icdFile);
    if (!q->dc.left || !q->dc.right)
    {
        oprintf(icdFile, "unset");
    }
    else
    {
        putamode(q, q->dc.left);
        oputc(',', icdFile);
        putamode(q, q->dc.right);
    }
}
static void iop_epilogue(QUAD* q)
{
    oprintf(icdFile, "\tEPILOGUE");
    oputc('\t', icdFile);
    if (!q->dc.left)
    {
        oprintf(icdFile, "unset");
    }
    else
    {
        putamode(q, q->dc.left);
    }
}
static void iop_pushcontext(QUAD* q)
{
    oprintf(icdFile, "\tPUSHCONTEXT", q->dc.v.label);
}
static void iop_popcontext(QUAD* q)
{
    oprintf(icdFile, "\tPOPCONTEXT", q->dc.v.label);
}
static void iop_loadcontext(QUAD* q)
{
    oprintf(icdFile, "\tLOADCONTEXT", q->dc.v.label);
}
static void iop_unloadcontext(QUAD* q)
{
    oprintf(icdFile, "\tUNLOADCONTEXT", q->dc.v.label);
}
static void iop_tryblock(QUAD* q)
{
    (void)q;
}
static void iop_substack(QUAD* q)
{
    putasunary(q, "STACKALLOC");
}
static void iop_loadstack(QUAD* q)
{
    oprintf(icdFile, "\tLOADSTACK");
    oputc('\t', icdFile);
    putamode(q, q->dc.left);
}
static void iop_savestack(QUAD* q)
{
    oprintf(icdFile, "\tSAVESTACK");
    oputc('\t', icdFile);
    putamode(q, q->dc.left);
}
static void iop_functailstart(QUAD* q)
{
    oprintf(icdFile, "\tTAILBEGIN");
}
static void iop_functailend(QUAD* q)
{
    oprintf(icdFile, "\tTAILEND");
}
static void iop_gcsestub(QUAD* q) { oprintf(icdFile, "\tGCSE"); }
static void iop_expressiontag(QUAD* q)
{
    oprintf(icdFile, "\tEXPR TAG\t%d", q->dc.v.label);
}
static void iop_tag(QUAD* q)
{
    oprintf(icdFile, "\tTAG");
}
static void iop_seh(QUAD* q)
{
    oprintf(icdFile, "\tSEH %d", q->sehMode);
}
static void iop_atomic_fence(QUAD* q)
{
    oprintf(icdFile, "\tATOMIC FENCE");
    oputc(' ', icdFile);
    putamode(q, q->dc.left);
}
static void iop_atomic_flag_fence(QUAD* q)
{
    oputc('\t', icdFile);
    if (q->ans)
    {
        putamode(q, q->ans);
        oprintf(icdFile, " = ");
    }
    oprintf(icdFile, "ATOMIC FLAG FENCE");
    oputc(' ', icdFile);
    putamode(q, q->dc.left);
    oputc(',', icdFile);
            putamode(q, q->dc.right);
}
static void iop_atomic_flag_test_and_set(QUAD* q)
{
    oputc('\t', icdFile);
    putamode(q, q->ans);
    oprintf(icdFile, "\t=ATOMIC TEST AND SET");
    oputc(' ', icdFile);
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
static void iop_atomic_flag_clear(QUAD* q)
{
    oprintf(icdFile, "\tATOMIC CLEAR");
    oputc(' ', icdFile);
    putamode(q, q->dc.left);
}
static void iop_cmpswp(QUAD* q)
{
    oprintf(icdFile, "\tCMPSWP\t");
    putamode(q, q->ans);
    oputc(',', icdFile);
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
static void iop_xchg(QUAD* q)
{
    oprintf(icdFile, "\tXCHG\t");
    putamode(q, q->ans);
    oputc(',', icdFile);
    putamode(q, q->dc.left);
    oputc(',', icdFile);
    putamode(q, q->dc.right);
}
/* List of opcodes
 * This list MUST be in the same order as the op_ enums
 */
static void (*oplst[])(QUAD* q) = {
    /* NOPROTO */
    iop_nop,
    iop_phi,
    iop_line,
    iop_passthrough,
    iop_datapassthrough,
    iop_skipcompare,
    iop_label,
    iop_asmgoto,
    iop_goto,
    iop_directbranch,
    iop_gosub,
    iop_fargosub,
    iop_trap,
    iop_int,
    iop_ret,
    iop_fret,
    iop_rett,
    iop_add,
    iop_sub,
    iop_udiv,
    iop_umod,
    iop_sdiv,
    iop_smod,
    iop_muluh,
    iop_mulsh,
    iop_mul,
    iop_lsl,
    iop_lsr,
    iop_asr,
    iop_neg,
    iop_not,
    iop_and,
    iop_or,
    iop_eor,
    iop_setne,
    iop_sete,
    iop_setc,
    iop_seta,
    iop_setnc,
    iop_setbe,
    iop_setl,
    iop_setg,
    iop_setle,
    iop_setge,
    iop_asmcond,
    iop_jne,
    iop_je,
    iop_jc,
    iop_ja,
    iop_jnc,
    iop_jbe,
    iop_jl,
    iop_jg,
    iop_jle,
    iop_jge,
    iop_assn,
    iop_genword,
    iop_coswitch,
    iop_swbranch,
    iop_assnblock,
    iop_clrblock,
    iop_cmpblock,
    iop_parmadj,
    iop_parmblock,
    iop_parm,
    iop_array,
    iop_arrayindex,
    iop_arraylsh,
    iop_struct,
    iop_cppini,
    iop_block,
    iop_blockend,
    iop_dbgblock,
    iop_dbgblockend,
    iop_varstart,
    iop_func,
    iop_livein,
    iop_icon,
    iop_fcon,
    iop_imcon,
    iop_cxcon,
    iop_atomic_flag_test_and_set,
    iop_atomic_flag_clear,
    iop_atomic_fence,
    iop_atomic_flag_fence,
    iop_cmpswp,
    iop_xchg,
    iop_prologue,
    iop_epilogue,
    iop_pushcontext,
    iop_popcontext,
    iop_loadcontext,
    iop_unloadcontext,
    iop_tryblock,
    iop_substack,
    iop_substack,
    iop_loadstack,
    iop_savestack,
    iop_functailstart,
    iop_functailend,
    iop_gcsestub,
    iop_expressiontag,
    iop_tag,
    iop_seh,
    iop_initblk,
    iop_cpblk};
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/

void putconst(SimpleExpression* offset, int color)
/*
 *      put a constant to the icdFile file.
 */
{
    switch (offset->type)
    {
        case se_fc:
            oprintf(icdFile, "%s + %s * I", ((std::string)offset->c.r).c_str(), ((std::string)offset->c.i).c_str());
            break;
        case se_i:
        case se_ui:
            oprintf(icdFile, "%llX", offset->i);
            break;
        case se_f:
        case se_fi:
            oprintf(icdFile, "%s", ((std::string)offset->f).c_str());
            break;
        case se_tempref:
            if (offset->sp)
            {
                SimpleSymbol* sym = (SimpleSymbol*)offset->sp;
                if (offset->right)
                    oprintf(icdFile, "T%d[%s]", (int)(sym->i), ((SimpleSymbol*)offset->right)->name);
                else
                    oprintf(icdFile, "T%d", (int)sym->i);
                if (registersAssigned)
                    oprintf(icdFile, "(%s)", lookupRegName(color));
            }
            else
            {
                oprintf(icdFile, "T%d", (offset->sp)->i);
                if (registersAssigned)
                    oprintf(icdFile, "(%s)", lookupRegName(color));
            }
            break;
        case se_auto:
            oprintf(icdFile, "%s:LINK", (offset->sp)->outputName);
            oprintf(icdFile, "(%d)", offset->sp->offset);
            break;
        case se_structelem:
            oprintf(icdFile, "%s:STRUCTELEM(%d)", (offset->sp)->outputName, offset->sp->offset);
            break;
        case se_string:
            if (offset->astring.str)
            {
                int i;
                oputc('"', icdFile);
                for (i = 0; i < offset->astring.len; i++)
                {
                    oputc(offset->astring.str[i], icdFile);
                }
                oputc('"', icdFile);
            }
            break;
        case se_labcon:
            oprintf(icdFile, "L_%ld:PC", offset->i);
            break;
        case se_pc:
            oprintf(icdFile, "%s:PC", (offset->sp)->outputName);
            break;
        case se_threadlocal:
            oprintf(icdFile, "%s:TLS", (offset->sp)->outputName);
            break;
        case se_global:
            oprintf(icdFile, "%s:RAM", (offset->sp)->outputName);
            break;
        case se_absolute:
            oprintf(icdFile, "$%lX:ABS", (offset->sp)->i);
            break;
        case se_add:
            putconst(offset->left, color);
            oprintf(icdFile, "+");
            putconst(offset->right, color);
            break;
        case se_sub:
            putconst(offset->left, color);
            oprintf(icdFile, "-");
            putconst(offset->right, color);
            break;
        case se_uminus:
            oputc('-', icdFile);
            putconst(offset->left, color);
            break;
        default:
            diag("putconst: illegal constant node.");
            break;
    }
}

/*-------------------------------------------------------------------------*/

void putlen(int l)
/*
 *      append the length field to a value
 */
{
    switch (l)
    {
        case ISZ_REG:
            break;
        case ISZ_NONE:
            oprintf(icdFile, ".N");
            break;
        case ISZ_BOOLEAN:
            oprintf(icdFile, ".BOOL");
            break;
        case ISZ_STRING:
            oprintf(icdFile, ".STRING");
            break;
        case ISZ_OBJECT:
            oprintf(icdFile, ".OBJECT");
            break;
        case ISZ_ADDR:
            oprintf(icdFile, ".A");
            break;
        case ISZ_FARPTR:
            oprintf(icdFile, ".FA");
            break;
        case ISZ_SEG:
            oprintf(icdFile, ".SA");
            break;
        case ISZ_UCHAR:
            oprintf(icdFile, ".UC");
            break;
        case -ISZ_UCHAR:
            oprintf(icdFile, ".C");
            break;
        case ISZ_U16:
            oprintf(icdFile, ".U16");
            break;
        case ISZ_U32:
            oprintf(icdFile, ".U32");
            break;
        case ISZ_USHORT:
            oprintf(icdFile, ".US");
            break;
        case -ISZ_USHORT:
            oprintf(icdFile, ".S");
            break;
        case ISZ_UINT:
            oprintf(icdFile, ".UI");
            break;
        case -ISZ_UINT:
            oprintf(icdFile, ".I");
            break;
        case ISZ_UNATIVE:
            oprintf(icdFile, ".UNATIVE");
            break;
        case -ISZ_UNATIVE:
            oprintf(icdFile, ".INATIVE");
            break;
        case ISZ_ULONG:
            oprintf(icdFile, ".UL");
            break;
        case -ISZ_ULONG:
            oprintf(icdFile, ".L");
            break;
        case ISZ_ULONGLONG:
            oprintf(icdFile, ".ULL");
            break;
        case -ISZ_ULONGLONG:
            oprintf(icdFile, ".LL");
            break;
        case ISZ_FLOAT:
            oprintf(icdFile, ".F");
            break;
        case ISZ_DOUBLE:
            oprintf(icdFile, ".D");
            break;
        case ISZ_LDOUBLE:
            oprintf(icdFile, ".LD");
            break;
        case ISZ_IFLOAT:
            oprintf(icdFile, ".IF");
            break;
        case ISZ_IDOUBLE:
            oprintf(icdFile, ".ID");
            break;
        case ISZ_ILDOUBLE:
            oprintf(icdFile, ".ILD");
            break;
        case ISZ_CFLOAT:
            oprintf(icdFile, ".CF");
            break;
        case ISZ_CDOUBLE:
            oprintf(icdFile, ".CD");
            break;
        case ISZ_CLDOUBLE:
            oprintf(icdFile, ".CLD");
            break;
        case ISZ_BIT:
            oprintf(icdFile, ".BIT");
            break;
        default:
            diag("putlen: illegal length field.");
            break;
    }
}

/*-------------------------------------------------------------------------*/

void putamode(QUAD* q, IMODE* ap)
/*
 *      output a general addressing mode.
 */
{
    /* We want to see if the compiler does anything wrong with
     * volatiles
     */
    int color = 0;
    if (q)
    {
        if (q->ans == ap)
            color = q->ansColor;
        else if (q->dc.left == ap)
            color = q->leftColor;
        else
            color = q->rightColor;
    }
    if (ap->offset && ap->offset->isvolatile)
        oputc('%', icdFile);
    switch (ap->mode)
    {
        case i_immed:
            oputc('#', icdFile);
            putconst(ap->offset, color);
            break;
        case i_ind:
            oputc('*', icdFile);
            oputc('(', icdFile);
            if (ap->offset)
                putconst(ap->offset, color);
            else
                oputc('#', icdFile);
            if (ap->offset2)
            {
                oprintf(icdFile, " + ");
                putconst(ap->offset2, q->scaleColor);
                if (ap->scale)
                    oprintf(icdFile, " * %d", 1 << ap->scale);
            }
            if (ap->offset3)
            {
                oprintf(icdFile, " + ");
                putconst(ap->offset3, color);
            }
            oputc(')', icdFile);
            break;
        case i_direct:
            if (ap->retval)
            {
                oprintf(icdFile, "RV.");
            }
            putconst(ap->offset, color);
            break;
        default:
            diag("putamode: illegal address mode.");
            break;
    }
    if (ap->bits)
        oprintf(icdFile, "{%d:%d}", ap->startbit, ap->bits);
    if (ap->mode == i_ind)
        putlen(ap->ptrsize);
    putlen(ap->size);
    //    if (q)
    //        oprintf(icdFile,"[0x%x]", q->liveRegs);
}

/*-------------------------------------------------------------------------*/
extern BLOCK** blockArray;
extern int blockCount;
void put_code(QUAD* q)
/*
 *      output a generic instruction.
 */
{
    int i;
    if (q->block && q->block->head == q)
    {
        oprintf(icdFile, "block %d\n", q->block->blocknum);
    }
    (*oplst[q->dc.opcode])(q);
    if (q->genConflict)
        oputc('^', icdFile);
    oputc('\n', icdFile);
}

/*
 * Very simple live variable analysis.  Only to be used with
 * temp regs at the moment...
 */

/*
 * Low level routinne to rewrite code for processor and dump it.
 * Here we only need dump
 */

static void PutFunc(BaseData *d)
{
    intermed_head = d->funcData->instructionList;
    functionVariables = d->funcData->variables;
    temporarySymbols = d->funcData->temporarySymbols;
    QUAD* q = intermed_head;
    while (q)
    {
        put_code(q);
        q = q->fwd;
    }
    intermed_head = 0;
}

static void PutFloat(const char *sz, FPF& flt)
{
    oprintf(icdFile, "DC%s %s", sz, ((std::string)flt).c_str());
    nl;
}
static void PutComplex(const char *sz, FPF& r, FPF& i)
{
    oprintf(icdFile, "DC%s %s+%s*I", sz, ((std::string)r).c_str(), ((std::string)i).c_str());
    nl;
}
static void PutData(BaseData* data)
{
    std::vector<std::string> segs =
    {
        "exitseg", "codeseg", "dataseg", "bssxseg", "stringseg", "constseg", "tlsseg", "startupxseg",
        "rundownxseg", "tlssuseg", "tlsrdseg", "typeseg", "symseg", "browseseg",
        "fixcseg", "fixdseg", "virtseg"

    };
    switch (data->type)
    {
    case DT_NONE:
        break;
    case DT_SEG:
        nl();
        oprintf(icdFile, "segment %s", segs[data->i].c_str());
        nl();
        break;
    case DT_SEGEXIT:
        nl();
        oprintf(icdFile, "segment end %s", segs[data->i].c_str());
        nl();
        break;
    case DT_DEFINITION:
        nl();
        if (data->symbol.i & BaseData::DF_GLOBAL)
        {
            oprintf(icdFile, "\nglobal %s", data->symbol.sym->outputName);
            nl();
        }
        if (data->symbol.i & BaseData::DF_EXPORT)
        {
            oprintf(icdFile, "\nexport %s", data->symbol.sym->outputName);
            nl();
        }
        oprintf(icdFile, "%s:", data->symbol.sym->outputName);
        nl();
        break;
    case DT_LABELDEFINITION:
        nl();
        oprintf(icdFile, "L_%d:", data->i);
        nl();
        break;
    case DT_RESERVE:
        oprintf(icdFile, "\treserve %d", data->i);
        nl();
        break;
    case DT_SYM:
        oprintf(icdFile, "\tDC.A %s", data->symbol.sym->outputName);
        nl();
        break;
    case DT_SRREF:
        oprintf(icdFile, "\tDC.A\t%s,%d", data->symbol.sym->outputName, data->symbol.i);
        nl();
        break;
    case DT_PCREF:
        oprintf(icdFile, "\tDC.A %s", data->symbol.sym->outputName);
        nl();
        break;
    case DT_FUNCREF:
        if (data->symbol.i & BaseData::DF_GLOBAL)
        {
            oprintf(icdFile, "\nglobal %s", data->symbol.sym->outputName);
            nl();
        }
        if (data->symbol.i & BaseData::DF_EXPORT)
        {
            oprintf(icdFile, "\nexport %s", data->symbol.sym->outputName);
            nl();
        }
        break;
    case DT_LABEL:
        oprintf(icdFile, "\tDC.A L_%d", data->i);
        nl();
        break;
    case DT_LABDIFFREF:
        oprintf(icdFile, "\tDC.D L_%d-L_%d", data->diff.l1, data->diff.l2);
        nl();
        break;
    case DT_STRING:
    {
        bool instring = false;
        for (int i = 0; i < data->astring.i; i++)
        {
            if (data->astring.str[i] >= ' '&& data->astring.str[i] < 127)
            {
                if (!instring)
                {
                    instring = true;
                    nl();
                    oprintf(icdFile, "\tDC.B \"");
                }
                oputc(data->astring.str[i], icdFile);
            }
            else {
                if (instring)
                {
                    instring = false;
                    oputc('"', icdFile);
                    nl();
                }
                oprintf(icdFile, "\tDC.B 0x%x", data->astring.str[i]);
            }
        }
    }
    break;
    case DT_BIT:
        break;
    case DT_BOOL:
        oprintf(icdFile, "\tDC.BOOL 0x%x", data->i);
        nl();
        break;
    case DT_BYTE:
        oprintf(icdFile, "\tDC.B 0x%x", data->i);
        nl();
        break;
    case DT_USHORT:
        oprintf(icdFile, "\tDC.S 0x%x", data->i);
        nl();
        break;
    case DT_UINT:
        oprintf(icdFile, "\tDC.I 0x%x", data->i);
        nl();
        break;
    case DT_ULONG:
        oprintf(icdFile, "\tDC.L 0x%x", data->i);
        nl();
        break;
    case DT_ULONGLONG:
        oprintf(icdFile, "\tDC.LL 0x%x", data->i);
        nl();
        break;
    case DT_16:
        oprintf(icdFile, "\tDC.16 0x%x", data->i);
        nl();
        break;
    case DT_32:
        oprintf(icdFile, "\tDC.32 0x%x", data->i);
        nl();
        break;
    case DT_ENUM:
        oprintf(icdFile, "\tDC.ENUM 0x%x", data->i);
        nl();
        break;
    case DT_FLOAT:
        PutFloat(".F", data->f);
        break;
    case DT_DOUBLE:
        PutFloat(".D", data->f);
        break;
    case DT_LDOUBLE:
        PutFloat(".LD", data->f);
        break;
    case DT_CFLOAT:
        PutComplex(".CF", data->c.r, data->c.i);
        break;
    case DT_CDOUBLE:
        PutComplex(".CD", data->c.r, data->c.i);
        break;
    case DT_CLONGDOUBLE:
        PutComplex(".CLD", data->c.r, data->c.i);
        break;
    case DT_ADDRESS:
        oprintf(icdFile, "\tDC.A 0x%x", data->i);
        nl();
        break;
    case DT_VIRTUAL:
        nl();
        oprintf(icdFile, "\tvirtual %s", data->symbol.sym->outputName);
        virtualMode = data->symbol.i;
        nl();
        break;
    case DT_ENDVIRTUAL:
        oprintf(icdFile, "\tvirtual end %s", data->symbol.sym->outputName);
        if (virtualMode)
            dseg();
        else
            cseg();
        nl();
        break;
    case DT_ALIGN:
        nl();
        oprintf(icdFile, "\t align %d", data->i);
        nl();
        break;
    case DT_VTT:
        oprintf(icdFile, "\t[this] = [this] - %d\n", data->symbol.i);
        oprintf(icdFile, "\tGOTO\t%s:PC", data->symbol.sym->outputName);
        break;
    case DT_IMPORTTHUNK:
        oprintf(icdFile, "\tGOTO [%s]\n", data->symbol.sym->name);
        break;
    case DT_VC1:
        oprintf(icdFile, "\tGOTO [[this] + %d]\n", data->symbol.i);
        break;

    }
}
const char* lookupRegName(int regnum)
{
    if (regnum < chosenAssembler->arch->registerCount)
        return chosenAssembler->arch->regNames[regnum].name;
    return "???";
}

void OutputIcdFile()
{
    for (auto d : baseData)
    {
        if (d->type == DT_FUNC)
        {
            PutFunc(d);
        }
        else
        {
            PutData(d);
        }
    }
    for (auto e : externals)
    {
        if (e)
            oprintf(icdFile, "\textern %s\n", e->outputName);

    }
}
