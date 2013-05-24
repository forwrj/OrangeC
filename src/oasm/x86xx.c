<ADL>
    <Processor Name="x86">
    </Processor>
    <Coding>
        <Param Name="CaseSensitive" Value="false"/>
        <Param Name="Endian" Value="little"/>
        <Param Name="BitsPerMAU" Value="8"/>
        <Number Name="signed8address">
            <Instance Value="-#:8"/>
        </Number>
        <Number Name="signed8">
            <Instance Value="#:8"/>
        </Number>
        <Number Name="mem6">
            <Instance Value="#:6"/>
        </Number>
        <Number Name="mem8">
            <Instance Value="#:8"/>
        </Number>
        <Number Name="mem16">
            <Instance Value="$#:16"/>
        </Number>
        <Number Name="mem32">
            <Instance Value="$#:32"/>
        </Number>
        <Number Name="address16">
            <Instance Value="$#:16" Cond="'seg32'==0"/>
        </Number>
        <Number Name="address32">
            <Instance Value="$#:32" Cond="'seg32'==1"/>
        </Number>
        <Number Name="rel8" relOfs="1">
            <Instance Value="-$#:8"/>
        </Number>
        <Number Name="rel8n" relOfs="-1">
            <Instance Value="-$#:8"/>
        </Number>
        <Number Name="rel16" relOfs="2">
            <Instance Value="-$#:16" Cond="'seg32'==0"/>
        </Number>
        <Number Name="rel16n" relOfs="-2">
            <Instance Value="-$#:16" Cond="'seg32'==0"/>
        </Number>
        <Number Name="rel16j" relOfs="2">
            <Instance Value="-$#:16" Cond="'seg32'==0"/>
        </Number>
        <Number Name="rel16jn" relOfs="-2">
            <Instance Value="-$#:16" Cond="'seg32'==0"/>
        </Number>
        <Number Name="rel32" relOfs="4">
            <Instance Value="-$#:32" Cond="'seg32'!=0"/>
        </Number>
        <Number Name="scale">
            <Instance Value="1;0"/>
            <Instance Value="2;1"/>
            <Instance Value="4;2"/>
            <Instance Value="8;3"/>
        </Number>
        <Number Name="zero">
            <Instance Value="0;0"/>
        </Number>
        <Number Name="one">
            <Instance Value="1;1"/>
        </Number>
        <StateVars>
            <Instance  Name="seg32" Init="0"/>
        </StateVars>
        <State Name="addr16">
            <When Cond="'seg32'==0" Value=""/>
            <When Cond="'seg32'!=0" Value="0x67:8"/>
        </State>
        <State Name="addr32">
            <When Cond="'seg32'!=0" Value=""/>
            <When Cond="'seg32'==0" Value="0x67:8"/>
        </State>
        <State Name="data16">
            <When Cond="'seg32'==0" Value=""/>
            <When Cond="'seg32'!=0" Value="0x66:8"/>
        </State>
        <State Name="data32">
            <When Cond="'seg32'!=0" Value=""/>
            <When Cond="'seg32'==0" Value="0x66:8"/>
        </State>
        <Register Class="general">
            <Instance Name="al" Ord="0" Class="reg8,low"/>
            <Instance Name="ah" Ord="4" Class="reg8,high"/>
            <Instance Name="ax" Ord="0" Class="reg16"/>
            <Instance Name="eax" Ord="0" Class="base32, index32, reg32"/>
        </Register>
        <Register Class="general">
            <Instance Name="cl" Ord="1" Class="reg8,low"/>
            <Instance Name="ch" Ord="5" Class="reg8,high"/>
            <Instance Name="cx" Ord="1" Class="reg16"/>
            <Instance Name="ecx" Ord="1" Class="base32, index32, reg32"/>
        </Register>
        <Register Class="general">
            <Instance Name="dl" Ord="2" Class="reg8,low"/>
            <Instance Name="dh" Ord="6" Class="reg8,high"/>
            <Instance Name="dx" Ord="2" Class="reg16"/>
            <Instance Name="edx" Ord="2" Class="base32, index32, reg32"/>
        </Register>
        <Register Class="general">
            <Instance Name="bl" Ord="3" Class="reg8,low,pushed"/>
            <Instance Name="bh" Ord="7" Class="reg8,high,pushed"/>
            <Instance Name="bx" Ord="3" base="0" Class="base16, reg16, pushed"/>
            <Instance Name="ebx" Ord="3" Class="base32, index32, reg32,pushed"/>
        </Register>
        <Register Class="stack">
            <Instance Name="sp" Ord="4" Class="reg16"/>
            <Instance Name="esp" Ord="4" Class="base32, reg32"/>
        </Register>
        <Register Class="stack">
            <Instance Name="bp" Ord="5" base="1" Class="base16, reg16"/>
            <Instance Name="ebp" Ord="5" Class="base32, index32, reg32"/>
        </Register>
        <Register Class="general">
            <Instance Name="si" Ord="6" index="0" Class="reg16,index16,pushed"/>
            <Instance Name="esi" Ord="6" Class="base32, index32, reg32,pushed"/>
        </Register>
        <Register Class="general">
            <Instance Name="di" Ord="7" index="1" Class="reg16,index16, pushed"/>
            <Instance Name="edi" Ord="7" Class="base32, index32, reg32, pushed"/>
        </Register>
        <Register Class="segment">
            <Instance Name="es" Ord="0" Prefix="0x26"/>
        </Register>
        <Register Class="segment">
            <Instance Name="cs" Ord="1" Prefix="0x2e"/>
        </Register>
        <Register Class="segment">
            <Instance Name="ss" Ord="2" Prefix="0x36"/>
        </Register>
        <Register Class="segment">
            <Instance Name="ds" Ord="3" Prefix="0x3e"/>
        </Register>
        <Register Class="segment">
            <Instance Name="fs" Ord="4" Prefix="0x64"/>
        </Register>
        <Register Class="segment">
            <Instance Name="gs" Ord="5" Prefix="0x65"/>
        </Register>
        <Register Class="floatreg">
            <Instance Name="st0" Ord="0" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st1" Ord="1" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st2" Ord="2" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st3" Ord="3" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st4" Ord="4" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st5" Ord="5" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st6" Ord="6" />
        </Register>
        <Register Class="floatreg">
            <Instance Name="st7" Ord="7" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr0" Ord="0" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr1" Ord="1" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr2" Ord="2" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr3" Ord="3" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr4" Ord="4" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr5" Ord="5" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr6" Ord="6" />
        </Register>
        <Register Class="controlreg">
            <Instance Name="cr7" Ord="7" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr0" Ord="0" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr1" Ord="1" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr2" Ord="2" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr3" Ord="3" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr4" Ord="4" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr5" Ord="5" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr6" Ord="6" />
        </Register>
        <Register Class="debugreg">
            <Instance Name="dr7" Ord="7" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr0" Ord="0" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr1" Ord="1" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr2" Ord="2" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr3" Ord="3" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr4" Ord="4" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr5" Ord="5" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr6" Ord="6" />
        </Register>
        <Register Class="tracereg">
            <Instance Name="tr7" Ord="7" />
        </Register>
        <DoubleReg Name="edx:eax"/>
        <DoubleReg Name="ecx:eax"/>
        <DoubleReg Name="edx:ecx"/>
        <DoubleReg Name="ebx:esi" Class="pushed"/>
        <DoubleReg Name="ebx:edi" Class="pushed"/>
        <DoubleReg Name="edi:esi" Class="pushed"/>

        <Address Name="['mem:address16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding="'addr16' 'op' 0:2 'mod':3 6:3 'mem':16"/>
        <Address Name="[ds:'mem:address16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding="0x3e:8 'addr16' 'op' 0:2 'mod':3 6:3 'mem':16"/>
        <Address Name="[ss:'mem:address16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding="0x36:8 'addr16' 'op' 0:2 'mod':3 6:3 'mem':16"/>
        <Address Name="['seg:segment':'mem:address16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding="'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 6:3 'mem':16"/>
        <Address Name="[bx+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 0:2 'index.index':1"/>
        <Address Name="[bp+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 1:2 'index.index':1"/>
        <Address Name="[ds:bx+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 0:2 'index.index':1"/>
        <Address Name="[ss:bx+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 0:2 'mod':3 0:2 'index.index':1"/>
        <Address Name="[ss:bp+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 1:2 'index.index':1"/>
        <Address Name="[ds:bp+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 0:2 'mod':3 1:2 'index.index':1"/>
        <Address Name="['seg:segment':bx+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 0:2 'index.index':1"/>
        <Address Name="['seg:segment':bp+'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 1:2 'index.index':1"/>
        <Address Name="['index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 'index.index'+4:3"/>
        <Address Name="[ds:'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 'index.index'+4:3"/>
        <Address Name="[ss:'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 0:2 'mod':3 'index.index'+4:3"/>
        <Address Name="['seg:segment':'index:index16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 'index.index'+4:3"/>
        <Address Name="[bx]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[ds:bx]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[ss:bx]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 0:2 'mod':3 7:3"/>
        <Address Name="['seg:segment':bx]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[bp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="[ss:bp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="[ds:bp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="['seg:segment':bp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="[bx+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[ds:bx+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[ss:bx+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 0:2 'mod':3 7:3"/>
        <Address Name="['seg:segment':bx+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 0:2 'mod':3 7:3"/>
        <Address Name="[bp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="[ss:bp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="[ds:bp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 1:2 'mod':3 6:3 0:8"/>
        <Address Name="['seg:segment':bp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 6:3 0:8"/>
    
        <Address Name="[bx+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 0:2 'index.index':1 'signed':8"/>
        <Address Name="[bp+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 1:2 'index.index':1 'signed':8"/>
        <Address Name="[ds:bx+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 0:2 'index.index':1 'signed':8"/>
        <Address Name="[ss:bx+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 1:2 'mod':3 0:2 'index.index':1 'signed':8"/>
        <Address Name="[ss:bp+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 1:2 'index.index':1 'signed':8"/>
        <Address Name="[ds:bp+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 1:2 'mod':3 1:2 'index.index':1 'signed':8"/>
        <Address Name="['seg:segment':bx+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 11:2 'index.index':1 'signed':8"/>
        <Address Name="['seg:segment':bp+'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 01:2 'index.index':1 'signed':8"/>
        <Address Name="['index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 'index.index'+4:3 'signed':8"/>
        <Address Name="[ds:'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 'index.index'+4:3 'signed':8"/>
        <Address Name="[ss:'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 1:2 'mod':3 'index.index'+4:3 'signed':8"/>
        <Address Name="['seg:segment':'index:index16' + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 'index.index'+4:3 'signed':8"/>
        <Address Name="[bx + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 7:3 'signed':8"/>
        <Address Name="[ds:bx + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 7:3 'signed':8"/>
        <Address Name="[ss:bx + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36 'op' 1:2 'mod':3 7:3 'signed':8"/>
        <Address Name="['seg:segment':bx + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 7:3 'signed':8"/>
        <Address Name="[bp + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 'signed':8"/>
        <Address Name="[ss:bp + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 1:2 'mod':3 6:3 'signed':8"/>
        <Address Name="[ds:bp + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e 'op' 1:2 'mod':3 6:3 'signed':8"/>
        <Address Name="['seg:segment':bp + 'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 1:2 'mod':3 6:3 'signed':8"/>
    
    
        <Address Name="[bx+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 0:2 'index.index':1 'mem':16"/>
        <Address Name="[bp+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 1:2 'index.index':1 'mem':16"/>
        <Address Name="[ds:bx+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 0:2 'index.index':1 'mem':16"/>
        <Address Name="[ss:bx+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 2:2 'mod':3 0:2 'index.index':1 'mem':16"/>
        <Address Name="[ss:bp+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 1:2 'index.index':1 'mem':16"/>
        <Address Name="[ds:bp+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 2:2 'mod':3 1:2 'index.index':1 'mem':16"/>
        <Address Name="['seg:segment':bx+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 2:2 'mod':3 0:2 'index.index':1 'mem':16"/>
        <Address Name="['seg:segment':bp+'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'seg.Prefix':8 'addr16' 'op' 2:2 'mod':3 1:2 'index.index':1 'mem':16"/>
        <Address Name="['index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 'index.index'+4:3 'mem':16"/>
        <Address Name="[ds:'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 'index.index'+4:3 'mem':16"/>
        <Address Name="[ss:'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 2:2 'mod':3 'index.index'+4:3 'mem':16"/>
        <Address Name="['seg:segment':'index:index16' + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 2:2 'mod':3 'index.index'+4:3 'mem':16"/>
        <Address Name="[bx + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 7:3 'mem':16"/>
        <Address Name="[ds:bx + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 7:3 'mem':16"/>
        <Address Name="[ss:bx + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x36:8 'op' 2:2 'mod':3 7:3 'mem':16"/>
        <Address Name="['seg:segment':bx + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 2:2 'mod':3 7:3 'mem':16"/>
        <Address Name="[bp + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 6:3 'mem':16"/>
        <Address Name="[ss:bp + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 'op' 2:2 'mod':3 6:3 'mem':16"/>
        <Address Name="[ds:bp + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit" Coding = "'addr16' 0x3e:8 'op' 2:2 'mod':3 6:3 'mem':16"/>
        <Address Name="['seg:segment':bp + 'mem:mem16']" Class="rmx,rm,frm,rm8,rm16,rm32,rm16bit"  Coding = "'seg.Prefix':8 'addr16' 'op' 2:2 'mod':3 6:3 'mem':16"/>
    
        <Address Name="[esp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ebp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="['base:base32']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 'base.Ord':3"/>
        <Address Name="[ss:esp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ss:ebp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ss:'base:base32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ds:esp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ds:ebp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ds:'base:base32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x3:3"/>
        <Address Name="['seg:segment':esp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="['seg:segment':ebp]" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="['seg:segment':'base:base32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 'base.Ord':3"/>
        <Address Name="['mem:address32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x05:3 'mem':32"/>
        <Address Name="[ds:'mem:address32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="0x3e:8 'addr32' 'op' 0:2 'mod':3 0x05:3 'mem':32"/>
        <Address Name="[ss:'mem:address32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="0x36:8 'addr32' 'op' 0:2 'mod':3 0x05:3 'mem':32"/>
        <Address Name="['seg:segment':'mem:address32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'seg.Prefix':8 'addr32' 'op' 0:2 'mod':3 0x05:3 'mem':32"/>

        <Address Name="[esp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ebp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="['base:base32'+'z:zero']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 'base.Ord':3"/>
        <Address Name="[ss:esp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ss:ebp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ss:'base:base32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ds:esp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="[ds:ebp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="[ds:'base:base32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x3:3"/>
        <Address Name="['seg:segment':esp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3"/>
        <Address Name="['seg:segment':ebp+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x5:3 0x0:8"/>
        <Address Name="['seg:segment':'base:base32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 'base.Ord':3"/>
    
        <Address Name="[esp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'signed':8"/>
        <Address Name="[ebp+'signed:signed8']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 5:3 'signed':8"/>
        <Address Name="['base:base32'+'signed:signed8']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 'base.Ord':3 'signed':8"/>
        <Address Name="[ss:esp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'signed':8"/>
        <Address Name="[ss:ebp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x5:3 'signed':8"/>
        <Address Name="[ss:'base:base32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 1:2 'mod':3 0x3:3 'signed':8"/>
        <Address Name="[ds:esp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'signed':8"/>
        <Address Name="[ds:ebp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x5:3 'signed':8"/>
        <Address Name="[ds:'base:base32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x3:3 'signed':8"/>
        <Address Name="['seg:segment':esp+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'signed':8"/>
        <Address Name="['seg:segment':ebp+'signed:signed8']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 5:3 'signed':8"/>
        <Address Name="['seg:segment':'base:base32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 'base.Ord':3 'signed':8"/>
    
        <Address Name="[ebp+'mem:mem32']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 5:3 'mem':32"/>
        <Address Name="[esp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'mem':32"/>
        <Address Name="['base:base32'+'mem:mem32']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 'base.Ord':3 'mem':32"/>
        <Address Name="[ss:esp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'mem':32"/>
        <Address Name="[ss:ebp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x5:3 'mem':32"/>
        <Address Name="[ss:'base:base32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 2:2 'mod':3 'base.Ord':3"/>
        <Address Name="[ds:esp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'mem':32"/>
        <Address Name="[ds:ebp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x5:3 'mem':32"/>
        <Address Name="[ds:'base:base32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 'base.Ord':3 'mem':32"/>
        <Address Name="['seg:segment':ebp+'mem:mem32']"	Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 5:3 'mem':32"/>
        <Address Name="['seg:segment':esp+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 0:2 0x4:3 0x4:3 'mem':32"/>
        <Address Name="['seg:segment':'base:base32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 'base.Ord':3 'mem':32"/>
    
    
        <Address Name="[ebp*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 0:32"/> 
        <Address Name="[ebp*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 'mem':32"/> 
        <Address Name="['base:base32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 0:32"/> 
        <Address Name="['base:base32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 'mem':32"/> 
        <Address Name="[ss:ebp*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 0:32"/> 
        <Address Name="[ss:ebp*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 'mem':32"/> 
        <Address Name="[ss:'base:base32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 0:32"/> 
        <Address Name="[ss:'base:base32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 'mem':32"/> 
        <Address Name="[ds:ebp*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 0:32"/> 
        <Address Name="[ds:ebp*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 'mem':32"/> 
        <Address Name="[ds:'base:base32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 0:32"/> 
        <Address Name="[ds:'base:base32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 'mem':32"/> 
        <Address Name="['seg:segment':ebp*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 0:32"/> 
        <Address Name="['seg:segment':ebp*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 5:3 0x5:3 'mem':32"/> 
        <Address Name="['seg:segment':'base:base32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 0:32"/> 
        <Address Name="['seg:segment':'base:base32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'base.Ord':3 0x5:3 'mem':32"/> 

        <Address Name="[ebp+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="[ebp+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[esp+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[esp+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="['base:base32'+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['base:base32'+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ss:ebp + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="[ss:ebp + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[ss:esp + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[ss:esp + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ds:ebp + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 0:8"/> 
        <Address Name="[ds:ebp + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[ds:esp + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[ds:esp + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['seg:segment':ebp+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="['seg:segment':ebp+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="['seg:segment':esp+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="['seg:segment':esp+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'*'sc:scale'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'+'z:zero']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 

        <Address Name="[ebp+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="[ebp+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[esp+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[esp+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="['base:base32'+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['base:base32'+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ss:ebp + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="[ss:ebp + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[ss:esp + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[ss:esp + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ss:'base:base32' + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ds:ebp + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 0:8"/> 
        <Address Name="[ds:ebp + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="[ds:esp + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="[ds:esp + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="[ds:'base:base32' + 'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['seg:segment':ebp+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3"/> 
        <Address Name="['seg:segment':ebp+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3"/> 
        <Address Name="['seg:segment':esp+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3"/> 
        <Address Name="['seg:segment':esp+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'*'sc:scale']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 0:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3"/> 

        <Address Name="[ebp+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[ebp+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[esp+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="[esp+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="['base:base32'+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="['base:base32'+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="[ss:ebp + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[ss:ebp + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[ss:esp + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="[ss:esp + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="[ds:ebp + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[ds:ebp + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="[ds:esp + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="[ds:esp + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':ebp+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':ebp+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':esp+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':esp+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'*'sc:scale'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding=" 'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'+'signed:signed8']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 1:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'signed.Ord':8"/> 

        <Address Name="[ebp+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[ebp+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[esp+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="[esp+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="['base:base32'+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="['base:base32'+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="[ss:ebp + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[ss:ebp + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[ss:esp + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="[ss:esp + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="[ss:'base:base32' + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x36:8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="[ds:ebp + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[ds:ebp + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="[ds:esp + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="[ds:esp + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 0x3e:8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="[ds:'base:base32' + 'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="['seg:segment':ebp+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="['seg:segment':ebp+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 5:3 'mem':32"/> 
        <Address Name="['seg:segment':esp+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="['seg:segment':esp+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 4:3 'mem':32"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'*'sc:scale'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 'sc':2 'index.Ord':3 'base.Ord':3 'mem':32"/> 
        <Address Name="['seg:segment':'base:base32'+'index:index32'+'mem:mem32']" Class="rmx,rm,frm,rm8,rm16,rm32,rm32bit" Coding="'addr32' 'seg.Prefix':8 'op' 2:2 'mod':3 0x4:3 0:2 'index.Ord':3 'base.Ord':3 'mem':32"/> 

        <Address Name="'reg:reg8'" Class="rm8,rmx,reg8rm" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
        <Address Name="'reg:reg16'" Class="rm16,rmx,reg16rm" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
        <Address Name="'reg:reg32'" Class="rm32,rmx,reg32rm" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
        <Address Name="'reg:floatreg'" Class="frm, regfloat" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
    
        <Opcode Class="single">
            <Operands Name="empty" Coding="'op'"/>
        </Opcode>
        <Opcode Class="twobyte">
            <Operands Name="empty" Coding="0x0f:8 'op'"/>
        </Opcode>
        <Opcode Class="reg16rmx">
            <Operands Name="'modreg:reg16', {word} 'rm:rm16'" op="'data16' 'op1'" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32'" op="'data32' 'op1'" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="reg16rmnrx">
            <Operands Name="'modreg:reg16', {word} 'rm:rm'" op="'data16' 'op1'" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword} 'rm:rm'" op="'data32' 'op1'" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="math">
            <Operands Name="al, {byte} 'omem:mem8'" Coding="'op1':8 'omem':8"/>
            <Operands Name="ax, {word} 'omem:mem16'" Coding="'data16' 'op1'+1:8 'omem':16"/>
            <Operands Name="eax, {dword} 'omem:mem32'" Coding="'data32' 'op1'+1:8 'omem':32"/>
            <Operands Name="'modreg:reg8', {byte} 'rm:rm8'" mod="'modreg.Ord'" op="'op2'+2:8" />
            <Operands Name="'modreg:reg16', {word} 'rm:rm16'" mod="'modreg.Ord'" op="'data16' 'op2'+3:8" />
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32'" mod="'modreg.Ord'" op="'data32' 'op2'+3:8" />
            <Operands Name="{byte} 'rm:rm8', 'modreg:reg8'" mod="'modreg.Ord'" op="'op2':8" />
            <Operands Name="{word} 'rm:rm16', 'modreg:reg16'" mod="'modreg.Ord'" op="'data16' 'op2'+1:8" />
            <Operands Name="{dword} 'rm:rm32', 'modreg:reg32'" mod="'modreg.Ord'" op="'data32' 'op2'+1:8" />
            <Operands Name="byte 'rm:rm8',  {byte} 'omem:mem8'" op="0x80:8" Coding="native 'omem':8"/>
            <Operands Name="word 'rm:rm16', byte 'signedimm:signed8'" op="0x83:8" Coding="'data16' native 'signedimm':8"/>
            <Operands Name="word 'rm:rm16', {word} 'omem:mem16'" op="0x81:8" Coding="'data16' native 'omem':16"/>
            <Operands Name="dword 'rm:rm32', byte 'signedimm:signed8'" op="0x83:8" Coding="'data32' native 'signedimm':8"/>
            <Operands Name="dword 'rm:rm32', {dword} 'omem:mem32'" op="0x81:8" Coding="'data32' native 'omem':32"/>
            <Operands Name="'modreg:reg8rm', {byte} 'omem:mem8'" op="0x80:8" Coding="native 'omem':8"/>
            <Operands Name="'modreg:reg16rm', byte 'signedimm:signed8'" op="0x83:8" Coding="'data16' native 'signedimm':8"/>
            <Operands Name="'modreg:reg16rm', {word} 'omem:mem16'" op="0x81:8" Coding="'data16' native 'omem':16"/>
            <Operands Name="'modreg:reg32rm', byte 'signedimm:signed8'" op="0x83:8" Coding="'data32' native 'signedimm':8"/>
            <Operands Name="'modreg:reg32rm', {dword} 'omem:mem32'" op="0x81:8" Coding="'data32' native 'omem':32"/>
        </Opcode>
        <Opcode Class="bit">
            <Operands Name="{word} 'rm:rm16', {word} 'omem:mem8'" op="'op1'" Coding="'data16' native 'omem':8"/>
            <Operands Name="{dword} 'rm:rm32', {dword} 'omem:mem8'" op="'op1'" Coding="'data32' native 'omem':8"/>
            <Operands Name="{word} 'rm:rm16', 'modreg:reg16'" op="'data16' 'op2'" mod="'modreg.Ord'" />
            <Operands Name="{dword} 'rm:rm32', 'modreg:reg32'" op="'data32' 'op2'" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="incdec">
            <Operands Name="'modreg:reg8rm'" op="0xfe:8"/>
            <Operands Name="'modreg:reg16'" Coding="'data16' 'op':5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg32'" Coding="'data32' 'op':5 'modreg.Ord':3"/>
            <Operands Name="byte 'rm:rm8'" op="0xfe:8" />
            <Operands Name="word 'rm:rm16'" op="'data16' 0xff:8" />
            <Operands Name="dword 'rm:rm32'" op="'data32' 0xff:8" />
        </Opcode>
        <Opcode Class="sizedrm">
            <Operands Name="'rm:reg8rm'" op="0xf6:8 " />
            <Operands Name="'rm:reg16rm'" op="'data16' 0xf7:8" />
            <Operands Name="'rm:reg32rm'" op="'data32' 0xf7:8" />
            <Operands Name="byte 'rm:rm8'" op="0xf6:8 " />
            <Operands Name="word 'rm:rm16'" op="'data16' 0xf7:8" />
            <Operands Name="dword 'rm:rm32'" op="'data32' 0xf7:8" />
        </Opcode>
        <Opcode Class="floatmath">
            <Operands Name="st0,'reg:floatreg'" Coding="'op1' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="'reg:floatreg', st0" Coding="'op1'+4 3:2 'mod1':3 'reg.Ord':3"/>
            <Operands Name="'reg:floatreg'" Coding="'op1' 3:2 'mod1':3 'reg.Ord':3"/>
            <Operands Name="dword 'reg:frm'" op="'op1'"/>
            <Operands Name="qword 'reg:frm'" op="'op1'+4"/>
        </Opcode>
        <Opcode Class="floatmathp">
            <Operands Name="'reg:floatreg',st0" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="'reg:floatreg'" Coding="'op' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="empty" Coding="'op' 3:2 'mod':3 1:3"/>
        </Opcode>
        <Opcode Class="floatimath">
            <Operands Name="word 'rm:rm'" op="'op1'+4:8" />
            <Operands Name="dword 'rm:rm'" op="'op1':8" />
        </Opcode>
        <Opcode Class="fbld">
            <Operands Name="{ tword } 'rm:rmx'" />
        </Opcode>
        <Opcode Class="branch">
            <Operands Name="short 'rel:rel8'" Coding="0x7:4 'sel':4 'rel':8"/>
            <Operands Name="near 'rel:rel16n'" Coding="'data16' 0x0f 0x8:4 'sel':4 'rel':16"/>
            <Operands Name="near 'rel:rel32'" Coding="'data32' 0x0f 0x8:4 'sel':4 'rel':32"/>
            <Operands Name="'rel:rel16'" Coding="'data16' 0x0f 0x8:4 'sel':4 'rel':16"/>
            <Operands Name="'rel:rel32'" Coding="'data32' 0x0f 0x8:4 'sel':4 'rel':32"/>
        </Opcode>
        <Opcode Class="cmov">
            <Operands Name="'modreg:reg16', {word}'rm:rm16'" op="'data16' 0x0f:8 0x4:4 'sel':4" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {word}'rm:rm32'" op="'data32' 0x0f:8 0x4:4 'sel':4" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="set">
            <Operands Name="{byte}'rm:rm8'" op="0x0f:8 0x9:4 'sel':4" mod="0"/> 
        </Opcode>
        <Opcode Class="movx">
            <Operands Name="'modreg:reg16','rm:reg8rm'" op="'data16' 0x0f:8 'op1':8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32','rm:reg8rm'" op="'data32' 0x0f:8 'op1':8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32','rm:reg16rm'" op="'data32' 0x0f:8 'op1'+1:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg16',byte 'rm:rm8'" op="'data16' 0x0f:8 'op1':8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32',byte 'rm:rm16'" op="'data32' 0x0f:8 'op1':8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32',word 'rm:rm32'" op="'data32' 0x0f:8 'op1'+1:8" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="shift">
            <Operands Name="'modreg:reg8rm', 'one:one'" op="0xd0:8" />
            <Operands Name="'modreg:reg8rm', 'omem:mem8'" op="0xc0:8" Coding="native 'omem':8" />
            <Operands Name="'modreg:reg8rm', cl" op="0xd2:8" />
            <Operands Name="byte 'rm:rm8', {byte}'one:one'" op="0xd0:8" />
            <Operands Name="byte 'rm:rm8',{byte} 'omem:mem8'" op="0xc0:8" Coding="native 'omem':8"/>
            <Operands Name="byte 'rm:rm8',cl" op="0xd2:8" />
            <Operands Name="'modreg:reg16rm', 'one:one'" op="'data16' 0xd1:8" />
            <Operands Name="'modreg:reg16rm', 'omem:mem8'" op="'data16' 0xc1:8" Coding="native 'omem':8"/>
            <Operands Name="'modreg:reg16rm', cl" op="'data16' 0xd3:8" />
            <Operands Name="word 'rm:rm16', {byte}'one:one'" op="'data16' 0xd1:8" />
            <Operands Name="word 'rm:rm16',{byte} 'omem:mem8'" op="'data16' 0xc1:8" Coding="native 'omem':8"/>
            <Operands Name="word 'rm:rm16',cl" op="'data16' 0xd3:8" />
            <Operands Name="'modreg:reg32rm', 'one:one'" op="'data32' 0xd1:8" />
            <Operands Name="'modreg:reg32rm', {byte} 'omem:mem8'" op="'data32' 0xc1:8" Coding="native 'omem':8"/>
            <Operands Name="'modreg:reg32rm', cl" op="'data32' 0xd3:8" />
            <Operands Name="dword 'rm:rm32',{byte} 'one:one'" op="'data32' 0xd1:8" />
            <Operands Name="dword 'rm:rm32',{byte}'omem:mem8'" op="'data32' 0xc1:8" Coding="native 'omem':8"/>
            <Operands Name="dword 'rm:rm32',cl" op="'data32' 0xd3:8" />
        </Opcode>
        <Opcode Class="regshift">
            <Operands Name="{word}'rm:rm16', 'modreg:reg16', 'omem:mem8'" op="'data16' 0x0f:8 'op1':8" mod="'modreg.Ord'" Coding="native 'omem':8"/>
            <Operands Name="{word}'rm:rm16', 'modreg:reg16', cl" op="'data16' 0x0f:8 'op1'+1:8" mod="'modreg.Ord'" />
            <Operands Name="{dword}'rm:rm32', 'modreg:reg32', 'omem:mem8'" op="'data32' 0x0f:8 'op1':8" mod="'modreg.Ord'" Coding="native 'omem':8" />
            <Operands Name="{dword}'rm:rm32', 'modreg:reg32', cl" op="'data32' 0x0f:8 'op1'+1:8" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Class="nostrictrm">
            <Operands Name="'rm:rm'" />
        </Opcode>
        <Opcode Name="aaa" op="0x37:8" Class="single"/>
        <Opcode Name="aad" op="0xd5:8 0x0a:8" Class="single"/>
        <Opcode Name="aam" op="0xd4:8 0x0a:8" Class="single"/>
        <Opcode Name="aas" op="0x3f:8" Class="single"/>
        <Opcode Name="adc" op1="0x14:8" op2="0x10" mod="2" Class="math"/>
        <Opcode Name="add" op1="0x04:8" op2="0x00" mod="0" Class="math"/>
        <Opcode Name="and" op1="0x24:8" op2="0x20" mod="4" Class="math"/>
        <Opcode Name="arpl">
            <Operands Name="'rm:rm16', 'modreg:reg16'" op="0x63:8" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Name="bound" op1="0x62:8" Class="reg16rmx"/>
        <Opcode Name="bsf" op1="0x0f:8 0xbc:8" Class="reg16rmx"/>
        <Opcode Name="bsr" op1="0x0f:8 0xbd:8" Class="reg16rmx"/>
        <Opcode Name="bswap">
            <Operands Name="'modreg:reg32'" mod="'modreg.Ord'" Coding="'data32' 0x0f:8 0x19:5 'modreg.Ord':3"/>
        </Opcode>
        <Opcode Name="bt" Class="bit" op1= "0x0f:8 0xba:8" op2="0x0f:8 0xa3:8" mod="4"/>
        <Opcode Name="btc" Class="bit" op1= "0x0f:8 0xba:8" op2="0x0f:8 0xbb:8" mod="7"/>
        <Opcode Name="btr" Class="bit" op1= "0x0f:8 0xba:8" op2="0x0f:8 0xb3:8" mod="6"/>
        <Opcode Name="bts" Class="bit" op1= "0x0f:8 0xba:8" op2="0x0f:8 0xab:8" mod="5"/>
        <Opcode Name="call">
            <Operands Name="'seg:mem16':{word}'omem:address16'" Coding="'data16' 0x9a:8 'omem':16 'seg':16"/>
            <Operands Name="'seg:mem16':{dword}'omem:address32'" Coding="'data32' 0x9a:8 'omem':32 'seg':16"/>
            <Operands Name="'rel:rel16j'" Coding="'data16' 0xe8:8 'rel':16"/>
            <Operands Name="'rel:rel32'" Coding="'data32' 0xe8:8 'rel':32"/>
            <Operands Name="'modreg:reg16rm'" op="'data16' 0xff:8" mod="2" />
            <Operands Name="'modreg:reg32rm'" op="'data32' 0xff:8" mod="2" />
            <Operands Name="{word} 'rm:rm16bit'" op="'data16' 0xff:8" mod="2" />
            <Operands Name="{dword} 'rm:rm32bit'" op="'data32' 0xff:8" mod="2" />
            <Operands Name="far 'omem:address16'" Coding="0xf:8 0xf:8 'data16' 0x9a:8 'omem':16 0:16"/>
            <Operands Name="far 'omem:address32'" Coding="0xf:8 0xf:8 'data32' 0x9a:8 'omem':32 0:16"/>
            <Operands Name="far 'rm:rm16bit'" op= "'data16' 0xff:8" mod="3" />
            <Operands Name="far 'rm:rm32bit'" op= "'data32' 0xff:8" mod="3" />
        </Opcode>
        <Opcode Name="cbw" op="'data16' 0x98:8" Class="single"/>
        <Opcode Name="cdq" op="'data32' 0x99:8" Class="single"/>
        <Opcode Name="clc" op="0xf8:8" Class="single"/>
        <Opcode Name="cld" op="0xfc:8" Class="single"/>
        <Opcode Name="cli" op="0xfa:8" Class="single"/>
        <Opcode Name="clts" op="0x06:8" Class="twobyte"/>
        <Opcode Name="cmc" op="0xf5:8" Class="single"/>
        <Opcode Name="cmova" sel="7" Class="cmov"/>
        <Opcode Name="cmovae" sel="3" Class="cmov"/>
        <Opcode Name="cmovb" sel="2" Class="cmov"/>
        <Opcode Name="cmovbe" sel="6" Class="cmov"/>
        <Opcode Name="cmovc" sel="2" Class="cmov"/>
        <Opcode Name="cmove" sel="4" Class="cmov"/>
        <Opcode Name="cmovg" sel="0xf" Class="cmov"/>
        <Opcode Name="cmovge" sel="0xd" Class="cmov"/>
        <Opcode Name="cmovl" sel="0xc" Class="cmov"/>
        <Opcode Name="cmovle" sel="0xe" Class="cmov"/>
        <Opcode Name="cmovna" sel="6" Class="cmov"/>
        <Opcode Name="cmovnae" sel="2" Class="cmov"/>
        <Opcode Name="cmovnb" sel="3" Class="cmov"/>
        <Opcode Name="cmovnbe" sel="7" Class="cmov"/>
        <Opcode Name="cmovnc" sel="3" Class="cmov"/>
        <Opcode Name="cmovne" sel="5" Class="cmov"/>
        <Opcode Name="cmovng" sel="0xe" Class="cmov"/>
        <Opcode Name="cmovnge" sel="0xc" Class="cmov"/>
        <Opcode Name="cmovnl" sel="0xd" Class="cmov"/>
        <Opcode Name="cmovnle" sel="0xf" Class="cmov"/>
        <Opcode Name="cmovno" sel="1" Class="cmov"/>
        <Opcode Name="cmovnp" sel="0xb" Class="cmov"/>
        <Opcode Name="cmovns" sel="9" Class="cmov"/>
        <Opcode Name="cmovnz" sel="5" Class="cmov"/>
        <Opcode Name="cmovo" sel="0" Class="cmov"/>
        <Opcode Name="cmovp" sel="0xa" Class="cmov"/>
        <Opcode Name="cmovpe" sel="0xa" Class="cmov"/>
        <Opcode Name="cmovpo" sel="0xb" Class="cmov"/>
        <Opcode Name="cmovs" sel="8" Class="cmov"/>
        <Opcode Name="cmovz" sel="4" Class="cmov"/>
        <Opcode Name="cmp" op1="0x3c:8" op2="0x38" mod="7" Class="math"/>
        <Opcode Name="cmps">
            <Operands Name="byte [ds:si], byte es:[di]" Coding="'addr16' 0xa6:8"/>
            <Operands Name="byte ['seg:segment':si], byte es:[di]" Coding="'addr16' 'seg.Prefix':8 0xa6:8"/>
            <Operands Name="byte [ds:esi], byte es:[edi]" Coding="'addr32' 0xa6:8"/>
            <Operands Name="byte ['seg:segment':esi], byte es:[edi]" Coding="'addr32' 'seg.Prefix':8 0xa6:8"/>
            <Operands Name="word [ds:si], word es:[di]" Coding="'data16' 'addr16' 0xa7:8"/>
            <Operands Name="word ['seg:segment':si], word es:[di]" Coding="'data16' 'addr16' 'seg.Prefix':8 0xa7:8"/>
            <Operands Name="word [ds:esi], word es:[edi]" Coding="'data16' 'addr32' 0xa7:8"/>
            <Operands Name="word ['seg:segment':esi], word es:[edi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0xa7:8"/>
            <Operands Name="dword [ds:si], dword es:[di]" Coding="'data32' 'addr16' 0xa7:8"/>
            <Operands Name="dword ['seg:segment':si], dword es:[di]" Coding="'data32' 'addr16' 'seg.Prefix':8 0xa7:8"/>
            <Operands Name="dword [ds:esi], dword es:[edi]" Coding="'data32' 'addr32' 0xa7:8"/>
            <Operands Name="dword ['seg:segment':esi], dword es:[edi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0xa7:8"/>
        </Opcode>
        <Opcode Name="cmpsb" op="0xa6:8" Class="single"/>
        <Opcode Name="cmpsw" op="'data16' 0xa7:8" Class="single"/>
        <Opcode Name="cmpsd" op="'data32' 0xa7:8" Class="single"/>
        <Opcode Name="cmpxchg">
            <Operands Name="{byte} 'rm:rm8', 'modreg:reg8'" mod="'modreg.Ord'" op="0xb0:8" />
        </Opcode>
        <Opcode Name="cmpxchg8b"/> <!-- fixme -->
        <Opcode Name="cpuid" op="0xA2:8" Class="twobyte"/>
        <Opcode Name="cwd" op="'data16' 0x99:8" Class="single"/>
        <Opcode Name="cwde" op="'data32' 0x98:8" Class="single"/>
        <Opcode Name="daa" op="0x27:8" Class="single"/>
        <Opcode Name="das" op="0x2f" Class="single"/>
        <Opcode Name="dec" op="0x9" mod="1" Class="incdec"/>
        <Opcode Name="div" mod="6" Class="sizedrm"/>
        <Opcode Name="enter">
            <Operands Name="{word} 'omem:mem16', {byte} 'mem1:mem8'" Coding="0xc8:8 'omem':16 'mem1':8"/>
        </Opcode>
        <Opcode Name="esc">
            <Operands Name="'omem:mem6', 'rm:rmx'" op="0x1b:5 'omem'>>3:3" mod="'omem'&amp;7" />
        </Opcode>
        <Opcode Name="f2xm1" op="0xd9:8 0xf0:8" Class="single"/>
        <Opcode Name="fabs" op="0xd9:8 0xe1:8" Class="single"/>
        <Opcode Name="fadd" op1="0xd8:8" mod="0" mod1="0" Class="floatmath"/>
        <Opcode Name="faddp" op="0xde:8" mod="0" Class="floatmathp"/>
        <Opcode Name="fbld" op="0xdf:8" mod="4" Class="fbld"/>
        <Opcode Name="fbstp" op="0xdf:8" mod="6" Class="fbld"/>
        <Opcode Name="fchs" op="0xd9:8 0xe0:8" Class="single"/>
        <Opcode Name="fclex" op="0x9b:8 0xdb:8 0xe2:8" Class="single"/>
        <Opcode Name="fnclex" op="0xdb:8 0xe2:8" Class="single"/>
        <Opcode Name="fcom" op1="0xd8:8" mod="2">
            <Operands Name="st0,'reg:floatreg'" Coding="'op1' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="'reg:floatreg'" Coding="'op1' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="dword 'reg:frm'" op="'op1'"/>
            <Operands Name="qword 'reg:frm'" op="'op1'+4"/>
        </Opcode>
        <Opcode Name="fcomp" op1="0xd8:8" mod="3">
            <Operands Name="'reg:floatreg'" Coding="'op1' 3:2 'mod':3 'reg.Ord':3"/>
            <Operands Name="dword 'reg:frm'" op="'op1'"/>
            <Operands Name="qword 'reg:frm'" op="'op1'+4"/>
        </Opcode>
        <Opcode Name="fcompp" op="0xde:8 0xd9:8" Class="single"/>
        <Opcode Name="fcos" op="0xd9:8 0xff:8" Class="single"/>
        <Opcode Name="fdecstp" op="0xd9:8 0xf6:8" Class="single"/>
        <Opcode Name="fdisi" op="0xdb:8 0xe1:8" Class="single"/>
        <Opcode Name="fdiv" op1="0xd8:8" mod="6" mod1="7" Class="floatmath"/>
        <Opcode Name="fdivp" op="0xde:8" mod="7" Class="floatmathp"/>
        <Opcode Name="fdivr" op1="0xd8:8" mod="7" mod1="6" Class="floatmath"/>
        <Opcode Name="fdivrp" op="0xde:8" mod="6" Class="floatmathp"/>
        <Opcode Name="feni" op="0xdb:8 0xe0:8" Class="single"/>
        <Opcode Name="ffree">
            <Operands Name="'reg:regfloat'" op="0xdd" mod="0"/>
        </Opcode>
        <Opcode Name="fiadd" op1="0xda:8" mod="0" Class="floatimath"/>
        <Opcode Name="ficom" op1="0xda:8" mod="2" Class="floatimath"/>
        <Opcode Name="ficomp" op1="0xda:8" mod="3" Class="floatimath"/>
        <Opcode Name="fidiv" op1="0xda:8" mod="6" Class="floatimath"/>
        <Opcode Name="fidivr" op1="0xda:8" mod="7" Class="floatimath"/>
        <Opcode Name="fild" op1="0xdb:8" mod="0" Class="floatimath">
            <Operands Name="qword 'rm:rm'" op="0xdf:8" mod="5"/>
        </Opcode>
        <Opcode Name="fimul" op1="0xda:8" mod="1" Class="floatimath"/>
        <Opcode Name="fincstp" op="0xd9:8 0xf7:8" Class="single"/>
        <Opcode Name="finit" op="0x9b:8 0xdb:8 0xe3:8" Class="single"/>
        <Opcode Name="fninit" op="0xdb:8 0xe3:8" Class="single"/>
        <Opcode Name="fist" op1="0xdb:8" mod="2" Class="floatimath"/>
        <Opcode Name="fistp" op1="0xdb:8" mod="3" Class="floatimath">
            <Operands Name="qword 'rm:rm'" op="0xdf:8" mod="7"/>
        </Opcode>
        <Opcode Name="fisub" op1="0xda:8" mod="4" Class="floatimath"/>
        <Opcode Name="fisubr" op1="0xda:8" mod="5" Class="floatimath"/>
        <Opcode Name="fld">
            <Operands Name="'reg:regfloat'" op="0xd9" mod="0"/>
            <Operands Name="dword 'rm:rm'" op="0xd9" mod="0" />
            <Operands Name="qword 'rm:rm'" op="0xdd" mod="0" />
            <Operands Name="tword 'rm:rm'" op="0xdb" mod="5" />
        </Opcode>
        <Opcode Name="fld1" op="0xd9:8 0xe8:8" Class="single"/>
        <Opcode Name="fldcw">
            <Operands Name="{word}'rm:rm'" op="0xd9:8" mod="5"/>
        </Opcode>
        <Opcode Name="fldenv">
            <Operands Name="'rm:rm'" op="0xd9:8" mod="4"/>
        </Opcode>
        <Opcode Name="fldl2e" op="0xd9:8 0xea:8" Class="single"/>
        <Opcode Name="fldl2t" op="0xd9:8 0xe9:8" Class="single"/>
        <Opcode Name="fldlg2" op="0xd9:8 0xec:8" Class="single"/>
        <Opcode Name="fldln2" op="0xd9:8 0xed:8" Class="single"/>
        <Opcode Name="fldpi" op="0xd9:8 0xeb:8" Class="single"/>
        <Opcode Name="fldz" op="0xd9:8 0xee:8" Class="single"/>
        <Opcode Name="fmul" op1="0xd8:8" mod="1" mod1="1" Class="floatmath"/>
        <Opcode Name="fmulp" op="0xde:8" mod="1" Class="floatmathp"/>
        <Opcode Name="fnop" op="0xd9:8 0xd0:8" Class="single"/>
        <Opcode Name="fnsave">
            <Operands Name="'rm:rm'" op="0xdd:8" mod="6"/>
        </Opcode>
        <Opcode Name="fpatan" op="0xd9:8 0xf3:8" Class="single"/>	
        <Opcode Name="fprem" op="0xd9:8 0xf8:8" Class="single"/>
        <Opcode Name="fprem1" op="0xd9:8 0xf5:8" Class="single"/>
        <Opcode Name="fptan" op="0xd9:8 0xf2:8" Class="single"/>	
        <Opcode Name="frndint" op="0xd9:8 0xfc:8" Class="single"/>	
        <Opcode Name="frstor">
            <Operands Name="'rm:rm'" op="0xdd:8" mod="4"/>
        </Opcode>
        <Opcode Name="fsave">
            <Operands Name="'rm:rm'" op="0x9b:8 0xdd:8" mod="6"/>
        </Opcode>
        <Opcode Name="fscale" op="0xd9:8 0xfd:8" Class="single"/>	
        <Opcode Name="fsetpm" op="0xdb:8 0xe4:8" Class="single"/>	
        <Opcode Name="fsin" op="0xd9:8 0xfe:8" Class="single"/>	
        <Opcode Name="fsincos" op="0xd9:8 0xfb:8" Class="single"/>	
        <Opcode Name="fsqrt" op="0xd9:8 0xfa:8" Class="single"/>	
        <Opcode Name="fst">
            <Operands Name="'reg:regfloat'" op="0xdd" mod="2"/>
            <Operands Name="dword 'rm:frm'" op="0xd9" mod="2" />
            <Operands Name="qword 'rm:frm'" op="0xdd" mod="2" />
        </Opcode>
        <Opcode Name="fstcw">
            <Operands Name="{word}'rm:rm'" op="0x9b:8 0xd9:8" mod="7"/>
        </Opcode>
        <Opcode Name="fnstcw">
            <Operands Name="{word}'rm:rm'" op="0xd9:8" mod="7"/>
        </Opcode>
        <Opcode Name="fstenv">
            <Operands Name="'rm:rm'" op="0x9b:8 0xd9:8" mod="6"/>
        </Opcode>
        <Opcode Name="fnstenv">
            <Operands Name="'rm:rm'" op="0xd9:8" mod="6"/>
        </Opcode>
        <Opcode Name="fstp">
            <Operands Name="'reg:regfloat'" op="0xdd" mod="3"/>
            <Operands Name="dword 'rm:frm'" op="0xd9" mod="3" />
            <Operands Name="qword 'rm:frm'" op="0xdd" mod="3" />
            <Operands Name="tword 'rm:frm'" op="0xdb" mod="7" />
        </Opcode>
        <Opcode Name="fstsw">
            <Operands Name="{word}'rm:rm'" op="0x9b:8 0xdd:8" mod="7"/>
            <Operands Name="ax" Coding="0x9b:8 0xdf:8 0xe0:8"/>
        </Opcode>
        <Opcode Name="fnstsw">
            <Operands Name="{word}'rm:rm'" op="0xdd:8" mod="7"/>
            <Operands Name="ax" Coding="0xdf:8 0xe0:8"/>
        </Opcode>
        <Opcode Name="fsub" op1="0xd8:8" mod="4" mod1="5" Class="floatmath"/>
        <Opcode Name="fsubp" op="0xde:8" mod="5" Class="floatmathp"/>
        <Opcode Name="fsubr" op1="0xd8:8" mod="5" mod1="4" Class="floatmath"/>
        <Opcode Name="fsubrp" op="0xde:8" mod="4" Class="floatmathp"/>
        <Opcode Name="ftst" op="0xd9:8 0xe4:8" Class="single"/>	
        <Opcode Name="fucom" op="0xdd" mod="4" Class="floatmathp"/>
        <Opcode Name="fucomp" op="0xdd" mod="5" Class="floatmathp"/>
        <Opcode Name="fucompp" op="0xda:8 0xe9:8" Class="single"/>	
        <Opcode Name="fwait" op="0x9b:8" Class="single"/>	
        <Opcode Name="fxam" op="0xd9:8 0xe5:8" Class="single"/>	
        <Opcode Name="fxch" op="0xd9" mod="1" Class="floatmathp"/>
        <Opcode Name="fxtract" op="0xd9:8 0xf4:8" Class="single"/>	
        <Opcode Name="fyl2x" op="0xd9:8 0xf1:8" Class="single"/>	
        <Opcode Name="fyl2xp1" op="0xd9:8 0xf9:8" Class="single"/>	
        <Opcode Name="hlt" op="0xf4:8" Class="single"/>	
        <Opcode Name="ibts" op="0xa7:8" Class="twobyte"/>	 
        <Opcode Name="idiv" mod="7" Class="sizedrm"/>
        <Opcode Name="imul" mod="5" Class="sizedrm">
            <Operands Name="'modreg:reg16', {word} 'rm:rm16', {byte} 'isigned:signed8'" op="'data16' 0x6b:8" mod="'modreg.Ord'" Coding="native 'isigned':8"/>
            <Operands Name="'modreg:reg16', {word} 'rm:rm16', 'omem:mem16'" op="'data16' 0x69:8" mod="'modreg.Ord'" Coding="native 'omem':16"/>
            <Operands Name="'modreg:reg16', {word} 'rm:rm16'" op="'data16' 0x0f:8 0xaf:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32', {byte} 'isigned:signed8'" op="'data32' 0x6b:8" mod="'modreg.Ord'" Coding="native 'isigned':8"/>
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32', 'omem:mem32'" op="'data32' 0x69:8" mod="'modreg.Ord'" Coding="native 'omem':32"/>
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32'" op="'data32' 0x0f:8 0xaf:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg16', {byte} 'signedimm:signed8'" Coding="'data16' 0x6b:8 0x3:2 'modreg.Ord':3 'modreg.Ord':3 'signedimm':8"/>
            <Operands Name="'modreg:reg16', {word} 'omem:mem16'" Coding="'data16' 0x69:8 0x3:2 'modreg.Ord':3 'modreg.Ord':3 'omem':16"/>
            <Operands Name="'modreg:reg32', {byte} 'signedimm:signed8'" Coding="'data32' 0x6b:8 0x3:2 'modreg.Ord':3 'modreg.Ord':3 'signedimm':8"/>
            <Operands Name="'modreg:reg32', {dword} 'omem:mem32'" Coding="'data32' 0x69:8 0x3:2 'modreg.Ord':3 'modreg.Ord':3 'omem':32"/>
        </Opcode>
        <Opcode Name="in">
            <Operands Name="al, {byte}'port:mem8'" Coding="0xe4:8 'port':8"/>
            <Operands Name="ax, {byte}'port:mem8'" Coding="'data16' 0xe5:8 'port':8"/>
            <Operands Name="eax, {byte}'port:mem8'" Coding="'data32' 0xe5:8 'port':8"/>
            <Operands Name="al, dx" Coding="0xec:8"/>
            <Operands Name="ax, dx" Coding="'data16' 0xed:8"/>
            <Operands Name="eax, dx" Coding="'data32' 0xed:8"/>
        </Opcode>
        <Opcode Name="ins">
            <Operands Name="byte es:[di],dx" Coding="'addr16' 0x0f:8 0x6c:8"/>
            <Operands Name="byte ['seg:segment':di],dx" Coding="'addr16' 'seg.Prefix':8 0x0f:8 0x6c:8"/>
            <Operands Name="byte es:[edi],dx" Coding="'addr32' 0x0f:8 0x6c:8"/>
            <Operands Name="byte ['seg:segment':edi],dx" Coding="'addr32' 'seg.Prefix':8 0x0f:8 0x6c:8"/>
            <Operands Name="word es:[di],dx" Coding="'data16' 'addr16' 0x0f:8 0x6d:8"/>
            <Operands Name="word ['seg:segment':di],dx" Coding="'data16' 'addr16' 'seg.Prefix':8 0x0f:8 0x6d:8"/>
            <Operands Name="word es:[edi],dx" Coding="'data16' 'addr32' 0x0f:8 0x6d:8"/>
            <Operands Name="word ['seg:segment':edi],dx" Coding="'data16' 'addr32' 'seg.Prefix':8 0x0f:8 0x6d:8"/>
            <Operands Name="dword es:[di],dx" Coding="'data32' 'addr16' 0x0f:8 0x6d:8"/>
            <Operands Name="dword ['seg:segment':di],dx" Coding="'data32' 'addr16' 'seg.Prefix':8 0x0f:8 0x6d:8"/>
            <Operands Name="dword es:[edi],dx" Coding="'data32' 'addr32' 0x0f:8 0x6d:8"/>
            <Operands Name="dword ['seg:segment':edi],dx" Coding="'data32' 'addr32' 'seg.Prefix':8 0x0f:8 0x6d:8"/>
        </Opcode>
        <Opcode Name="insb" op="0x6c:8" Class="twobyte"/>	
        <Opcode Name="insw" op="'data16' 0x6d:8" Class="twobyte"/>	
        <Opcode Name="insd" op="'data32' 0x6d:8" Class="twobyte"/>	
        <Opcode Name="inc" op="0x8" mod="0" Class="incdec"/>
        <Opcode Name="int">
            <Operands Name="{byte}'omem:mem8'" Coding="0xcd:8 'omem':8"/>
        </Opcode>
        <Opcode Name="int1" op="0xf1:8" Class="single"/>
        <Opcode Name="int3" op="0xcc:8" Class="single"/>
        <Opcode Name="into" op="0xce:8" Class="single"/>
        <Opcode Name="invd" op="0x8:8" Class="twobyte"/>
        <Opcode Name="invlpg">
            <Operands Name="'rm:rm'" op="0xf 1:8" mod= "7" />
        </Opcode>
        <Opcode Name="iret" op="0xcf" Class="single"/>
        <Opcode Name="iretw" op="'data16' 0xcf" Class="single"/>
        <Opcode Name="iretd" op="'data32' 0xcf" Class="single"/>
        <Opcode Name="ja" sel="7" Class="branch"/>
        <Opcode Name="jae" sel="3" Class="branch"/>
        <Opcode Name="jb" sel="2" Class="branch"/>
        <Opcode Name="jbe" sel="6" Class="branch"/>
        <Opcode Name="jc" sel="2" Class="branch"/>
        <Opcode Name="jcxz">
            <Operands Name="'rel:rel8n'" Coding="'addr16' 0xe3:8 'rel':8"/>
        </Opcode>	
        <Opcode Name="jecxz">
            <Operands Name="'rel:rel8n'" Coding="'addr32' 0xe3:8 'rel':8"/>
        </Opcode>	
        <Opcode Name="je" sel="4" Class="branch"/>
        <Opcode Name="jg" sel="0xf" Class="branch"/>
        <Opcode Name="jge" sel="0xd" Class="branch"/>
        <Opcode Name="jl" sel="0xc" Class="branch"/>
        <Opcode Name="jle" sel="0xe" Class="branch"/>
    
        <Opcode Name="jmp">
            <Operands Name="far 'seg:mem16':{word}'omem:address16'" Coding="'data16' 0xea:8 'omem':16 'seg':16"/>
            <Operands Name="far 'seg:mem16':{dword}'omem:address32'" Coding="'data32' 0xea:8 'omem':32 'seg':16"/>
            <Operands Name="far 'omem:address16'" Coding="0xf:8 0xf:8 'data16' 0xea:8 'omem':16 0:16"/>
            <Operands Name="far 'omem:address32'" Coding="0xf:8 0xf:8 'data32' 0xea:8 'omem':32 0:16"/>
            <Operands Name="far 'rm:rm16bit'" op= "'data16' 0xff:8" mod="5" />
            <Operands Name="far 'rm:rm32bit'" op= "'data32' 0xff:8" mod="5" />
            <Operands Name="short 'rel:rel8'" Coding="0xeb:8 'rel':8"/>
            <Operands Name="near 'rel:rel16jn'" Coding="'data16' 0xe9:8 'rel':16"/>
            <Operands Name="near 'rel:rel32'" Coding="'data32' 0xe9:8 'rel':32"/>
            <Operands Name="'rel:rel16j'" Coding="'data16' 0xe9:8 'rel':16"/>
            <Operands Name="'rel:rel32'" Coding="'data32' 0xe9:8 'rel':32"/>
            <Operands Name="'modreg:reg16rm'" op="'data16' 0xff:8" mod="4" />
            <Operands Name="'modreg:reg32rm'" op="'data32' 0xff:8" mod="4" />
            <Operands Name="{word} 'rm:rm16bit'" op="'data16' 0xff:8" mod="4" />
            <Operands Name="{dword} 'rm:rm32bit'" op="'data32' 0xff:8" mod="4" />
        </Opcode>
        <Opcode Name="jna" sel="6" Class="branch"/>
        <Opcode Name="jnae" sel="2" Class="branch"/>
        <Opcode Name="jnb" sel="3" Class="branch"/>
        <Opcode Name="jnbe" sel="7" Class="branch"/>
        <Opcode Name="jnc" sel="3" Class="branch"/>
        <Opcode Name="jne" sel="5" Class="branch"/>
        <Opcode Name="jng" sel="0xe" Class="branch"/>
        <Opcode Name="jnge" sel="0xc" Class="branch"/>
        <Opcode Name="jnl" sel="0xd" Class="branch"/>
        <Opcode Name="jnle" sel="0xf" Class="branch"/>
        <Opcode Name="jno" sel="1" Class="branch"/>
        <Opcode Name="jnp" sel="0xb" Class="branch"/>
        <Opcode Name="jns" sel="9" Class="branch"/>
        <Opcode Name="jnz" sel="5" Class="branch"/>
        <Opcode Name="jo" sel="0" Class="branch"/>
        <Opcode Name="jp" sel="0xa" Class="branch"/>
        <Opcode Name="jpe" sel="0xa" Class="branch"/>
        <Opcode Name="jpo" sel="0xb" Class="branch"/>
        <Opcode Name="js" sel="8" Class="branch"/>
        <Opcode Name="jz" sel="4" Class="branch"/>
        <Opcode Name="lahf" op="0x9f:8" Class="single"/>
        <Opcode Name="lar" op1="0x0f:8 0x2:8" Class="reg16rmx"/>
        <Opcode Name="lds" op1="0xc5:8" Class="reg16rmnrx"/>
        <Opcode Name="lea" op1="0x8d:8" Class="reg16rmnrx"/>
        <Opcode Name="leave" op="0xc9:8" Class="single"/>
        <Opcode Name="les" op1="0xc4:8" Class="reg16rmnrx"/>
        <Opcode Name="lfence" op="0x0f:8 0xae:8 0xe8:8" Class="single"/>
        <Opcode Name="lfs" op1="0x0f:8 0xb4:8" Class="reg16rmnrx"/>
        <Opcode Name="lgdt" op="0x0f:8 1:8" mod="2" Class="nostrictrm"/>
        <Opcode Name="lgs" op1="0x0f:8 0xb5:8" Class="reg16rmnrx"/>
        <Opcode Name="lidt" op="0x0f:8 1:8" mod="3" Class="nostrictrm"/>
        <Opcode Name="lmsw" op="0x0f:8 1:8" mod="6" Class="nostrictrm">
            <Operands Name="'reg:reg16rm'" op="'data16' 0x0f:8 1:8" mod="6"/>
            <Operands Name="'reg:reg32rm'" op="'data32' 0x0f:8 1:8" mod="6"/>
        </Opcode>
        <Opcode Name="lods">
            <Operands Name="byte [ds:si]" Coding="'addr16' 0xac:8"/>
            <Operands Name="byte ['seg:segment':si]" Coding="'addr16' 'seg.Prefix':8 0xac:8"/>
            <Operands Name="byte [ds:esi]" Coding="'addr32' 0xac:8"/>
            <Operands Name="byte ['seg:segment':esi]" Coding="'addr32' 'seg.Prefix':8 0xac:8"/>
            <Operands Name="word [ds:si]" Coding="'data16' 'addr16' 0xad:8"/>
            <Operands Name="word ['seg:segment':si]" Coding="'data16' 'addr16' 'seg.Prefix':8 0xad:8"/>
            <Operands Name="word [ds:esi]" Coding="'data16' 'addr32' 0xad:8"/>
            <Operands Name="word ['seg:segment':esi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0xad:8"/>
            <Operands Name="dword [ds:si]" Coding="'data32' 'addr16' 0xad:8"/>
            <Operands Name="dword ['seg:segment':si]" Coding="'data32' 'addr16' 'seg.Prefix':8 0xad:8"/>
            <Operands Name="dword [ds:esi]" Coding="'data32' 'addr32' 0xad:8"/>
            <Operands Name="dword ['seg:segment':esi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0xad:8"/>
        </Opcode>
        <Opcode Name="lodsb" op="0xac:8" Class="single"/>
        <Opcode Name="lodsw" op="'data16' 0xad:8" Class="single"/>
        <Opcode Name="lodsd" op="'data32' 0xad:8" Class="single"/>
        <Opcode Name="loop">
            <Operands Name="'rel:rel8n'" Coding="0xe2:8 'rel':8"/>
        </Opcode>
        <Opcode Name="loope">
            <Operands Name="'rel:rel8n'" Coding="0xe1:8 'rel':8"/>
        </Opcode>
        <Opcode Name="loopne">
            <Operands Name="'rel:rel8n'" Coding="0xe0:8 'rel':8"/>
        </Opcode>
        <Opcode Name="loopnz">
            <Operands Name="'rel:rel8n'" Coding="0xe0:8 'rel':8"/>
        </Opcode>
        <Opcode Name="loopz">
            <Operands Name="'rel:rel8n'" Coding="0xe1:8 'rel':8"/>
        </Opcode>
        <Opcode Name="lsl" op1="0x0f:8 0x03:8" Class="reg16rmx"/>
        <Opcode Name="lss" op1="0x0f:8 0xb2:8" Class="reg16rmnrx"/>
        <Opcode Name="ltr" op="0x0f:8 0:8" mod="3" Class="nostrictrm">
            <Operands Name="'reg:reg32rm'" op="0x0f:8 0:8" mod="3"/>
        </Opcode>
        <Opcode Name="mfence" op="0x0f:8 0xae:8 0xf0:8" Class="single"/>
        <Opcode Name="mov">
            <Operands Name="'creg:controlreg', 'modreg:reg32rm'" op="0xf:8 0x22:8" mod="'creg.Ord'" />
            <Operands Name="'dreg:debugreg', 'modreg:reg32rm'" op="0xf:8 0x23:8" mod="'dreg.Ord'" />
            <Operands Name="'treg:tracereg', 'modreg:reg32rm'" op="0xf:8 0x26:8" mod="'treg.Ord'" />
            <Operands Name="al, {byte}['omem:address16']" Coding="'addr16' 0xa0:8 'omem':16"/>
            <Operands Name="al, {byte}['seg:segment':'omem:address16']" Coding="'seg.Prefix':8 'addr16' 0xa0:8 'omem':16"/>
            <Operands Name="al, {byte}['omem:address32']" Coding="'addr32' 0xa0:8 'omem':32"/>
            <Operands Name="al, {byte}['seg:segment':'omem:address32']" Coding="'seg.Prefix':8 'addr32' 0xa0:8 'omem':32"/>
            <Operands Name="ax, {word}['omem:address16']" Coding="'data16' 'addr16' 0xa1:8 'omem':16"/>
            <Operands Name="ax, {word}['seg:segment':'omem:address16']" Coding="'seg.Prefix':8 'data16' 'addr16' 0xa1:8 'omem':16"/>
            <Operands Name="ax, {word}['omem:address32']" Coding="'data16' 'addr32' 0xa1:8 'omem':32"/>
            <Operands Name="ax, {word}['seg:segment':'omem:address32']" Coding="'seg.Prefix':8 'data16' 'addr32' 0xa1:8 'omem':32"/>
            <Operands Name="eax, {dword}['omem:address16']" Coding="'data32' 'addr16' 0xa1:8 'omem':16"/>
            <Operands Name="eax, {dword}['seg:segment':'omem:address16']" Coding="'seg.Prefix':8 'data32' 'addr16' 0xa1:8 'omem':16"/>
            <Operands Name="eax, {dword}['omem:address32']" Coding="'data32' 'addr32' 0xa1:8 'omem':32"/>
            <Operands Name="eax, {dword}['seg:segment':'omem:address32']" Coding="'seg.Prefix':8 'data32' 'addr32' 0xa1:8 'omem':32"/>
            <Operands Name="'modreg:reg8', {byte}'omem:mem8'" Coding="0x16:5 'modreg.Ord':3 'omem':8"/>
            <Operands Name="'modreg:reg16', {word} 'omem:mem16'" Coding="'data16' 0x17:5 'modreg.Ord':3 'omem':16"/>
            <Operands Name="'modreg:reg32', {dword} 'omem:mem32'" Coding="'data32' 0x17:5 'modreg.Ord':3 'omem':32"/>
            <Operands Name="'modreg:reg8', {byte} 'rm:rm8'" op="0x8a:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg16', {word} 'rm:rm16'" op="'data16' 0x8b:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword} 'rm:rm32'" op="'data32' 0x8b:8" mod="'modreg.Ord'" />
            <Operands Name="byte 'rm:rm8', {byte}'omem:mem8'" op="0xc6:8" mod="0" Coding="native 'omem':8"/>
            <Operands Name="word 'rm:rm16', {word}'omem:mem16'" op="'data16' 0xc7:8" mod="0" Coding="native 'omem':16"/>
            <Operands Name="dword 'rm:rm32', {dword}'omem:mem32'" op="'data32' 0xc7:8" mod="0" Coding="native 'omem':32"/>
            <Operands Name="'modreg:reg32rm', 'creg:controlreg'" op="0xf:8 0x20:8" mod="'creg.Ord'" />
            <Operands Name="'modreg:reg32rm', 'dreg:debugreg'" op="0xf:8 0x21:8" mod="'dreg.Ord'" />
            <Operands Name="'modreg:reg32rm', 'treg:tracereg'" op="0xf:8 0x24:8" mod="'treg.Ord'" />
            <Operands Name="{byte} ['omem:address16'],al" Coding="'addr16' 0xa2:8 'omem':16"/>
            <Operands Name="{byte} ['seg:segment':'omem:address16'],al" Coding="'seg.Prefix':8 'addr16' 0xa2:8 'omem':16"/>
            <Operands Name="{byte} ['omem:address32'],al" Coding="'addr32' 0xa2:8 'omem':32"/>
            <Operands Name="{byte} ['seg:segment':'omem:address32'],al" Coding="'seg.Prefix':8 'addr32' 0xa2:8 'omem':32"/>
            <Operands Name="{word} ['omem:address16'],ax" Coding="'data16' 'addr16' 0xa3:8 'omem':16"/>
            <Operands Name="{word} ['seg:segment':'omem:address16'],ax" Coding="'seg.Prefix':8 'data16' 'addr16' 0xa3:8 'omem':16"/>
            <Operands Name="{word} ['omem:address32'],ax" Coding="'data16' 'addr32' 0xa3:8 'omem':32"/>
            <Operands Name="{word} ['seg:segment':'omem:address32'],ax" Coding="'seg.Prefix':8 'data16' 'addr32' 0xa3:8 'omem':32"/>
            <Operands Name="{dword} ['omem:address16'],eax" Coding="'data32' 'addr16' 0xa3:8 'omem':16"/>
            <Operands Name="{dword} ['seg:segment':'omem:address16'],eax" Coding="'seg.Prefix':8 'data32' 'addr16' 0xa3:8 'omem':16"/>
            <Operands Name="{dword} ['omem:address32'],eax" Coding="'data32' 'addr32' 0xa3:8 'omem':32"/>
            <Operands Name="{dword} ['seg:segment':'omem:address32'],eax" Coding="'seg.Prefix':8 'data32' 'addr32' 0xa3:8 'omem':32"/>
            <Operands Name="{byte} 'rm:rm8', 'modreg:reg8'" op="0x88:8" mod="'modreg.Ord'" />
            <Operands Name="{word} 'rm:rm16', 'modreg:reg16'" op="'data16' 0x89:8" mod="'modreg.Ord'" />
            <Operands Name="{dword} 'rm:rm32', 'modreg:reg32'" op="'data32' 0x89:8" mod="'modreg.Ord'" />
            <Operands Name="'segm:segment',{word} 'rm:rm16'" op="0x8e:8" mod="'segm.Ord'" />
            <Operands Name="'segm:segment',{dword} 'modreg:reg32rm'" op="0x8e:8" mod="'segm.Ord'" />
            <Operands Name="{word} 'rm:rm16','segm:segment'" op="0x8c:8" mod="'segm.Ord'" />
            <Operands Name="{dword} 'modreg:reg32rm','segm:segment'" op="0x8c:8" mod="'segm.Ord'" />
            <Operands Name="'rm:reg8rm', {byte}'omem:mem8'" op="0xc6:8" mod="0" Coding="native 'omem':8"/>
            <Operands Name="'rm:reg16rm', {word}'omem:mem16'" op="'data16' 0xc7:8" mod="0" Coding="native 'omem':16"/>
            <Operands Name="'rm:reg32rm', {dword}'omem:mem32'" op="'data32' 0xc7:8" mod="0" Coding="native 'omem':32"/>
        </Opcode>
        <Opcode Name="movs">
            <Operands Name="byte es:[di], byte [ds:si]" Coding="'addr16' 0xa4:8"/>
            <Operands Name="byte es:[di], byte ['seg:segment':si]" Coding="'addr16' 'seg.Prefix':8 0xa4:8"/>
            <Operands Name="byte es:[edi], byte [ds:esi]" Coding="'addr32' 0xa4:8"/>
            <Operands Name="byte es:[edi], byte ['seg:segment':esi]" Coding="'addr32' 'seg.Prefix':8 0xa4:8"/>
            <Operands Name="word es:[di], word [ds:si]" Coding="'data16' 'addr16' 0xa5:8"/>
            <Operands Name="word es:[di], word ['seg:segment':si]" Coding="'data16' 'addr16' 'seg.Prefix':8 0xa5:8"/>
            <Operands Name="word es:[edi], word [ds:esi]" Coding="'data16' 'addr32' 0xa5:8"/>
            <Operands Name="word es:[edi], word ['seg:segment':esi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0xa5:8"/>
            <Operands Name="dword es:[di], dword [ds:si]" Coding="'data32' 'addr16' 0xa5:8"/>
            <Operands Name="dword es:[di], dword ['seg:segment':si]" Coding="'data32' 'addr16' 'seg.Prefix':8 0xa5:8"/>
            <Operands Name="dword es:[edi], dword [ds:esi]" Coding="'data32' 'addr32' 0xa5:8"/>
            <Operands Name="dword es:[edi], dword ['seg:segment':esi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0xa5:8"/>
        </Opcode>
        <Opcode Name="movsb" op="0xa4:8" Class="single"/>
        <Opcode Name="movsw" op="'data16' 0xa5:8" Class="single"/>
        <Opcode Name="movsd" op="'data32' 0xa5:8" Class="single"/>
        <Opcode Name="movsx" op1="0xbe" Class="movx"/>
        <Opcode Name="movzx" op1="0xb6" Class="movx"/>
        <Opcode Name="mul" mod="4" Class="sizedrm"/>
        <Opcode Name="neg" mod="3" Class="sizedrm"/>
        <Opcode Name="nop" op="0x90:8" Class="single"/>
        <Opcode Name="not" mod="2" Class="sizedrm"/>
        <Opcode Name="or"  op1="0x0c:8" op2="0x08" mod="1" Class="math"/>
        <Opcode Name="out">
            <Operands Name="{byte}'port:mem8',al" Coding="0xe6:8 'port':8"/>
            <Operands Name="{byte}'port:mem8',ax" Coding="'data16' 0xe7:8 'port':8"/>
            <Operands Name="{byte}'port:mem8',eax" Coding="'data32' 0xe7:8 'port':8"/>
            <Operands Name="dx,al" Coding="0xee:8"/>
            <Operands Name="dx,ax" Coding="'data16' 0xef:8"/>
            <Operands Name="dx,eax" Coding="'data32' 0xef:8"/>
        </Opcode>
        <Opcode Name="outs">	
            <Operands Name="dx,byte [ds:si]" Coding="'addr16'  0x0f:8 0x6e:8"/>
            <Operands Name="dx,byte ['seg:segment':si]" Coding="'addr16' 'seg.Prefix':8 0x0f:8 0x6e:8"/>
            <Operands Name="dx,byte [ds:esi]" Coding="'addr32' 0x0f:8 0x6e:8"/>
            <Operands Name="dx,byte ['seg:segment':esi]" Coding="'addr32' 'seg.Prefix':8 0x0f:8 0x6e:8"/>
            <Operands Name="dx,word [ds:si]" Coding="'data16' 'addr16' 0x0f:8 0x6f:8"/>
            <Operands Name="dx,word ['seg:segment':si]" Coding="'data16' 'addr16' 'seg.Prefix':8 0x0f:8 0x6f:8"/>
            <Operands Name="dx,word [ds:esi]" Coding="'data16' 'addr32' 0x0f:8 0x6f:8"/>
            <Operands Name="dx,word ['seg:segment':esi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0x0f:8 0x6f:8"/>
            <Operands Name="dx,dword [ds:si]" Coding="'data32' 'addr16' 0x0f:8 0x6f:8"/>
            <Operands Name="dx,dword ['seg:segment':si]" Coding="'data32' 'addr16' 'seg.Prefix':8 0x0f:8 0x6f:8"/>
            <Operands Name="dx,dword [ds:esi]" Coding="'data32' 'addr32' 0x0f:8 0x6f:8"/>
            <Operands Name="dx,dword ['seg:segment':esi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0x0f:8 0x6f:8"/>
        </Opcode>
        <Opcode Name="outsb" op="0x6e:8" Class="twobyte"/>	
        <Opcode Name="outsw" op="'data16' 0x6f:8" Class="twobyte"/>	
        <Opcode Name="outsd" op="'data32' 0x6f:8" Class="twobyte"/>	
        <Opcode Name="pop">
            <Operands Name="'modreg:reg16'" Coding="'data16' 0xb:5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg32'" Coding="'data32' 0xb:5 'modreg.Ord':3"/>
            <Operands Name="word 'rm:rm16'" op="'data16' 0x8f:8" mod="0" />
            <Operands Name="dword 'rm:rm32'" op="'data32' 0x8f:8" mod="0" />
            <Operands Name="fs" Coding="0x0f:8 0xa1:8"/>
            <Operands Name="gs" Coding="0x0f:8 0xa9:8"/>
            <Operands Name="'seg:segment'" Coding="0:2 'seg.Ord':3 7:3"/>
        </Opcode>
        <Opcode Name="popa" op="0x61:8" Class="single"/>
        <Opcode Name="popaw" op="'data16' 0x61:8" Class="single"/>
        <Opcode Name="popad" op="'data32' 0x61:8" Class="single"/>
        <Opcode Name="popf" op="0x9d:8" Class="single"/>
        <Opcode Name="popfw" op="'data16' 0x9d:8" Class="single"/>
        <Opcode Name="popfd" op="'data32' 0x9d:8" Class="single"/>
        <Opcode Name="push">
            <Operands Name="'modreg:reg16'" Coding="'data16' 0xa:5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg32'" Coding="'data32' 0xa:5 'modreg.Ord':3"/>
            <Operands Name="{byte} 'omem:signed8'" Coding="0x6a:8 'omem':8"/>
            <Operands Name="'omem:address16'" Coding="'data16' 0x68:8 'omem':16"/>
            <Operands Name="'omem:address32'" Coding="'data32' 0x68:8 'omem':32"/>
            <Operands Name="word 'omem:mem16'" Coding="'data16' 0x68:8 'omem':16"/>
            <Operands Name="dword 'omem:mem32'" Coding="'data32' 0x68:8 'omem':32"/>
            <Operands Name="word 'rm:rm16'" op="0xff:8" mod="6" Coding="'data16' native"/>
            <Operands Name="dword 'rm:rm32'" op="0xff:8" mod="6" Coding="'data32' native"/>
            <Operands Name="fs" Coding="0x0f:8 0xa0:8"/>
            <Operands Name="gs" Coding="0x0f:8 0xa8:8"/>
            <Operands Name="'seg:segment'" Coding="0:2 'seg.Ord':3 6:3"/>
        </Opcode>
        <Opcode Name="pusha" op="0x60:8" Class="single"/>
        <Opcode Name="pushaw" op="'data16' 0x60:8" Class="single"/>
        <Opcode Name="pushad" op="'data32' 0x60:8" Class="single"/>
        <Opcode Name="pushf" op="0x9c:8" Class="single"/>
        <Opcode Name="pushfw" op="'data16' 0x9c:8" Class="single"/>
        <Opcode Name="pushfd" op="'data32' 0x9c:8" Class="single"/>
        <Opcode Name="rcl" mod="2" Class="shift"/>
        <Opcode Name="rcr" mod="3" Class="shift"/>
        <Opcode Name="rdmsr" op="0x32:8" Class="twobyte"/>
        <Opcode Name="rdpmc" op="0x33:8" Class="twobyte"/>
        <Opcode Name="rdtsc" op="0x31:8" Class="twobyte"/>
        <Opcode Name="ret">
            <Operands Name="'omem:mem16'" Coding="0xc2:8 'omem':16"/>
            <Operands Name="empty" Coding="0xc3:8"/>
        </Opcode>
        <Opcode Name="retf">
            <Operands Name="'omem:mem16'" Coding="0xca:8 'omem':16"/>
            <Operands Name="empty" Coding="0xcb:8"/>
        </Opcode>
        <Opcode Name="rol" mod="0" Class="shift"/>
        <Opcode Name="ror" mod="1" Class="shift"/>
        <Opcode Name="rsm" op="0xaa:8" Class="twobyte"/>
        <Opcode Name="sahf" op="0x9e:8" Class="single"/>
        <Opcode Name="sal" mod="4" Class="shift"/>
        <Opcode Name="sar" mod="7" Class="shift"/>
        <Opcode Name="sbb" op1="0x1c:8" op2="0x18" mod="3" Class="math"/>
        <Opcode Name="scas">
            <Operands Name="byte es:[di]" Coding="'addr16' 0xae:8"/>
            <Operands Name="byte ['seg:segment':di]" Coding="'addr16' 'seg.Prefix':8 0xae:8"/>
            <Operands Name="byte es:[edi]" Coding="'addr32' 0xae:8"/>
            <Operands Name="byte ['seg:segment':edi]" Coding="'addr32' 'seg.Prefix':8 0xae:8"/>
            <Operands Name="word es:[di]" Coding="'data16' 'addr16' 0xaf:8"/>
            <Operands Name="word ['seg:segment':di]" Coding="'data16' 'addr16' 'seg.Prefix':8 0xaf:8"/>
            <Operands Name="word es:[edi]" Coding="'data16' 'addr32' 0xaf:8"/>
            <Operands Name="word ['seg:segment':edi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0xaf:8"/>
            <Operands Name="dword es:[di]" Coding="'data32' 'addr16' 0xaf:8"/>
            <Operands Name="dword ['seg:segment':di]" Coding="'data32' 'addr16' 'seg.Prefix':8 0xaf:8"/>
            <Operands Name="dword es:[edi]" Coding="'data32' 'addr32' 0xaf:8"/>
            <Operands Name="dword ['seg:segment':edi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0xaf:8"/>
        </Opcode>
        <Opcode Name="scasb" op="0xae:8" Class="single"/>
        <Opcode Name="scasw" op="'data16' 0xaf:8" Class="single"/>
        <Opcode Name="scasd" op="'data32' 0xaf:8" Class="single"/>
        <Opcode Name="seta" sel="7" Class="set"/>
        <Opcode Name="setae" sel="3" Class="set"/>
        <Opcode Name="setb" sel="2" Class="set"/>
        <Opcode Name="setbe" sel="6" Class="set"/>
        <Opcode Name="setc" sel="2" Class="set"/>
        <Opcode Name="sete" sel="4" Class="set"/>
        <Opcode Name="setg" sel="0xf" Class="set"/>
        <Opcode Name="setge" sel="0xd" Class="set"/>
        <Opcode Name="setl" sel="0xc" Class="set"/>
        <Opcode Name="setle" sel="0xe" Class="set"/>
        <Opcode Name="setna" sel="6" Class="set"/>
        <Opcode Name="setnae" sel="2" Class="set"/>
        <Opcode Name="setnb" sel="3" Class="set"/>
        <Opcode Name="setnbe" sel="7" Class="set"/>
        <Opcode Name="setnc" sel="3" Class="set"/>
        <Opcode Name="setne" sel="5" Class="set"/>
        <Opcode Name="setng" sel="0xe" Class="set"/>
        <Opcode Name="setnge" sel="0xc" Class="set"/>
        <Opcode Name="setnl" sel="0xd" Class="set"/>
        <Opcode Name="setnle" sel="0xf" Class="set"/>
        <Opcode Name="setno" sel="1" Class="set"/>
        <Opcode Name="setnp" sel="0xb" Class="set"/>
        <Opcode Name="setns" sel="9" Class="set"/>
        <Opcode Name="setnz" sel="5" Class="set"/>
        <Opcode Name="seto" sel="0" Class="set"/>
        <Opcode Name="setp" sel="0xa" Class="set"/>
        <Opcode Name="setpe" sel="0xa" Class="set"/>
        <Opcode Name="setpo" sel="0xb" Class="set"/>
        <Opcode Name="sets" sel="8" Class="set"/>
        <Opcode Name="setz" sel="4" Class="set"/>
        <Opcode Name="sfence" op="0x0f:8 0xae:8 0xf8:8" Class="single"/>
        <Opcode Name="shl" mod="4" Class="shift"/>
        <Opcode Name="shld" op1="0xa4" Class="regshift"/>
        <Opcode Name="shr" mod="5" Class="shift"/>
        <Opcode Name="shrd" op1="0xac" Class="regshift"/>
        <Opcode Name="sidt" op="0x0f:8 1:8" mod="1" Class="nostrictrm"/>
        <Opcode Name="sldt" op="0x0f:8 0:8" mod="0" Class="nostrictrm"/>
        <Opcode Name="smsw" op="0x0f:8 1:8" mod="4" Class="nostrictrm">
            <Operands Name="'reg:reg16rm'" op="'data16' 0x0f:8 1:8" mod="4"/>
            <Operands Name="'reg:reg32rm'" op="'data32' 0x0f:8 1:8" mod="4"/>
        </Opcode>
        <Opcode Name="stc" op="0xf9:8" Class="single"/>
        <Opcode Name="std" op="0xfd:8" Class="single"/>
        <Opcode Name="sti" op="0xfb:8" Class="single"/>
        <Opcode Name="stos">
            <Operands Name="byte es:[di]" Coding="'addr16' 0xaa:8"/>
            <Operands Name="byte ['seg:segment':di]" Coding="'addr16' 'seg.Prefix':8 0xaa:8"/>
            <Operands Name="byte es:[edi]" Coding="'addr32' 0xaa:8"/>
            <Operands Name="byte ['seg:segment':edi]" Coding="'addr32' 'seg.Prefix':8 0xaa:8"/>
            <Operands Name="word es:[di]" Coding="'data16' 'addr16' 0xab:8"/>
            <Operands Name="word ['seg:segment':di]" Coding="'data16' 'addr16' 'seg.Prefix':8 0xab:8"/>
            <Operands Name="word es:[edi]" Coding="'data16' 'addr32' 0xab:8"/>
            <Operands Name="word ['seg:segment':edi]" Coding="'data16' 'addr32' 'seg.Prefix':8 0xab:8"/>
            <Operands Name="dword es:[di]" Coding="'data32' 'addr16' 0xab:8"/>
            <Operands Name="dword ['seg:segment':di]" Coding="'data32' 'addr16' 'seg.Prefix':8 0xab:8"/>
            <Operands Name="dword es:[edi]" Coding="'data32' 'addr32' 0xab:8"/>
            <Operands Name="dword ['seg:segment':edi]" Coding="'data32' 'addr32' 'seg.Prefix':8 0xab:8"/>
        </Opcode>
        <Opcode Name="stosb" op="0xaa:8" Class="single"/>
        <Opcode Name="stosw" op="'data16' 0xab:8" Class="single"/>
        <Opcode Name="stosd" op="'data32' 0xab:8" Class="single"/>
        <Opcode Name="str" op="0x0f:8 0:8" mod="1" Class="nostrictrm">
            <Operands Name="'reg:reg16rm'" op="'data16' 0x0f:8 0:8" mod="1"/>
            <Operands Name="'reg:reg32rm'" op="'data32' 0x0f:8 0:8" mod="1"/>
        </Opcode>	
        <Opcode Name="sub" op1="0x2c:8" op2="0x28" mod="5" Class="math"/>
        <Opcode Name="test">
            <Operands Name="al, {byte} 'omem:mem8'" Coding="0xa8:8 'omem':8"/>
            <Operands Name="ax, {word} 'omem:mem16'" Coding="'data16' 0xa9:8 'omem':16"/>
            <Operands Name="eax, {dword} 'omem:mem32'" Coding="'data32' 0xa9:8 'omem':32"/>
            <Operands Name="{byte}'rm:rm8', 'modreg:reg8'" op="0x84:8" mod="'modreg.Ord'" />
            <Operands Name="{word}'rm:rm16', 'modreg:reg16'" op="'data16' 0x85:8" mod="'modreg.Ord'" />
            <Operands Name="{dword}'rm:rm32', 'modreg:reg32'" op="'data32' 0x85:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg8', {byte}'rm:rm8'" op="0x84:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg16', {word}'rm:rm16'" op="'data16' 0x85:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword}'rm:rm32'" op="'data32' 0x85:8" mod="'modreg.Ord'" />
            <Operands Name="'rm:reg8rm', 'omem:mem8'" op="0xf6:8" mod="0" Coding="native 'omem':8"/>
            <Operands Name="'rm:reg16rm', 'omem:mem16'" op="'data16' 0xf7:8" mod="0" Coding="native 'omem':16"/>
            <Operands Name="'rm:reg32rm', 'omem:mem32'" op="'data32' 0xf7:8" mod="0" Coding="native 'omem':32"/>
            <Operands Name="byte 'rm:rm8', 'omem:mem8'" op="0xf6:8" mod="0" Coding="native 'omem':8"/>
            <Operands Name="word 'rm:rm16', 'omem:mem16'" op="'data16' 0xf7:8" mod="0" Coding="native 'omem':16"/>
            <Operands Name="dword 'rm:rm32', 'omem:mem32'" op="'data32' 0xf7:8" mod="0" Coding="native 'omem':32"/>
        </Opcode>
        <Opcode Name="ud2" op="0x0b:8" Class="twobyte"/>
        <Opcode Name="verr" op="0x0f:8 0:8" mod="4" Class="nostrictrm">
            <Operands Name="'reg:reg16rm'" op="'data16' 0x0f:8 0:8" mod="4"/>
            <Operands Name="'reg:reg32rm'" op="'data32' 0x0f:8 0:8" mod="4"/>
        </Opcode>	
        <Opcode Name="verw" op="0x0f:8 0:8" mod="5" Class="nostrictrm">
            <Operands Name="'reg:reg16rm'" op="'data16' 0x0f:8 0:8" mod="5"/>
            <Operands Name="'reg:reg32rm'" op="'data32' 0x0f:8 0:8" mod="5"/>
        </Opcode>	
        <Opcode Name="wait" op="0x9b:8" Class="single"/>
        <Opcode Name="wbinvd" op="0x09:8" Class="twobyte"/>
        <Opcode Name="wrmsr" op="0x30:8" Class="twobyte"/>
        <Opcode Name="xadd">
            <Operands Name="{byte} 'rm:rm8','modreg:reg8'" op="0x0f:8 0xc0:8" mod="'modreg.Ord'" />
        </Opcode>
    
        <Opcode Name="xbts">
            <Operands Name="'modreg:reg16',{word}'rm:rm16'" op="'data16' 0x0f:8 0xa6:8" mod="'modreg.Ord'"/>
            <Operands Name="'modreg:reg32',{dword}'rm:rm32'" op="'data32' 0x0f:8 0xa6:8" mod="'modreg.Ord'"/>
        </Opcode>
        <Opcode Name="xchg">
            <Operands Name="ax, 'modreg:reg16'" Coding="'data16' 0x12:5 'modreg.Ord':3"/>
            <Operands Name="eax, 'modreg:reg32'" Coding="'data32' 0x12:5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg16', ax" Coding="'data16' 0x12:5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg32', eax" Coding="'data32' 0x12:5 'modreg.Ord':3"/>
            <Operands Name="'modreg:reg8', {byte}'rm:rm8'" op="0x86:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg16', {word}'rm:rm16'" op="'data16' 0x87:8" mod="'modreg.Ord'" />
            <Operands Name="'modreg:reg32', {dword}'rm:rm32'" op="'data32' 0x87:8" mod="'modreg.Ord'" />
            <Operands Name="{byte}'rm:rm8', 'modreg:reg8'" op="0x86:8" mod="'modreg.Ord'" />
            <Operands Name="{word}'rm:rm16', 'modreg:reg16'" op="'data16' 0x87:8" mod="'modreg.Ord'" />
            <Operands Name="{dword}'rm:rm32', 'modreg:reg32'" op="'data32' 0x87:8" mod="'modreg.Ord'" />
        </Opcode>
        <Opcode Name="xlat" >
            <Operands Name="{byte}[ds:bx]" Coding="'addr16' 0xd7:8"/>
            <Operands Name="{byte}['seg:segment':bx]" Coding="'addr16' 'seg.Prefix' 0xd7:8"/>
            <Operands Name="{byte}[ds:ebx]" Coding="'addr32' 0xd7:8"/>
            <Operands Name="{byte}['seg:segment':ebx]" Coding="'addr32' 'seg.Prefix' 0xd7:8"/>
            <Operands Name="empty" Coding="0xd7:8"/>
        </Opcode>
        <Opcode Name="xlatb" op="0xd7:8" Class="single"/>
        <Opcode Name="xor" op1="0x34:8" op2="0x30" mod="6" Class="math"/>
        <Prefix Name="a16" Coding="'addr16'"/>
        <Prefix Name="a32" Coding="'addr32'"/>
        <Prefix Name="lock" Coding="0xf0:8"/>
        <Prefix Name="o16" Coding="'data16'"/>
        <Prefix Name="o32" Coding="'data32'"/>
        <Prefix Name="rep" Coding="0xf3:8"/>
        <Prefix Name="repe" Coding="0xf3:8"/>
        <Prefix Name="repne" Coding="0xf2:8"/>
        <Prefix Name="repnz" Coding="0xf2:8"/>
        <Prefix Name="repz" Coding="0xf3:8"/>
    </Coding>
    <Compiling Profile="bit32">
        <General>
            <Instance Name="GenStackAlign" Value="1"/>
            <Instance Name="StandardNames" Value="1"/>
            <Instance Name="compatibleint" Value="long"/>
            <Instance Name="compatibleaddress" Value="long"/>
            <Instance Name="defaultpacking" Value="8"/>
            <Instance Name="optimize" Value="all" commandline="1"/>
            <Instance Name="denyoptimize" Value="0"/>
            <Instance Name="reversebits" Value="0"/>
            <Instance Name="framesize" Value="8"/>
            <Instance Name="minparamwidth" Value="4"/>
            <Instance Name="minalignment" Value="4"/>
        </General>
        <Sizes>
            <Instance Name="bool" size="1" align="1"/>
            <Instance Name="char" size="1" align="1"/>
            <Instance Name="short" size="2" align="2"/>
            <Instance Name="int" size="4" align="4"/>
            <Instance Name="long" size="4" align="4"/>
            <Instance Name="longlong" size="8" align="8"/>
            <Instance Name="address" size="4" align="4"/>
            <Instance Name="faraddress" size="6" align="4"/>
            <Instance Name="segment" size="2" align="2"/>
            <Instance Name="float" size="4" align="4"/>
            <Instance Name="double" size="8" align="8"/>
            <Instance Name="longdouble" size="12" align="12"/>
            <Instance Name="complexfloat" size="8" align="4"/>
            <Instance Name="complexdouble" size="16" align="8"/>
            <Instance Name="complexlongdouble" size="24" align="8"/>
        </Sizes>
        <Floating>
            <Instance Name="float" min="-126" bias="126" max="128" mantissa_bits="24"/>
            <Instance Name="double" min="-1022" bias="1022" max="1024" mantissa_bits="54"/>
            <Instance Name="longdouble" min="-16382" bias="16382" max="16384" mantissa_bits="65"/>
        </Floating>
        <Assembler Profile="nasm">
            <Usage>
            </Usage>
            <Params>
                <Instance Name="hosted" Value="1"/>
                <Instance Name="extension" Value=".asm"/>
                <Instance Name="objextenstion" Value=".o"/>
                <Instance Name="envname" Value="OCC"/>
                <Instance Name="progname" Value="OCC"/>
                <Instance Name="cfgname" Value="occ.cfg"/>
                <Instance Name="debugger" profile=""/>
            </Params>
            <Arguments>
            </Arguments>
            <Defines>
            </Defines>
        </Assembler>
    void (*internalConflict)(QUAD *q) ; /* enter a conflict for this instruction if necessary */
    void (*align)(int size);            /* put an alignment command */
    IMODE *(*handleIntrins)(EXPRESSION *node, int novalue);  /* backend handle intrinsic */
        <Gen>
            <Intrinsics>
                <Instance Name="__LXMUL"/>
                <Instance Name="__LXIDIV"/>
                <Instance Name="__LXUDIV"/>
                <Instance Name="__LXIMOD"/>
                <Instance Name="__LXUMOD"/>
            </Intrinsics>
            <Code Name="line">
            </Code>
            <Code Name="passthrough">
            </Code>
            <Code Name="datapassthrough">
            </Code>
            <Code Name="label">
            </Code>
            <Code Name="goto">
            </Code>
            <Code Name="gosub">
    call %op[0]%
            </Code>
            <Code Name="fargosub">
            </Code>
            <Code Name="trap">
            </Code>
            <Code Name="int">
    int	%op[0]%
            </Code>
            <Code Name="ret">
                <When Cond="opcount==0">
    ret
                </When>
                <When Cond="opcount==1&amp;&amp;isscalar(op[0])">
    ret	%op[0]%
                </When>
            </Code>
            <Code Name="fret">
                <When Cond="opcount==0">
    retf
                </When>
                <When Cond="opcount==1&amp;&amp;isscalar(op[0])">
    retf	%op[0]%
                </When>
            </Code>
            <Code Name="rett">
    iret
            </Code>
            <Code Class="math">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result==op[0]">
    %op1% %result.low%,%op[1].low%
    %op2% %result.high%,%op[1].high%
                        </When>
                        <When Cond="result==op[1]&amp;&amp;op[0]!=op[1]">
    %op1% %result.low%,%op[0].low%
    %op2% %result.high%,%op[0].high%
                        </When>
                        <Otherwise>
    mov %result.low%,%op[0].low%
    mov %result.high%,%op[0].high%
    %op1% %result.low%,%op[1].low%
    %op2% %result.high%,%op[1].high%
                        </Otherwise>
                    </When>
                    <Otherwise>
    
                        <When Cond="result==op[0]">
    %op1% %result%,%op[1]%
                        </When>
                        <When Cond="result==op[1]&amp;&amp;op[0]!=op[1]">
    %op1% %result%,%op[0]%
                        </When>
                        <Otherwise>
    mov %result%,%op[0]%
    %op1% %result$,%op[1]%
                        </Otherwise>
                    </Otherwise>
                </When>
                <When Cond="isfloat(result)">
                    <When Cond="!istemp(op[0])">
                        <When Cond="op[0]==1.0">
    fld1
                        </When>
                        <When Cond="op[0]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[0]%
                        </Otherwise>
                    </When>
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
                    </When>
                    <When Cond="istemp(op[0]) &amp;&amp; op[0]==op[1]">
    fld st0
                    </When>
    %op2% st1
                    <When Cond="!istemp(result)">
    fstp %result%
                    </When>
                </When>
            </Code>
            <Code Name="add" op1="add" op2="adc" op3="faddp" Class="math"/>
            <Code Name="sub" op1="sub" op2="sbb" op3="fsubp" Class="math">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result==op[0]">
    %op1% %result.low%,%op[1].low%
    %op2% %result.high%,%op[1].high%
                        </When>
                        <Otherwise>
    mov %result.low%,%op[0].low%
    mov %result.high%,%op[0].high%
    %op1% %result.low%,%op[1].low%
    %op2% %result.high%,%op[1].high%
                        </Otherwise>
                    </When>
                    <Otherwise>
                        <When Cond="result==op[0]">
    %op1% %result%,%op[1]%
                        </When>
                        <When Cond="result==op[1]&amp;&amp;op[0]!=op[1]">
    %op1% %result%,%op[0]%
    neg	  %result%
                        </When>
                        <Otherwise>
    mov %result%,%op[0]%
    %op1% %result$,%op[1]%
                        </Otherwise>
                    </Otherwise>
                </When>
                <When Cond="isfloat(result)">
                    <When Cond="!istemp(op[0])">
                        <When Cond="op[0]==1.0">
    fld1
                        </When>
                        <When Cond="op[0]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[0]%
                        </Otherwise>
                    </When>
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
                    </When>
                    <When Cond="istemp(op[0]) &amp;&amp; op[0]==op[1]">
    fld st0
                    </When>
    %op2% st1
                    <When Cond="!istemp(result)">
    fstp %result%
                    </When>
                </When>
            </Code>
            <Code Name="udiv">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
    push %op[1].high%
    push %op[1].low%
    push %op[0].high%
    push %op[0].low%
    call __LXUDIV
                    </When>
                    <Otherwise>
    div %op[1]%
                    </Otherwise>
                </When>
                <When Cond="isfloat(result)">
                    <When Cond="!istemp(op[0])">
                        <When Cond="op[0]==1.0">
    fld1
                        </When>
                        <When Cond="op[0]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[0]%
                        </Otherwise>
                    </When>
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
                    </When>
                    <When Cond="istemp(op[0]) &amp;&amp; op[0]==op[1]">
    fld st0
                    </When>
    fdivp st1
                    <When Cond="!istemp(result)">
    fstp %result%
                    </When>
                </When>
                
            </Code>
            <Code Name="umod">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
    push %op[1].high%
    push %op[1].low%
    push %op[0].high%
    push %op[0].low%
    call __LXUMOD
                    </When>
                    <Otherwise>
    div %op[1]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="sdiv">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
    push %op[1].high%
    push %op[1].low%
    push %op[0].high%
    push %op[0].low%
    call __LXIDIV
                    </When>
                    <Otherwise>
    idiv %op[1]%
                    </Otherwise>
                </When>
                <When Cond="isfloat(result)">
                    <When Cond="!istemp(op[0])">
                        <When Cond="op[0]==1.0">
    fld1
                        </When>
                        <When Cond="op[0]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[0]%
                        </Otherwise>
                    </When>
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
                    </When>
                    <When Cond="istemp(op[0]) &amp;&amp; op[0]==op[1]">
    fld st0
                    </When>
    fdivp st1
                    <When Cond="!istemp(result)">
    fstp %result%
                    </When>
                </When>
            </Code>
            <Code Name="smod">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
    push %op[1].high%
    push %op[1].low%
    push %op[0].high%
    push %op[0].low%
    call __LXIDIV
                    </When>
                    <Otherwise>
    idiv %op[1]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="mul">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
    push %op[1].high%
    push %op[1].low%
    push %op[0].high%
    push %op[0].low%
    call __LXMUL
                        <When Cond="%result.high%!=edx || %result.low%!=eax">
    mov	%result.high%,edx
    mov	%result.low%,eax
                        </When>
                    </When>
                    <Otherwise>
                        <When Cond="result==op[0]">
    imul %result%,%op[1]%
                        </When>
                        <When Cond="result==op[1]&amp;&amp;op[0]!=op[1]">
    mov %result%,%op[1]%
    imul %result%,%op[0]%
                        </When>
                        <Otherwise>
    mov %result%,%op[0]%
    imul %result$,%op[1]%
                        </Otherwise>
                    </Otherwise>
                </When>
                <When Cond="isfloat(result)">
                    <When Cond="!istemp(op[0])">
                        <When Cond="op[0]==1.0">
    fld1
                        </When>
                        <When Cond="op[0]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[0]%
                        </Otherwise>
                    </When>
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
                    </When>
                    <When Cond="istemp(op[0]) &amp;&amp; op[0]==op[1]">
    fld st0
                    </When>
    fmulp st1
                    <When Cond="!istemp(result)">
    fstp %result%
                    </When>
                </When>
            </Code>
            <Code Name="lsl">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result!=op[0]">
    mov %op[0].low%, %op[1].low%
    mov %op[0].high%, %op[1].high%
                        </When>
                        <When Cond="isnumber(op[2])">
                            <When Cond="op[2]==32">
    mov %op[0].high%, %op[0].low%
    xor %op[0].low%, %op[0].low%
                            </When>
                            <When Cond="op[2] &lt; 32">
    shld %op[0].high%, %op[1].low%, %op[2]
    shl  %op1[1].low%, %op[2]%
                            </When>
                            <When Cond="op[2] > 32">
    mov %op[0].high%, %op[0].low%
    xor %op[0].low%, %op[0].low%
    shl %op[0].high%, %op[2]%
                            </When>
                        </When>
                        <Otherwise>
    shld %op[0].high%, %op[1].low%, %op[2]
    shl  %op1[1].low%, %op[2]%
                        </Otherwise>
                    </When>
                    <Otherwise>
                        <When Cond="result!=op[0]">
    mov %result%,%op[0]%
                        </When>
    shl %result%,%op[2]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="lsr">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result!=op[0]">
    mov %op[0].low%, %op[1].low%
    mov %op[0].high%, %op[1].high%
                        </When>
                        <When Cond="isnumber(op[2])">
                            <When Cond="op[2]==32">
    mov %op[0].low%, %op[0].high%
    xor %op[0].high%, %op[0].high%
                            </When>
                            <When Cond="op[2] &lt; 32">
    shrd %op[0].low%, %op[1].high%, %op[2]
    shr  %op1[1].high%, %op[2]%
                            </When>
                            <When Cond="op[2] > 32">
    mov %op[0].low%, %op[0].high%
    xor %op[0].high%, %op[0].high%
    shr %op[0].low%, %op[2]%
                            </When>
                        </When>
                        <Otherwise>
    shrd %op[0].low%, %op[1].high%, %op[2]
    shr  %op1[1].high%, %op[2]%
                        </Otherwise>
                    </When>
                    <Otherwise>
                        <When Cond="result!=op[0]">
    mov %result%,%op[0]%
                        </When>
    shr %result%,%op[2]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="asr">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result!=op[0]">
    mov %op[0].low%, %op[1].low%
    mov %op[0].high%, %op[1].high%
                        </When>
                        <When Cond="isnumber(op[2])">
                            <When Cond="op[2]==32">
    mov %op[0].low%, %op[0].high%
    sar %op[0].high%, %op[2]%
                            </When>
                            <When Cond="op[2] &lt; 32">
    shrd %op[0].low%, %op[1].high%, %op[2]
    sar  %op1[1].high%, %op[2]%
                            </When>
                            <When Cond="op[2] > 32">
    mov %op[0].low%, %op[0].high%
    sar %op[0].high%, 31
    shr %op[0].low%, %op[2]%
                            </When>
                        </When>
                        <Otherwise>
    shrd %op[0].low%, %op[1].high%, %op[2]
    sar  %op1[1].high%, %op[2]%
                        </Otherwise>
                    </When>
                    <Otherwise>
                        <When Cond="result!=op[0]">
    mov %result%,%op[0]%
                        </When>
    sar %result%,%op[2]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="neg">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result!=op[0]">
    mov %op[0].low%, %op[1].low%
    mov %op[0].high%, %op[1].high%
                        </When>
    neg %op[0].high%
    neg %op[0],low%
    sbb %op[0].high%,0
                    </When>
                    <Otherwise>
                        <When Cond="result!=op[0]">
    mov %op[0]%, %op[1]%
                        </When>
    neg %op[0]%
                    </Otherwise>
                </When>
                <When Cond="result.size==float">
                    <When Cond="!istemp(op[1])">
                        <When Cond="op[1]==1.0">
    fld1
                        </When>
                        <When Cond="op[1]==0.0">
    fldz
                        </When>
                        <Otherwise>
    fld %op[1]%
                        </Otherwise>
    fchs
                    </When>
                </When>
                
            </Code>
            <Code Name="not">
                <When Cond="isscalar(result)">
                    <When Cond="result.size==longlong">
                        <When Cond="result!=op[0]">
    mov %op[0].low%, %op[1].low%
    mov %op[0].high%, %op[1].high%
                        </When>
    not %op[0].high%
    not %op[0],low%
                    </When>
                    <Otherwise>
                        <When Cond="result!=op[0]">
    mov %op[0]%, %op[1]%
                        </When>
    not %op[0]%
                    </Otherwise>
                </When>
            </Code>
            <Code Name="and" op1="and" op2="and" op3="" Class="math"/>
            <Code Name="or" op1="or" op2="or" op3="" Class="math"/>
            <Code Name="eor" op1="xor" op2="xor" op3="" Class="math"/>
            <Code Class="compare">
            </Code>
            <Code Name="setne" Class="compare">
    setn %op[0]%
            </Code>
            <Code Name="sete" Class="compare">
    sete %op[0]%
            </Code>
            <Code Name="setc" Class="compare">
    setc %op[0]%
            </Code>
            <Code Name="seta" Class="compare">
    seta %op[0]%
            </Code>
            <Code Name="setnc" Class="compare">
    setnc %op[0]%
            </Code>
            <Code Name="setbe" Class="compare">
    setbe %op[0]%
            </Code>
            <Code Name="setl" Class="compare">
    setl %op[0]%
            </Code>
            <Code Name="setg" Class="compare">
    setg %op[0]%
            </Code>
            <Code Name="setle" Class="compare">
    setel %op[0]%
            </Code>
            <Code Name="setge" Class="compare">
            </Code>
            <Code Name="assn">
            </Code>
            <Code Name="genword">
            </Code>
            <Code Name="coswitch">
            </Code>
            <Code Name="swbranch">
            </Code>
            <Code Name="dc">
            </Code>
            <Code Name="assnblock">
            </Code>
            <Code Name="clrblock">
            </Code>
            <Code Name="jc" Class="compare">
    jc %label%
            </Code>
            <Code Name="ja" Class="compare">
    ja %label%
            </Code>
            <Code Name="je" Class="compare">
    je %label%
            </Code>
            <Code Name="jnc" Class="compare">
    jnc %label%
            </Code>
            <Code Name="jbe" Class="compare">
    jbe %label%
            </Code>
            <Code Name="jne" Class="compare">
    jne %label%
            </Code>
            <Code Name="jl" Class="compare">
    jl %label%
            </Code>
            <Code Name="jg" Class="compare">
    jg %label%
            </Code>
            <Code Name="jle" Class="compare">
    jle %label%
            </Code>
            <Code Name="jge" Class="compare">
    jge %label%
            </Code>
            <Code Name="parm">
            </Code>
            <Code Name="parmadj">
            </Code>
            <Code Name="parmblock">
            </Code>
            <Code Name="cppini">
            </Code>
            <Code Name="prologue">
            </Code>
            <Code Name="epilogue">
            </Code>
            <Code Name="pushcontext">
            </Code>
            <Code Name="popcontext">
            </Code>
            <Code Name="loadcontext">
            </Code>
            <Code Name="unloadcontext">
            </Code>
            <Code Name="asm_tryblock">
            </Code>
            <Code Name="stackalloc">
            </Code>
            <Code Name="loadstack">
            </Code>
            <Code Name="savestack">
            </Code>
            <Code Name="blockstart">
            </Code>
            <Code Name="blockend">				
            </Code>
        </Gen>
        <PreColor>
        </PreColor>
        <Combine>
        </Combine>
        <Peep>
        </Peep>
    </Compiling>
</ADL>
