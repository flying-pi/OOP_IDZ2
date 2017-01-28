//
// Created by Yura Braiko on 27.01.17.
//

#include "util.h"
#include "const.h"
#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>

using namespace std;

unsigned short parseAsHex(char *buf, int size) {
    int result = 0;
    int order = 1;
    for (int i = size - 1; i >= 0 && buf[i] != 'x'; i--) {
        int value = buf[i];
        if (value <= '9' && value >= '0')
            value = (((int) value) - ((int) '0'));
        else if (value >= 'a' && value <= 'f') {
            value = (((int) value) - ((int) 'a')) + 10;
        } else {
            throw "нецифровой символ";
        }
        result += order * value;
        if (result > DEFAULT_VALUES::maxNum) {
            throw "переполнение";
        }
        order *= 16;
    }
    return (unsigned short) result;
}

unsigned short parseAsDex(char *buf, int size) {
    int result = 0;
    int order = 1;
    if (buf[0] == '0') {
        for (int i = 0; i < size; i++) {
            if (buf[i] != '0')
                throw "избыточное количество символов";
        }
    }
    for (int i = size - 1; i >= 0 && buf[i] != 'x'; i--) {
        int value = buf[i];
        if (value <= '9' && value >= '0')
            value = (((int) value) - ((int) '0'));
        else
            throw "нецифровой символ";
        result += order * value;
        if (result > DEFAULT_VALUES::maxNum) {
            throw "переполнение";
        }
        order *= 10;
    }
    return (unsigned short) result;
}

unsigned short readFromConsole() {
    int bufSize = 1024;
    char *buf = new char[bufSize];
    std::cin >> buf;
    for (int i = 0; i < bufSize; i++)
        buf[i] = (char) tolower(buf[i]);
    unsigned short result = 0;
    int inputStrSize = (int) strlen(buf);
    if (inputStrSize <2 ||(buf[1] >= '0' && buf[1] <= '9')) {
        result = parseAsDex(buf, inputStrSize);
    } else if (buf[1] == 'x') {
        result = parseAsHex(buf, inputStrSize);
    } else {
        throw "недопустимый дескриптор системы счисления";
    }
    delete buf;
    return result;
}
