/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2011, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, 
    with or without modification, are permitted provided that the following 
    conditions are met:
    
    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the
      following disclaimer.
    
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.
    
    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifdef TEST
#define LLONG_TYPE long long
#include "floating.h"
int BigEndian = 0;
#else
#include "compiler.h"
extern ARCH_ASM *chosenAssembler;
#define BigEndian chosenAssembler->arch->big_endian
#endif

#include "math.h"

/*
** emfloat.c
** BYTEmark (tm)
** BYTE's Native Mode Benchmarks
** Rick Grehan, BYTE Magazine.
*/

/***********************
** SetFPFZero **
************************
** Set an internal floating-point-format number to zero.
** sign determines the sign of the zero.
*/
void SetFPFZero(FPF *dest,
                        uchar sign)
{
int i;          /* Index */

dest->type=IFPF_IS_ZERO;
dest->sign=sign;
dest->exp=MIN_EXP;
for(i=0;i<INTERNAL_FPF_PRECISION;i++)
        dest->mantissa[i]=0;
return;
}

/***************************
** SetFPFInfinity **
****************************
** Set an internal floating-point-format number to infinity.
** This can happen if the exponent exceeds MAX_EXP.
** As above, sign picks the sign of infinity.
*/
void SetFPFInfinity(FPF *dest,
                        uchar sign)
{
int i;          /* Index */

dest->type=IFPF_IS_INFINITY;
dest->sign=sign;
dest->exp=MIN_EXP;
for(i=0;i<INTERNAL_FPF_PRECISION;i++)
        dest->mantissa[i]=0;
return;
}

/**********************
** SetFPFNaN **
***********************
** Set an internal floating-point-format number to Nan
** (not a number).  Note that we "emulate" an 80x87 as far
** as the mantissa bits go.
*/
void SetFPFNaN(FPF *dest)
{
int i;          /* Index */

dest->type=IFPF_IS_NAN;
dest->exp=MAX_EXP;
dest->sign=1;
dest->mantissa[0]=0x4000;
for(i=1;i<INTERNAL_FPF_PRECISION;i++)
        dest->mantissa[i]=0;

return;
}

int ValueIsOne(FPF *value)
{
    if (value->type != IFPF_IS_NORMAL)
        return 0;
    if (value->exp != 1)
        return 0;
    if (value->sign)
        return 0;
    return IsMantissaOne(value->mantissa);
}
int FPFEQ(FPF *left, FPF *right)
{
    if (left->type != right->type)
        return 0;
    if (left->sign != right->sign)
        return 0;
    if (left->type == IFPF_IS_INFINITY || left->type == IFPF_IS_ZERO)
        return 1;
    if (left->type == IFPF_IS_NAN)
        return 0;
    if (left->exp != right->exp)
        return 0;
    return !memcmp(left->mantissa, right->mantissa, sizeof(right->mantissa));
}
int FPFGT(FPF *left, FPF *right)
{
    if (left->type == IFPF_IS_NAN || right->type == IFPF_IS_NAN)
        return 0;
    if (left->sign && !right->sign)
        return 0;
    if (!left->sign && right->sign)
        return 1;
    if (right->type == IFPF_IS_INFINITY && left->type == IFPF_IS_INFINITY)
        return 0;
    if (left->sign) {
        if (right->type == IFPF_IS_INFINITY)
            return 1;
        if (left->exp < right->exp)
            return 1;
        if (left->exp > right->exp)
            return 0;
        return (memcmp(left->mantissa, right->mantissa, sizeof(left->mantissa)) < 0);
    }
    if (left->type == IFPF_IS_INFINITY)
        return 1;
    if (left->exp > right->exp)
        return 1;
    if (left->exp < right->exp)
        return 0;
    return (memcmp(left->mantissa, right->mantissa, sizeof(left->mantissa)) > 0);
}
int FPFGTE(FPF *left, FPF *right)
{
    return FPFGT(left,right) || FPFEQ(left,right);
}
/*******************
** IsMantissaZero **
********************
** Pass this routine a pointer to an internal floating point format
** number's mantissa.  It checks for an all-zero mantissa.
** Returns 0 if it is NOT all zeros, !=0 otherwise.
*/
int IsMantissaZero(u16 *mant)
{
int i;          /* Index */
int n;          /* Return value */

n=0;
for(i=0;i<INTERNAL_FPF_PRECISION;i++)
        n|=mant[i];

return(!n);
}
int IsMantissaOne(u16 *mant)
{
    int i;
    if (mant[0] != 0x8000)
        return 0;
    for (i=1; i < INTERNAL_FPF_PRECISION; i++)
        if (mant[i])
            return 0;
    return 1;
}

/**************
** Add16Bits **
***************
** Add b, c, and carry.  Retult in a.  New carry in carry.
*/
void Add16Bits(u16 *carry,
                u16 *a,
                u16 b,
                u16 c)
{
u32 accum;              /* Accumulator */

/*
** Do the work in the 32-bit accumulator so we can return
** the carry.
*/
accum=(u32)b;
accum+=(u32)c;
accum+=(u32)*carry;
*carry=(u16)((accum & 0x00010000) ? 1 : 0);     /* New carry */
*a=(u16)(accum & 0xFFFF);       /* Result is lo 16 bits */
return;
}

/**************
** Sub16Bits **
***************
** Additive inverse of above.
*/
void Sub16Bits(u16 *borrow,
                u16 *a,
                u16 b,
                u16 c)
{
u32 accum;              /* Accumulator */

accum=(u32)b;
accum-=(u32)c;
accum-=(u32)*borrow;
*borrow=(u32)((accum & 0x00010000) ? 1 : 0);    /* New borrow */
*a=(u16)(accum & 0xFFFF);
return;
}

