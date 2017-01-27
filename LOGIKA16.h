//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_LOGIKA16_H
#define IDZ2_LOGIKA16_H

#include <vector>

using namespace std;

class LOGIKA16 {
public:
    unsigned short logicalAnd(unsigned short, unsigned short);

    unsigned short logicalOr(unsigned short, unsigned short);

    unsigned short logicalXor(unsigned short, unsigned short);

    unsigned short leftShift(unsigned short, unsigned short);

    unsigned short rightShift(unsigned short, unsigned short);

    unsigned short logicalInvarsion(unsigned short);

    void processBinaryFile(const char *fileName);

protected:
    typedef unsigned short (LOGIKA16::*logicalFunction)(unsigned short, unsigned short);

    // second parameter ignored
    unsigned short logicalInvarsionBinary(unsigned short, unsigned short);

    void applyAllLogicalOperation(vector<char const *> &operationNames, vector<logicalFunction> &functions,
                                  vector<unsigned short> &nums);
};


#endif //IDZ2_LOGIKA16_H
