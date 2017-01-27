//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_CONST_H
#define IDZ2_CONST_H

namespace APP_EXIT_CODE {
    static const int openFileError = 1;
}

namespace LOGICAL_OPEATION_NAME {
    static const char andOpertion[10] = "\nAND     ";
    static const char orOpertion[10] = "\nOR      ";
    static const char xorOpertion[10] = "\nXOR     ";
    static const char leftShift[10] = "\n<<      ";
    static const char rightShift[10] = "\n>>      ";
    static const char inversion[10] = "INV      ";
}

namespace DEFAULT_VALUES{
    static const char *binaryFilePath = "/Users/yurabraiko/temp/IDZ2_BINARY_OUT.bin";
    const unsigned short maxNum = 65535;
}

#endif //IDZ2_CONST_H