/*******************
** ShiftMantLeft1 **
********************
** Shift a vector of 16-bit numbers left 1 bit.  Also provides
** a carry bit, which is shifted in at the beginning, and
** shifted out at the end.
*/
void ShiftMantLeft1(u16 *carry,
                        u16 *mantissa)
{
int i;          /* Index */
int new_carry;
u16 accum;      /* Temporary holding placed */

for(i=INTERNAL_FPF_PRECISION-1;i>=0;i--)
{       accum=mantissa[i];
        new_carry=accum & 0x8000;       /* Get new carry */
        accum=accum<<1;                 /* Do the shift */
        if(*carry)
                accum|=1;               /* Insert previous carry */
        *carry=new_carry;
        mantissa[i]=accum;              /* Return shifted value */
}
return;
}

/********************
** ShiftMantRight1 **
*********************
** Shift a mantissa right by 1 bit.  Provides carry, as
** above
*/
void ShiftMantRight1(u16 *carry,
                        u16 *mantissa)
{
int i;          /* Index */
int new_carry;
u16 accum;

for(i=0;i<INTERNAL_FPF_PRECISION;i++)
{       accum=mantissa[i];
        new_carry=accum & 1;            /* Get new carry */
        accum=accum>>1;
        if(*carry)
                accum|=0x8000;
        *carry=new_carry;
        mantissa[i]=accum;
}
return;
}


/*****************************
** StickyShiftMantRight **
******************************
** This is a shift right of the mantissa with a "sticky bit".
** I.E., if a carry of 1 is shifted out of the least significant
** bit, the least significant bit is set to 1.
*/
void StickyShiftRightMant(FPF *ptr,
                        int amount)
{
int i;          /* Index */
u16 carry;      /* Self-explanatory */
u16 *mantissa;

mantissa=ptr->mantissa;

if(ptr->type!=IFPF_IS_ZERO)     /* Don't bother shifting a zero */
{
        /*
        ** If the amount of shifting will shift everyting
        ** out of existence, then just clear the whole mantissa
        ** and set the lowmost bit to 1.
        */
        if(amount>=INTERNAL_FPF_PRECISION * 16)
        {
                for(i=0;i<INTERNAL_FPF_PRECISION-1;i++)
                        mantissa[i]=0;
                mantissa[INTERNAL_FPF_PRECISION-1]=1;
        }
        else
                for(i=0;i<amount;i++)
                {
                        carry=0;
                        ShiftMantRight1(&carry,mantissa);
                        if(carry)
                                mantissa[INTERNAL_FPF_PRECISION-1] |= 1;
                }
}
return;
}


/**************************************************
**         POST ARITHMETIC PROCESSING            **
**  (NORMALIZE, ROUND, OVERFLOW, AND UNDERFLOW)  **
**************************************************/

/**************
** normalize **
***************
** Normalize an internal-representation number.  Normalization
** discards empty most-significant bits.
*/
void normalize(FPF *ptr)
{
u16     carry;

/*
** As long as there's a highmost 0 bit, shift the significand
** left 1 bit.  Each time you do this, though, you've
** gotta decrement the exponent.
*/
while ((ptr->mantissa[0] & 0x8000) == 0)
{
        carry = 0;
        ShiftMantLeft1(&carry, ptr->mantissa);
        ptr->exp--;
}
return;
}

/****************
** denormalize **
*****************
** Denormalize an internal-representation number.  This means
** shifting it right until its exponent is equivalent to
** minimum_exponent. (You have to do this often in order
** to perform additions and subtractions).
*/
void denormalize(FPF *ptr,
                int minimum_exponent)
{
long exponent_difference;

exponent_difference = ptr->exp-minimum_exponent;
if (exponent_difference < 0)
{
        /* 
        ** The number is subnormal
        */
        exponent_difference = -exponent_difference;
        if (exponent_difference >= (INTERNAL_FPF_PRECISION * 16))
        {
                /* Underflow */
                SetFPFZero(ptr, ptr->sign);
        }
        else
        {
                ptr->exp+=exponent_difference;
                StickyShiftRightMant(ptr, exponent_difference);
        }
}
return;
}


/*********************
** RoundFPF **
**********************
** Round an internal-representation number.
** The kind of rounding we do here is simplest...referred to as
** "chop".  "Extraneous" rightmost bits are simply hacked off.
*/
void RoundFPF(FPF *ptr)
{
/* int i; */

if (ptr->type == IFPF_IS_NORMAL ||
        ptr->type == IFPF_IS_SUBNORMAL)
{
        denormalize(ptr, MIN_EXP);
        if (ptr->type != IFPF_IS_ZERO)
        {
        
                /* clear the extraneous bits */
                ptr->mantissa[INTERNAL_FPF_PRECISION-1] &= 0xfff8;
/*              for (i=4; i<INTERNAL_FPF_PRECISION; i++)
                {
                        ptr->mantissa[i] = 0;
                }
*/
                /*
                ** Check for overflow
                */
                if (ptr->exp > MAX_EXP)
                {
                        SetFPFInfinity(ptr, ptr->sign);
                }
        }
}
return;
}

/*******************************************************
**  ARITHMETIC OPERATIONS ON INTERNAL REPRESENTATION  **
*******************************************************/

