//===---------------------- bad_alloc.cpp ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "__config"
#include "new"

namespace std {

bad_alloc::bad_alloc()
{
}

bad_alloc::~bad_alloc() _NOEXCEPT
{
}

const char *bad_alloc::what() const _NOEXCEPT
{
    return "bad_alloc";
}
void
__throw_bad_alloc()
{
#ifndef _LIBCPP_NO_EXCEPTIONS
    throw bad_alloc();
#endif
}

bad_array_length::bad_array_length() : bad_alloc()
{
}

bad_array_length::~bad_array_length() _NOEXCEPT
{
}

const char *bad_array_length::what() const _NOEXCEPT
{
    return "bad_array_length";
}

bad_array_new_length::bad_array_new_length() : bad_alloc()
{
}

bad_array_new_length::~bad_array_new_length() _NOEXCEPT
{
}

const char *bad_array_new_length::what() const _NOEXCEPT
{
    return "bad_array_new_length";
}

}
