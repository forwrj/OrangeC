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

%ifdef __BUILDING_LSCRTL_DLL
[export __crotl]
[export __crotr]
[export __rotl]
[export __rotr]
[export __lrotl]
[export __lrotr]
%endif
[global __crotl]
[global __crotr]
[global __rotl]
[global __rotr]
[global __lrotl]
[global __lrotr]

SECTION code CLASS=CODE USE32
__rotl:
__lrotl:
    mov 	eax,[esp + 4]
    mov		ecx,[esp + 8]
    rol		eax,cl
    ret

__rotr:
__lrotr:
    mov 	eax,[esp + 4]
    mov		ecx,[esp + 8]
    ror		eax,cl
    ret
__crotl:
    movzx 	eax, BYTE [esp + 4]
    mov		ecx,[esp + 8]
    rol		al,cl
    ret
__crotr:
    movzx 	eax, BYTE [esp + 4]
    mov		ecx,[esp + 8]
    ror		al,cl
    ret