/***************
** choose_nan **
****************
** Called by routines that are forced to perform math on
** a pair of NaN's.  This routine "selects" which NaN is
** to be returned.
*/
void choose_nan(FPF *x,
                FPF *y,
                FPF *z,
                int intel_flag)
{
int i;

/*
** Compare the two mantissas,
** return the larger.  Note that we will be emulating
** an 80387 in this operation.
*/
for (i=0; i<INTERNAL_FPF_PRECISION; i++)
{
        if (x->mantissa[i] > y->mantissa[i])
        {
                memcpy((void *)z,(void *)x,sizeof(FPF));
                return;
        }
        if (x->mantissa[i] < y->mantissa[i])
        {
                memcpy((void *)z,(void *)y,sizeof(FPF));
                return;
        }
}

/* 
** They are equal
*/
if (!intel_flag)
        /* if the operation is addition */
        memcpy((void *)z,(void *)x,sizeof(FPF));
else
        /* if the operation is multiplication */
        memcpy((void *)z,(void *)y,sizeof(FPF));
return;
}


/**********************
** AddSubFPF **
***********************
** Adding or subtracting internal-representation numbers.
** -representation numbers pointed to by x and y are
** added/subtracted and the result returned in z.
*/
void AddSubFPF(uchar operation,
                FPF *x,
                FPF *y,
                FPF *z)
{
int exponent_difference;
u16 borrow;
u16 carry;
int i;
FPF locx,locy;  /* Needed since we alter them */

/*
** Following big switch statement handles the
** various combinations of operand types.
*/
switch ((x->type * IFPF_TYPE_COUNT) + y->type)
{
case ZERO_ZERO:
        memcpy((void *)z,(void *)x,sizeof(FPF));
        if (x->sign ^ y->sign ^ operation)
        {
                z->sign = 0; /* positive */
        }
        break;

case NAN_ZERO:
case NAN_SUBNORMAL:
case NAN_NORMAL:
case NAN_INFINITY:
case SUBNORMAL_ZERO:
case NORMAL_ZERO:
case INFINITY_ZERO:
case INFINITY_SUBNORMAL:
case INFINITY_NORMAL:
        memcpy((void *)z,(void *)x,sizeof(FPF));
        break;


case ZERO_NAN:
case SUBNORMAL_NAN:
case NORMAL_NAN:
case INFINITY_NAN:
        memcpy((void *)z,(void *)y,sizeof(FPF));
        break;

case ZERO_SUBNORMAL:
case ZERO_NORMAL:
case ZERO_INFINITY:
case SUBNORMAL_INFINITY:
case NORMAL_INFINITY:
        memcpy((void *)z,(void *)y,sizeof(FPF));
        z->sign ^= operation;
        break;

case SUBNORMAL_SUBNORMAL:
case SUBNORMAL_NORMAL:
case NORMAL_SUBNORMAL:
case NORMAL_NORMAL:
        /*
        ** Copy x and y to locals, since we may have
        ** to alter them.
        */
        memcpy((void *)&locx,(void *)x,sizeof(FPF));
        memcpy((void *)&locy,(void *)y,sizeof(FPF));

        /* compute sum/difference */
        exponent_difference = locx.exp-locy.exp;
        if (exponent_difference == 0)
        {
                /* 
                ** locx.exp == locy.exp
                ** so, no shifting required
                */
                if (locx.type == IFPF_IS_SUBNORMAL ||
                  locy.type == IFPF_IS_SUBNORMAL)
                        z->type = IFPF_IS_SUBNORMAL;
                else
                        z->type = IFPF_IS_NORMAL;

                /* 
                ** Assume that locx.mantissa > locy.mantissa
                */
                z->sign = locx.sign;
                z->exp= locx.exp;
        }
        else
                if (exponent_difference > 0)
                {
                        /*
                        ** locx.exp > locy.exp
                        */
                        StickyShiftRightMant(&locy,
                                 exponent_difference);
                        z->type = locx.type;
                        z->sign = locx.sign;
                        z->exp = locx.exp;
                }
                else    /* if (exponent_difference < 0) */
                {
                        /*
                        ** locx.exp < locy.exp
                        */
                        StickyShiftRightMant(&locx,
                                -exponent_difference);
                        z->type = locy.type;
                        z->sign = locy.sign ^ operation;
                        z->exp = locy.exp;
                }

                if (locx.sign ^ locy.sign ^ operation)
                {
                        /* 
                        ** Signs are different, subtract mantissas
                        */
                        borrow = 0;
                        for (i=(INTERNAL_FPF_PRECISION-1); i>=0; i--)
                                Sub16Bits(&borrow,
                                        &z->mantissa[i],
                                        locx.mantissa[i],
                                        locy.mantissa[i]);

                        if (borrow)
                        {
                                /* The y->mantissa was larger than the
                                ** x->mantissa leaving a negative
                                ** result.  Change the result back to
                                ** an unsigned number and flip the
                                ** sign flag.
                                */
                                z->sign = locy.sign ^ operation;
                                borrow = 0;
                                for (i=(INTERNAL_FPF_PRECISION-1); i>=0; i--)
                                {
                                        Sub16Bits(&borrow,
                                                &z->mantissa[i],
                                                0,
                                                z->mantissa[i]);
                                }
                        }
                        else
                        {
                                /* The assumption made above
                                ** (i.e. x->mantissa >= y->mantissa)
                                ** was correct.  Therefore, do nothing.
                                ** z->sign = x->sign;
                                */
                        }

                        if (IsMantissaZero(z->mantissa))
                        {
                                z->type = IFPF_IS_ZERO;
                                z->sign = 0; /* positive */
                        }
                        else
                                if (locx.type == IFPF_IS_NORMAL ||
                                         locy.type == IFPF_IS_NORMAL)
                                {
                                        normalize(z);
                                }
                }
                else
                {
                        /* signs are the same, add mantissas */
                        carry = 0;
                        for (i=(INTERNAL_FPF_PRECISION-1); i>=0; i--)
                        {
                                Add16Bits(&carry,
                                        &z->mantissa[i],
                                        locx.mantissa[i],
                                        locy.mantissa[i]);
                        }

                        if (carry)
                        {
                                z->exp++;
                                carry=0;
                                ShiftMantRight1(&carry,z->mantissa);
                                z->mantissa[0] |= 0x8000;
                                z->type = IFPF_IS_NORMAL;
                        }
                        else
                                if (z->mantissa[0] & 0x8000)
                                        z->type = IFPF_IS_NORMAL;
        }
        break;

case INFINITY_INFINITY:
        SetFPFNaN(z);
        break;

case NAN_NAN:
        choose_nan(x, y, z, 1);
        break;
}

/*
** All the math is done; time to round.
*/
RoundFPF(z);
return;
}


