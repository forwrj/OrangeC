;Software License Agreement (BSD License)
;
;Copyright (c) 1997-2008, David Lindauer, (LADSoft).
;All rights reserved.
;
;Redistribution and use of this software in source and binary forms, with or without modification, are
;permitted provided that the following conditions are met:
;
;* Redistributions of source code must retain the above
;  copyright notice, this list of conditions and the
;  following disclaimer.
;
;* Redistributions in binary form must reproduce the above
;  copyright notice, this list of conditions and the
;  following disclaimer in the documentation and/or other
;  materials provided with the distribution.
;
;* Neither the name of LADSoft nor the names of its
;  contributors may be used to endorse or promote products
;  derived from this software without specific prior
;  written permission of LADSoft.
;
;THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
;WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
;PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
;ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
;TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
;ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%include "matherr.inc"
%ifdef __BUILDING_LSCRTL_DLL
[export _log1p]
[export _log1pf]
[export _log1pl]
%endif
[global _log1p]
[global _log1pf]
[global _log1pl]
[global lexp1]
SECTION data CLASS=DATA USE32
nm	db	"log1p",0

two dd 2
pointthree dd 0.28

SECTION code CLASS=CODE USE32

lexp1:
    fldln2
    fxch
    fld st0
    fabs
    fld dword [pointthree]
    fcompp
    fstsw ax
    sahf
    jae p1calc
    fld1
    faddp st1
    fyl2x
    ret
p1calc:
    fyl2xp1
    ret    
    
_log1pf:
    lea	ecx,[esp+4]
    fld	dword[ecx]
    sub dl,dl
    jmp short log1p
_log1pl:
    lea	ecx,[esp+4]
    fld	tword[ecx]
    mov dl,2
    jmp short log1p
_log1p:
    lea	ecx,[esp+4]
    fld	qword[ecx]
    mov dl,1
log1p:
    lea	eax,[nm]
    call    clearmath
    fld1
    fchs
    fcomp st1
    fnstsw ax
    sahf
    jae domainerr
    call    lexp1
    jmp wrapmath
