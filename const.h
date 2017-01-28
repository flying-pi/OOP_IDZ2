//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_CONST_H
#define IDZ2_CONST_H

namespace APP_EXIT_CODE {
    static const int openFileError = 1;
    static const int fileNameToLong = 2;
    static const int fileNameEndWithDot = 3;
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
    static const char *binaryFilePath = "./../IDZ2_BINARY_OUT.bin";
	static const char *textResultFilePath = "./../IDZ2_TEXT_RESULT_OUT.txt";
	static const char *textFilePath = "./../IDZ2_TEXT_OUT.txt";

    const unsigned short maxNum = 65535;
}

namespace LIMITS{
    static const int maxFileNameSize = 37;
    }

enum command{
    eAnd,eOr,eXort,eLeftShift,eRightShift,eIversion,eFinish
};

#endif //IDZ2_CONST_H
