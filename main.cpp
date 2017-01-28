#include <iostream>

#include "LOGIKA16.h"
#include "const.h"
#include "util.h"
#include "TermianlUserInterface.h"

int main() {
    LOGIKA16 logika16;
    logika16.processBinaryFile(DEFAULT_VALUES::binaryFilePath);
    TermianlUserInterface userInterface(logika16);
    userInterface.startUserLoop();
    return 0;
}