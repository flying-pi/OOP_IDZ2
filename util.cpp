//
// Created by Yura Braiko on 27.01.17.
//

#include "util.h"

void getbin(unsigned short n) {

    for (int i = 0; i < 16; i++) {
        if (n & 0x8000)
            putc('1', stdout);
        else
            putc('0', stdout);
        n = n << 1;
    }
}

void printResult(const char *str, const unsigned short &result, const unsigned short &firstArgument,
                 const unsigned short &secondArgument) {
    printf("Result:\n");
    printf("\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020%5hu 0x%04x ", firstArgument, firstArgument);
    getbin(firstArgument);
    printf("%s%5hu 0x%04x ", str, secondArgument, secondArgument);
    getbin(secondArgument);
    printf("\n=====================================\n");
    printf("\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020%5hu 0x%04x ", result, result);
    getbin(result);
    printf("\n\n");
}

void printResult(const char *str, const unsigned short &val3, const unsigned short &val1) {
    printf("Result:\n");
    printf("%s%5hu 0x%04x ", str, val1, val1);
    getbin(val1);
    printf("\n======================================\n");
    printf("\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020\u0020%5hu 0x%04x ", val3, val3);
    getbin(val3);
    printf("\n\n");
}
