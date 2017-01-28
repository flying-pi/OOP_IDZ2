//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_LOGIKA16_H
#define IDZ2_LOGIKA16_H

#include <vector>
#include "OutPrinter.h"

using namespace std;

//замечание по поводу заданий и правильности построение архитектуры -
// переносить логику работы с потоками ввода и вывода в один класс
// нарушает принцип SRP(принцип единой ответсвености) то есть класс,
//предназначеный для работы с логичискими операторами не должен зависить от
// конкретных инструментов ввода/вывод поэтому 7 пункт данного задания не
// совсем коректный,  поскольку подразумивает создание и работу с файлами
// в своем конструкторе.

//из данного требование следует так же, что пользовательские операции
// так же нужно провидить в этом классе что проверащает его в пример
//антипатерна  God object

// формально задание выполнено поскольку в конструкторе создается обьект OutPrinter,
// который инкапсулирует указаное поведение
class LOGIKA16 {
public:
    LOGIKA16();
    ~LOGIKA16();

    unsigned short logicalAnd(unsigned short, unsigned short);

    unsigned short logicalOr(unsigned short, unsigned short);

    unsigned short logicalXor(unsigned short, unsigned short);

    unsigned short leftShift(unsigned short, unsigned short);

    unsigned short rightShift(unsigned short, unsigned short);

    unsigned short logicalInvarsion(unsigned short);

    void processBinaryFile(const char *fileName);

    IPrinter * getPriinter();

protected:
    typedef unsigned short (LOGIKA16::*logicalFunction)(unsigned short, unsigned short);

    // second parameter ignored
    unsigned short logicalInvarsionBinary(unsigned short, unsigned short);

    void applyAllLogicalOperation(vector<char const *> &operationNames, vector<logicalFunction> &functions,
                                  vector<unsigned short> &nums);

    PrintComposer *printer;
};


#endif //IDZ2_LOGIKA16_H
