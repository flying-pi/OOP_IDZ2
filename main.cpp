#include <iostream>

#include "LOGIKA16.h"
#include "const.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LOGIKA16 logika16;
    logika16.processBinaryFile(DEFAULT_VALUES::binaryFilePath);
    return 0;
}