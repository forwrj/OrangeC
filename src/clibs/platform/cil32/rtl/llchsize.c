/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2008, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, with or without modification, are
    permitted provided that the following conditions are met:
    
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
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
    WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
    TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <errno.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "libp.h"
#include <sys\stat.h>

using namespace System::IO;
using namespace System;

void __SetFileErrno(Exception e);
FileStream __llGetHandle(int);

int __ll_chsize(int handle, int size)
{
   int old = __ll_getpos(handle) ;
   char buf[256] ;
   int len ;
   int rv = 0 ;
   if (old == -1)
      return old ;
   len = __ll_seek(handle,0,SEEK_END) ;
   if (len == -1)
      return len ;
   len = __ll_getpos(handle) ;
   if (len == -1)
      return len ;
   if (len != size) {
      if (len < size) {
         memset(buf,0,256) ;
         len = size - len ;
         while (len >= 256) {
            rv = __ll_write(handle,buf,256) ;
            if (rv == -1 || rv != 256)
               return -1 ;
            len -= 256 ;
         }
         if (len) {
            rv = __ll_write(handle,buf,len) ;
            if (rv == -1 || rv != len)
               return -1 ;
         }
      } else {
         __try {
             FileStream strm = __llGetHandle(handle);
             strm.SetLength(size);
         }
         __catch(Exception e)
         {
             __SetFileErrno(e);
             rv = -1;
         }
         if (rv == -1)
             return rv;
      }
   }
   return __ll_seek(handle,old,SEEK_SET) ;
}