/************************
** MultiplyFPF **
*************************
** Two internal-representation numbers x and y are multiplied; the
** result is returned in z.
*/
void MultiplyFPF(FPF *x,
                        FPF *y,
                        FPF *z)
{
int i;
int j;
u16 carry;
u16 extra_bits[INTERNAL_FPF_PRECISION];
FPF locy;       /* Needed since this will be altered */
/*
** As in the preceding function, this large switch
** statement selects among the many combinations
** of operands.
*/
switch ((x->type * IFPF_TYPE_COUNT) + y->type)
{
case INFINITY_SUBNORMAL:
case INFINITY_NORMAL:
case INFINITY_INFINITY:
case ZERO_ZERO:
case ZERO_SUBNORMAL:
case ZERO_NORMAL:
        memcpy((void *)z,(void *)x,sizeof(FPF));
        z->sign ^= y->sign;
        break;

case SUBNORMAL_INFINITY:
case NORMAL_INFINITY:
case SUBNORMAL_ZERO:
case NORMAL_ZERO:
        memcpy((void *)z,(void *)y,sizeof(FPF));
        z->sign ^= x->sign;
        break;

case ZERO_INFINITY:
case INFINITY_ZERO:
        SetFPFNaN(z);
        break;

case NAN_ZERO:
case NAN_SUBNORMAL:
case NAN_NORMAL:
case NAN_INFINITY:
        memcpy((void *)z,(void *)x,sizeof(FPF));
        break;

case ZERO_NAN:
case SUBNORMAL_NAN:
case NORMAL_NAN:
case INFINITY_NAN:
        memcpy((void *)z,(void *)y,sizeof(FPF));
        break;


case SUBNORMAL_SUBNORMAL:
case SUBNORMAL_NORMAL:
case NORMAL_SUBNORMAL:
case NORMAL_NORMAL:
        /*
        ** Make a local copy of the y number, since we will be
        ** altering it in the process of multiplying.
        */
        memcpy((void *)&locy,(void *)y,sizeof(FPF));

        /*
        ** Check for unnormal zero arguments
        */
        if (IsMantissaZero(x->mantissa) || IsMantissaZero(y->mantissa))
                SetFPFInfinity(z, 0);

        /*
        ** Initialize the result
        */
        if (x->type == IFPF_IS_SUBNORMAL ||
            y->type == IFPF_IS_SUBNORMAL)
                z->type = IFPF_IS_SUBNORMAL;
        else
                z->type = IFPF_IS_NORMAL;

        z->sign = x->sign ^ y->sign;
        z->exp = x->exp + y->exp ;
        for (i=0; i<INTERNAL_FPF_PRECISION; i++)
        {
                z->mantissa[i] = 0;
                extra_bits[i] = 0;
        }

        for (i=0; i<(INTERNAL_FPF_PRECISION*16); i++)
        {
                /*
                ** Get rightmost bit of the multiplier
                */
                carry = 0;
                ShiftMantRight1(&carry, locy.mantissa);
                if (carry)
                {
                        /* 
                        ** Add the multiplicand to the product
                        */
                        carry = 0;
                        for (j=(INTERNAL_FPF_PRECISION-1); j>=0; j--)
                                Add16Bits(&carry,
                                        &z->mantissa[j],
                                        z->mantissa[j],
                                        x->mantissa[j]);
                }
                else
                {
                        carry = 0;
                }

                /* 
                ** Shift the product right.  Overflow bits get
                ** shifted into extra_bits.  We'll use it later
                ** to help with the "sticky" bit.
                */
                ShiftMantRight1(&carry, z->mantissa);
                ShiftMantRight1(&carry, extra_bits);
        }

        /*
        ** Normalize
        ** Note that we use a "special" normalization routine
        ** because we need to use the extra bits. (These are
        ** bits that may have been shifted off the bottom that
        ** we want to reclaim...if we can.
        */
        while ((z->mantissa[0] & 0x8000) == 0)
        {
                carry = 0;
                ShiftMantLeft1(&carry, extra_bits);
                ShiftMantLeft1(&carry, z->mantissa);
                z->exp--;
        }

        /*
        ** Set the sticky bit if any bits set in extra bits.
        */
        if (IsMantissaZero(extra_bits))
        {
                z->mantissa[INTERNAL_FPF_PRECISION-1] |= 1;
        }
        break;

case NAN_NAN:
        choose_nan(x, y, z, 0);
        break;
}

/*
** All math done...do rounding.
*/
RoundFPF(z);
return;
}


