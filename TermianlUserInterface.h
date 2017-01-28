//
// Created by Yura Braiko on 28.01.17.
//

#ifndef IDZ2_TERMIANLUSERINTERFACE_H
#define IDZ2_TERMIANLUSERINTERFACE_H

#include "LOGIKA16.h"

class TermianlUserInterface {
public:
    TermianlUserInterface(LOGIKA16 &logica);
    void startUserLoop();

private:
    typedef unsigned short (LOGIKA16::*binaryLogicalFunction)(unsigned short, unsigned short);
    typedef unsigned short (LOGIKA16::*unarLogicalFunction)(unsigned short);
    LOGIKA16 &logica;
    void printInstruction();
    void executeOperration(const char *commandName,binaryLogicalFunction fun);
    void executeOperration(const char *commandName,unarLogicalFunction fun);
};


#endif //IDZ2_TERMIANLUSERINTERFACE_H
