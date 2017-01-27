//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_UTIL_H
#define IDZ2_UTIL_H

#include <stdio.h>
#include <cstring>

extern void getbin(unsigned short n);

extern void printResult(const char *str,
                 const unsigned short &result,
                 const unsigned short &firstArgument,
                 const unsigned short &secondArgument);

extern void printResult(const char *str,
           const unsigned short &val3,
           const unsigned short &val1);

#endif //IDZ2_UTIL_H