/**********************
** DivideFPF **
***********************
** Divide internal FPF number x by y.  Return result in z.
*/
void DivideFPF(FPF *x, 
                        FPF *y, 
                        FPF *z)
{
int i;
int j;
u16 carry;
u16 extra_bits[INTERNAL_FPF_PRECISION];
FPF locx;       /* Local for x number */

/*
** As with preceding function, the following switch
** statement selects among the various possible
** operands.
*/
switch ((x->type * IFPF_TYPE_COUNT) + y->type)
{
case ZERO_ZERO:
case INFINITY_INFINITY:
        SetFPFNaN(z);
        break;

case ZERO_SUBNORMAL:
case ZERO_NORMAL:
        if (IsMantissaZero(y->mantissa))
        {
                SetFPFNaN(z);
                break;
        }

case ZERO_INFINITY:
case SUBNORMAL_INFINITY:
case NORMAL_INFINITY:
        SetFPFZero(z, x->sign ^ y->sign);
        break;

case SUBNORMAL_ZERO:
case NORMAL_ZERO:
        if (IsMantissaZero(x->mantissa))
        {
                SetFPFNaN(z);
                break;
        }

case INFINITY_ZERO:
case INFINITY_SUBNORMAL:
case INFINITY_NORMAL:
        SetFPFInfinity(z, 0);
        z->sign = x->sign ^ y->sign;
        break;

case NAN_ZERO:
case NAN_SUBNORMAL:
case NAN_NORMAL:
case NAN_INFINITY:
        memcpy((void *)z,(void *)x,sizeof(FPF));
        break;

case ZERO_NAN:
case SUBNORMAL_NAN:
case NORMAL_NAN:
case INFINITY_NAN:
        memcpy((void *)z,(void *)y,sizeof(FPF));
        break;

case SUBNORMAL_SUBNORMAL:
case NORMAL_SUBNORMAL:
case SUBNORMAL_NORMAL:
case NORMAL_NORMAL:
        /*
        ** Make local copy of x number, since we'll be
        ** altering it in the process of dividing.
        */
        memcpy((void *)&locx,(void *)x,sizeof(FPF));

        /* 
        ** Check for unnormal zero arguments
        */
        if (IsMantissaZero(locx.mantissa))
        {
                if (IsMantissaZero(y->mantissa))
                        SetFPFNaN(z);
                else
                        SetFPFZero(z, 0);
                break;
        }
        if (IsMantissaZero(y->mantissa))
        {
                SetFPFInfinity(z, 0);
                break;
        }

        /* 
        ** Initialize the result
        */
        z->type = x->type;
        z->sign = x->sign ^ y->sign;
        z->exp = x->exp - y->exp +
                        ((INTERNAL_FPF_PRECISION * 16 * 2));
        for (i=0; i<INTERNAL_FPF_PRECISION; i++)
        {
                z->mantissa[i] = 0;
                extra_bits[i] = 0;
        }

        while ((z->mantissa[0] & 0x8000) == 0)
        {
                carry = 0;
                ShiftMantLeft1(&carry, locx.mantissa);
                ShiftMantLeft1(&carry, extra_bits);

                /* 
                ** Time to subtract yet?
                */
                if (carry == 0)
                        for (j=0; j<INTERNAL_FPF_PRECISION; j++)
                        {
                                if (y->mantissa[j] > extra_bits[j])
                                {
                                        carry = 0;
                                        goto no_subtract;
                                }
                                if (y->mantissa[j] < extra_bits[j])
                                        break;
                        }
                /* 
                ** Divisor (y) <= dividend (x), subtract
                */
                carry = 0;
                for (j=(INTERNAL_FPF_PRECISION-1); j>=0; j--)
                        Sub16Bits(&carry,
                                &extra_bits[j],
                                extra_bits[j],
                                y->mantissa[j]);
                carry = 1;      /* 1 shifted into quotient */
        no_subtract:
                ShiftMantLeft1(&carry, z->mantissa);
                z->exp--;
        }
        break;

case NAN_NAN:
        choose_nan(x, y, z, 0);
        break;
}

/*
** Math complete...do rounding
*/
RoundFPF(z);
}
void LongLongToFPF(FPF *dest, LLONG_TYPE myllong)
{
int i;          /* Index */
u16 myword;     /* Used to hold converted stuff */
/*
** Save the sign and get the absolute value.  This will help us
** with 64-bit machines, since we use only the lower 32
** bits just in case.
*/
if(myllong<0L)
{       dest->sign=1;
        myllong=0-myllong;
}
else
        dest->sign=0;
/*
** Prepare the destination floating point number
*/
dest->type=IFPF_IS_NORMAL;
for(i=0;i<INTERNAL_FPF_PRECISION;i++)
        dest->mantissa[i]=0;

/*
** See if we've got a zero.  If so, make the resultant FP
** number a true zero and go home.
*/
if(myllong==0)
{       dest->type=IFPF_IS_ZERO;
        dest->exp=0;
        return;
}

/*
** Not a true zero.  Set the exponent to 64 (internal FPFs have
** no bias) and load the low and high words into their proper
** locations in the mantissa.  Then normalize.  The action of
** normalizing slides the mantissa bits into place and sets
** up the exponent properly.
*/
dest->exp=64;
#ifdef USE_LONGLONG
myword=(u16)((myllong >> 48) & 0xFFFFL);
dest->mantissa[0]=myword;
myword=(u16)((myllong >> 32) & 0xFFFFL);
dest->mantissa[1]=myword;
#endif
myword=(u16)((myllong >> 16) & 0xFFFFL);
dest->mantissa[2]=myword;
myword=(u16)(myllong & 0xFFFFL);
dest->mantissa[3]=myword;
normalize(dest);
return;
}
void UnsignedLongLongToFPF(FPF *dest, LLONG_TYPE myllong)
{
int i;          /* Index */
u16 myword;     /* Used to hold converted stuff */
        dest->sign=0;
/*
** Prepare the destination floating point number
*/
dest->type=IFPF_IS_NORMAL;
for(i=0;i<INTERNAL_FPF_PRECISION;i++)
        dest->mantissa[i]=0;

/*
** See if we've got a zero.  If so, make the resultant FP
** number a true zero and go home.
*/
if(myllong==0)
{       dest->type=IFPF_IS_ZERO;
        dest->exp=0;
        return;
}

/*
** Not a true zero.  Set the exponent to 64 (internal FPFs have
** no bias) and load the low and high words into their proper
** locations in the mantissa.  Then normalize.  The action of
** normalizing slides the mantissa bits into place and sets
** up the exponent properly.
*/
dest->exp=64;
#ifdef USE_LONGLONG
myword=(u16)((myllong >> 48) & 0xFFFFL);
dest->mantissa[0]=myword;
myword=(u16)((myllong >> 32) & 0xFFFFL);
dest->mantissa[1]=myword;
#endif
myword=(u16)((myllong >> 16) & 0xFFFFL);
dest->mantissa[2]=myword;
myword=(u16)(myllong & 0xFFFFL);
dest->mantissa[3]=myword;
normalize(dest);
return;
}
/* converts the exponent to base ten, doing truncation rounding 
 * we are using real floating point here but not depending on the format
 */
