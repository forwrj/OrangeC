#pragma once
/* Software License Agreement
 *
 *     Copyright(C) 1994-2019 David Lindauer, (LADSoft)
 *
 *     This file is part of the Orange C Compiler package.
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
#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif
class SharedMemory
{
public:
    SharedMemory(unsigned max, std::string name = "");
    ~SharedMemory();

    std::string Name() { return name_; }
#ifdef _WIN32
    BYTE* GetMapping();
#else
    unsigned char* GetMapping();
#endif
    void CloseMapping();
    bool EnsureCommitted(int size, bool relative = false);
private:
    void SetName();
    std::string name_;

    unsigned max_;
    unsigned current_;
#ifdef _WIN32
    HANDLE regionHandle;
    BYTE *regionStart;
#endif
};
#pragma once