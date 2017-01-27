//
// Created by Yura Braiko on 27.01.17.
//

#include "LOGIKA16.h"
#include <fstream>
#include <iostream>
#include "const.h"
#include "util.h"

unsigned short LOGIKA16::logicalInvarsionBinary(unsigned short a, unsigned short) {
    return logicalInvarsion(a);
}

unsigned short LOGIKA16::logicalAnd(unsigned short a, unsigned short b) {
    return a & b;
}

unsigned short LOGIKA16::logicalOr(unsigned short a, unsigned short b) {
    return a & b;
}

unsigned short LOGIKA16::logicalXor(unsigned short a, unsigned short b) {
    return a ^ b;
}

unsigned short LOGIKA16::leftShift(unsigned short a, unsigned short b) {
    return a << b;
}

unsigned short LOGIKA16::rightShift(unsigned short a, unsigned short b) {
    return a >> b;
}

unsigned short LOGIKA16::logicalInvarsion(unsigned short a) {
    return ~a;
}

void LOGIKA16::processBinaryFile(const char *fileName) {
    vector<unsigned short> nums;
    unsigned short A, B;
    FILE *file = fopen(fileName, "r");
    if (!file) {
        exit(APP_EXIT_CODE::openFileError);
        return;
    }

    while (fread(&A, sizeof(A), 1, file)) {
        nums.push_back(A);
        if (!fread(&B, sizeof(B), 1, file))
            break;
        nums.push_back(B);
    }
    vector<char const *> operationName;
    vector<LOGIKA16::logicalFunction> functions;

    operationName.push_back(LOGICAL_OPEATION_NAME::andOpertion);
    operationName.push_back(LOGICAL_OPEATION_NAME::orOpertion);
    operationName.push_back(LOGICAL_OPEATION_NAME::xorOpertion);
    operationName.push_back(LOGICAL_OPEATION_NAME::leftShift);
    operationName.push_back(LOGICAL_OPEATION_NAME::rightShift);
    operationName.push_back(LOGICAL_OPEATION_NAME::inversion);

    functions.push_back(&LOGIKA16::logicalAnd);
    functions.push_back(&LOGIKA16::logicalOr);
    functions.push_back(&LOGIKA16::logicalXor);
    functions.push_back(&LOGIKA16::leftShift);
    functions.push_back(&LOGIKA16::rightShift);
    functions.push_back(&LOGIKA16::logicalInvarsionBinary);

    applyAllLogicalOperation(operationName, functions, nums);
}

void
LOGIKA16::applyAllLogicalOperation(vector<char const *> &operationNames, vector<LOGIKA16::logicalFunction> &functions,
                                   vector<unsigned short> &nums) {
    unsigned short a, b;
    for (int i = 0; i < functions.size(); i++) {
        bool isInvarsion = &LOGIKA16::logicalInvarsionBinary == (functions[i]);
        for (int n = 0; n < nums.size(); n += (isInvarsion ? 1 : 2)) {

            if (isInvarsion) {
                printResult(operationNames[i], (this->*(functions[i]))(nums[n], 0), nums[n]);
                continue;
            }
            a = nums[n];
            if (n+1 < nums.size())
                b = nums[n + 1];
            else
                b = 0;
            printResult(operationNames[i], (this->*(functions[i]))(a, b), a, b);

        }
    }

}