#define LB2_10 (M_LN10 / M_LN2)
int FPFTensExponent(FPF *value)
{
    return (int)((float)value->exp/LB2_10);
}
/* multiply by a power of ten */
void FPFMultiplyPowTen(FPF *value, int power)
{
    FPF temp,mul ;
    int i;
    temp.sign = 0;
 /* 10^x = 5^x * 2^x*/
    if (value->type == IFPF_IS_ZERO || value->type == IFPF_IS_NAN || value->type == IFPF_IS_INFINITY)
        return;
    value->exp += power ;
    if (power < 0) { /* constant 0.2 */
        for (i=0; i < INTERNAL_FPF_PRECISION; i++)
            temp.mantissa[i] = 0xCCCC;
        power = - power;
        temp.exp = -2 ;
        temp.type = IFPF_IS_NORMAL;
    } else if (power > 0) { /* constant 5 */
        temp.mantissa[0] = 0xa000;
        for (i=1; i < INTERNAL_FPF_PRECISION; i++)
            temp.mantissa[i] = 0;
        temp.exp = 3;
        temp.type = IFPF_IS_NORMAL;
    } else { /* multiply by 10^0 is a nop */
        return ;
    }
    mul = temp;
    while (power) {
        FPF internal;
        if (power & 1) { 
            MultiplyFPF(value, &mul, &internal);
            *value = internal;
        }
        MultiplyFPF (&mul, &mul, &internal);
        mul = internal;
        power >>= 1 ;
    }
    RoundFPF(value);
}
/************************
** FPFToString **
*************************
** FOR DEBUG PURPOSES
** This routine converts an internal floating point representation
** number to a string.  Used in debugging the package.
** Returns length of converted number.
** NOTE: dest must point to a buffer big enough to hold the
**  result.  Also, this routine does append a null (an effect
**  of using the sprintf() function).  It also returns
**  a length count.
** NOTE: This routine returns 5 significant digits.  Thats
**  about all I feel safe with, given the method of
**  conversion.  It should be more than enough for programmers
**  to determine whether the package is properly ported.
*/
char * FPFToString(char *dest,
                FPF *src)
{
    char *old = dest;
    if (src->type == IFPF_IS_NAN)
    {
        if (src->sign)
            *dest++ = '-';
        strcpy(dest, "nan");
    }
    else if (src->type == IFPF_IS_INFINITY)
    {
        if (src->sign)
            *dest++ = '-';
        strcpy(dest, "inf");
    }
    else
    {
        u16 mantissa[INTERNAL_FPF_PRECISION];
        FPF temp = *src;
        int power = FPFTensExponent(&temp);
        u16 carry;
        int val,val1,i,j;
        if (src->type == IFPF_IS_ZERO)
        {
            strcpy(dest, "0.0");
            return dest;
        }
        FPFMultiplyPowTen(&temp,-power);
        val = 0;
        if (temp.sign)
            *dest++ = '-';
        if (temp.exp > 0) {
            while (temp.exp--) {
                carry = 0;
                ShiftMantLeft1(&carry,temp.mantissa);
                val <<= 1;
                val |= !!carry;
            }
            *dest++ = val + '0';
            *dest++ = '.' ;
        }
        else {
            *dest++ = '0';
            *dest++ = '.';
            while (temp.exp++) {
                carry = 0;
                ShiftMantRight1(&carry, temp.mantissa);
            }
        }    
        for (i=0; i < 18; i++) {
            carry = 0;
            val = 0;
            ShiftMantLeft1(&carry,temp.mantissa);
            val <<= 1;
            val |= !!carry;
            val1 = val ;
            memcpy(mantissa,temp.mantissa, INTERNAL_FPF_PRECISION * sizeof(u16));
            carry = 0;
            ShiftMantLeft1(&carry,temp.mantissa);
            val <<= 1;
            val |= !!carry;
            carry = 0;
            ShiftMantLeft1(&carry,temp.mantissa);
            val <<= 1;
            val |= !!carry;
            val += val1 ;
            carry = 0;
            for (j= INTERNAL_FPF_PRECISION-1; j >=0; j--) {
                Add16Bits(&carry, temp.mantissa + j, mantissa[j], temp.mantissa[j]);
            }
            val += !!carry;
            *dest++ = '0' + val;
        }
        if (power) {
           *dest++ = 'E';
            if (power < 0) {
                power = - power;
                *dest++ = '-';
            } else
                *dest++ = '+';
            sprintf(dest,"%d",power);
        } else
            *dest = 0 ;
    }
    return old;
}

LLONG_TYPE FPFToLongLong(FPF *src)
{
    FPF stemp = *src;
    int exp = stemp.exp;
    LLONG_TYPE temp;
    u16 tmant[INTERNAL_FPF_PRECISION];
    int i;
    if (stemp.type == IFPF_IS_ZERO)
        return 0;
    switch(stemp.type) {
        case IFPF_IS_INFINITY:
        case IFPF_IS_NAN:
#ifdef USE_LONGLONG
        if (stemp.sign)
            return LLONG_MIN;
        else
            return LLONG_MAX;
#else
        if (stemp.sign)
            return LONG_MIN;
        else
            return LONG_MAX;
#endif
        case IFPF_IS_ZERO:
        case IFPF_IS_SUBNORMAL:
            return 0;
        case IFPF_IS_NORMAL:
        memcpy(tmant,stemp.mantissa,sizeof(tmant));
#ifdef USE_LONGLONG
        if (stemp.exp > 63)
            if (stemp.sign)
                return LLONG_MIN;
            else
                return LLONG_MAX;
        if (stemp.exp < 0)
            return 0;
        while (stemp.exp++ != 64) {
            u16 carry= 0;
            ShiftMantRight1(&carry, tmant);
        }
        temp = 0;
        for (i=0 ; i < 4; i++) {
            temp = temp << 16;
            temp |= tmant[i];
        }
#else
        if (stemp.exp > 31)
            if (stemp.sign)
                return LONG_MIN;
            else
                return LONG_MAX;
        if (stemp.exp < 0)
            return 0;
        while (exp++ != 32) {
            u16 carry= 0;
            ShiftMantRight1(&carry, tmant);
        }
        temp = 0;
        for (i=0 ; i < 2; i++) {
            temp = temp << 16;
            temp |= tmant[i];
        }
#endif            
        if (stemp.sign)
            temp = - temp;
        return temp;
        
    }
    return 0;
}
int FPFToFloat(unsigned char *dest, FPF *src)
{
    u32 val ;
    if (src->type == IFPF_IS_ZERO)
        val = 0 ;
    else 
    {
        if (src->type == IFPF_IS_INFINITY)
            val = 0x7f800000;
        else if (src->type == IFPF_IS_NAN)
            val = 0x7fc00000;
        else {
            if (src->exp <= -126)
            {
                val = (((src->mantissa[0]) << 7) + (src->mantissa[1] >> 9)) >> (-126 - src->exp) ;
            }
            else
            {
                val = ((src->mantissa[0] & 0x7fff) << 8) + (src->mantissa[1] >> 8) ;
                val |= (src->exp + 126) << 23;
            }
            if (src->exp > 129)
            {
                diag("FPFToFloat: invalid exponent");
            }
        }
    }
    if (src->sign)
        val |= 0x80000000L;
    if (BigEndian) {
        dest[0] = val >> 24;
        dest[1] = (val >> 16) & 0xff ;
        dest[2] = (val >> 8) & 0xff ;
        dest[3] = (val >> 0) & 0xff ;
    } else {
        dest[3] = val >> 24;
        dest[2] = (val >> 16) & 0xff ;
        dest[1] = (val >> 8) & 0xff ;
        dest[0] = (val >> 0) & 0xff ;
    }
    return 1;
}
int FPFToDouble(unsigned char *dest, FPF *src)
{
    ULLONG_TYPE val;
    if (src->type == IFPF_IS_ZERO)
        val = 0;
    else 
    {
        if (src->type == IFPF_IS_INFINITY)
            val = 0x7ff0000000000000i64;
        else if (src->type == IFPF_IS_NAN)
            val = 0x7ff8000000000000i64;
        else {
            if (src->exp <= -1022)
            {
                val = (unsigned)((src->mantissa[0] << 16) + src->mantissa[1]) ;
                val <<= 20;
                val |= (src->mantissa[2] << 4) + (src->mantissa[3] >> 12) ;
                val >>= -1022 - src->exp;
            }
            else
            {
                val = (src->exp + 1022);
                val <<= 31;
                val |= ((src->mantissa[0] & 0x7fff) << 16) + src->mantissa[1]  ;
                val <<= 21;
                val |= (src->mantissa[2] << 5) + (src->mantissa[3] >> 11) ;
            }
            if (src->exp > 1025)
            {
                diag("FPFToDouble: invalid exponent");
            }
        }
    }
    if (src->sign)
        val |= 0x8000000000000000i64;
    if (BigEndian) {
        dest[0] = val >> 56;
        dest[1] = (val >> 48) & 0xff ;
        dest[2] = (val >> 40) & 0xff ;
        dest[3] = (val >> 32) & 0xff ;
        dest[4] = (val >> 24) & 0xff;
        dest[5] = (val >> 16) & 0xff ;
        dest[6] = (val >> 8) & 0xff ;
        dest[7] = (val >> 0) & 0xff ;
    } else {
        dest[7] = val >> 56;
        dest[6] = (val >> 48) & 0xff ;
        dest[5] = (val >> 40) & 0xff ;
        dest[4] = (val >> 32) & 0xff ;
        dest[3] = (val >> 24) & 0xff;
        dest[2] = (val >> 16) & 0xff ;
        dest[1] = (val >> 8) & 0xff ;
        dest[0] = (val >> 0) & 0xff ;
    }
    return 1;
}
int FPFToLongDouble(unsigned char *dest, FPF *src)
{
    int exp;
    ULLONG_TYPE val;
    /* have to or in the high bit in case infinity or nan*/
    if (src->type == IFPF_IS_ZERO)
        exp = val = 0;
    else 
    {
        if (src->type == IFPF_IS_INFINITY)
            exp = 0x7fff, val = 0x8000000000000000i64;
        else if (src->type == IFPF_IS_NAN)
        {
            exp = 0x7fff;
            val = 0xc000000000000000i64;
        }
        else {
            exp = 0;
            val = (unsigned)((src->mantissa[0] << 16) + src->mantissa[1]) ;
            val <<= 32;
            val |= (unsigned)((src->mantissa[2] << 16) + src->mantissa[3]) ;
            if (src->exp > 16385)
                diag("FPFToLongDouble: invalid exponent");
            else if (src->exp <= - 16382)
                val >>= - 16382 - src->exp;
            else
                exp = src->exp + 16382;
        }
    }
    if (src->sign)
        exp |= 0x8000L;
        
    if (BigEndian) {
        dest[0] = exp >> 8;
        dest[1] = exp & 0xff;
        dest[2] = val >> 56;
        dest[3] = (val >> 48) & 0xff ;
        dest[4] = (val >> 40) & 0xff ;
        dest[5] = (val >> 32) & 0xff ;
        dest[6] = (val >> 24) & 0xff;
        dest[7] = (val >> 16) & 0xff ;
        dest[8] = (val >> 8) & 0xff ;
        dest[9] = (val >> 0) & 0xff ;
    } else {
        dest[9] = exp >> 8;
        dest[8] = exp & 0xff;
        dest[7] = val >> 56;
        dest[6] = (val >> 48) & 0xff ;
        dest[5] = (val >> 40) & 0xff ;
        dest[4] = (val >> 32) & 0xff ;
        dest[3] = (val >> 24) & 0xff;
        dest[2] = (val >> 16) & 0xff ;
        dest[1] = (val >> 8) & 0xff ;
        dest[0] = (val >> 0) & 0xff ;
    }
    return 1;
}
void FPFTruncate(FPF *value, int bits, int maxexp, int minexp)
{
    switch(value->type) {
        case IFPF_IS_NAN:
        case IFPF_IS_INFINITY:
            return;
        case IFPF_IS_ZERO:
            return;
        case IFPF_IS_NORMAL:
        case IFPF_IS_SUBNORMAL:
            normalize(value);
            if (value->exp > maxexp)
                SetFPFInfinity(value, value->sign);
            else if (value->exp < minexp) {
                if (value->exp + bits < minexp)
                    SetFPFZero(value, 0);
                else {
                    while (value->exp < minexp) {
                        u16 carry = 0;
                        ShiftMantRight1(&carry, value->mantissa);
                        value->exp++ ;
                    }
                    if (IsMantissaZero(value->mantissa))
                        SetFPFZero(value,0);
                    else
                        value->type = IFPF_IS_SUBNORMAL;
                }
            } else {
                int i, v;
                int rounding = FALSE;
                if (bits % 16) {
                    int mask = 0x8000, mask2 = 0x8000;
                    for (i= 1; i < bits % 16; i++) {
                        mask >>= 1;
                        mask2 >>= 1;
                        mask |= 0x8000;
                    }
                    if (value->mantissa[bits/16] & ~mask)
                        rounding = TRUE;
                    value->mantissa[bits /16] &= mask;
                    v = mask2;
                }
                else
                    v = 1;
                for (i = (bits + 15)/16; i < INTERNAL_FPF_PRECISION; i++)
                {
                    if (value->mantissa[i])
                        rounding ++;
                    value->mantissa[i] = 0;
                }
                if (rounding)
                {
                    int n;

                    /* do an add of 1 to the LSB */
                    for (i= bits/16; i >= 0; i--)
                    {
                        n =	value->mantissa[i] + v;
                        value->mantissa[i] = n;
                        if (n < 0x10000)
                            break;
                        v = 1;
                    }
                    /* overflow????? */
                    if (n >= 0x10000)
                    {
                        value->exp++;
                        /* exponent too large ? */
                        if (value->exp >= maxexp)
                        {
                            /* yes leave it alone */
                            SetFPFInfinity(value, value->sign);
                        }
                        else 
                        {
                            /* else shift mantissa right and increment exponent... */
                            u16 carry = 1 ; /* high bit should be one */
                            ShiftMantRight1(&carry, value->mantissa);
                        }
                    }
                }
            }
            break ;
    }
}
#ifdef TEST
int main()
{
    int i;
    char buf[256];
    float f;
    double d;
    long double l;
    FPF one,two,three ;
    int val;
    LLONG_TYPE aa ;
    LongLongToFPF(&one,-1976543);
    LongLongToFPF(&two,100000000);
    DivideFPF(&one, &two, &three);
/*    val = FPFTensExponent(&three);*/
/*    printf("%d\n",val);*/
/*    FPFMultiplyPowTen(&one, -2);*/
/*    printf("%d\n",memcmp(&one,&three,sizeof(one)));*/
    FPFToString(buf,&three);
    
    printf("%s\n",buf);
    FPFToFloat(&f,&one);
    FPFToDouble(&d,&one);
    FPFToLongDouble(&l, &one);
    aa = FPFToLongLong(&one) ;
    printf("%f %f %Lf %ld", f,d,l, aa);
    for (i=0; i < INTERNAL_FPF_PRECISION; i++)
        printf("%x ",one.mantissa[i]);
    printf("\n%d\n",one.type);
    FPFTruncate(&one,10,4,-4);
    for (i=0; i < INTERNAL_FPF_PRECISION; i++)
        printf("%x ",one.mantissa[i]);
    printf("\n%d\n",one.type);
    LongLongToFPF(&one,1);
    printf("%d\n",ValueIsOne(&one));
    printf("%d\n",FPFGTE(&one,&two));
    printf("%d\n",FPFGTE(&two,&one));
}
#endif
