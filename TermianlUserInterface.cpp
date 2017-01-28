//
// Created by Yura Braiko on 28.01.17.
//

#include "TermianlUserInterface.h"
#include <iostream>
#include "const.h"
#include "util.h"

using namespace std;

TermianlUserInterface::TermianlUserInterface(LOGIKA16 &_logica) : logica(_logica) {

}

void TermianlUserInterface::startUserLoop() {
    bool isWork = true;
    int selectOperation;
    while (isWork) {
        printInstruction();
        cin >> selectOperation;
        switch ((command) (selectOperation - 1)) {
            case eAnd: {
                executeOperration(LOGICAL_OPEATION_NAME::andOpertion, &LOGIKA16::logicalAnd);
                break;
            }
            case eOr: {
                executeOperration(LOGICAL_OPEATION_NAME::orOpertion, &LOGIKA16::logicalOr);
                break;
            }
            case eXort: {
                executeOperration(LOGICAL_OPEATION_NAME::xorOpertion, &LOGIKA16::logicalXor);
                break;
            }
            case eLeftShift: {
                executeOperration(LOGICAL_OPEATION_NAME::leftShift, &LOGIKA16::leftShift);
                break;
            }
            case eRightShift: {
                executeOperration(LOGICAL_OPEATION_NAME::rightShift, &LOGIKA16::rightShift);
                break;
            }
            case eIversion: {
                executeOperration(LOGICAL_OPEATION_NAME::inversion, &LOGIKA16::logicalInvarsion);
                break;
            }
            default:
                cout << "ОШИБКА: введено число, не соответствующее пункту меню";
            case eFinish: {
                isWork = false;
                break;
            }
        }
    }
}

void TermianlUserInterface::printInstruction() {
    cout << ("ТЕСТИРОВАНИЕ ПОРАЗР.ЛОГИЧИСКИХ ОПЕРАЦИЙ\n"\
            " 1-выполнение операции И (&)\n"\
            " 2-выполнение операции ИЛИ (|)\n"\
            " 3-выполнение операции ИСКЛ.ИЛИ (^)\n"\
            " 4-выполнение операции ЛОГ.СДВИГ ВЛЕВО (<<)\n"\
            " 5-выполнение операции ЛОГ.СДВИГ ВПРАВО (>>)\n"\
            " 6-выполнение операции ИНВЕРСИИ (~)\n"\
            " 7-завершить выполнение программы\n");


}

void TermianlUserInterface::executeOperration(const char *commandName,
                                              binaryLogicalFunction fun) {
    unsigned short a;
    unsigned short b;

    printf("Введите два операнда из [0,65535]: \n");
    try {
        a = readFromConsole();
    } catch (const char *error) {
        cout << "ОШИБКА: в 1-м " << error << endl;
        return;
    }
    try {
        b = readFromConsole();
    } catch (const char *error) {
        cout << "ОШИБКА: в 2-м " << error << endl;
        return;
    }
    logica.getPriinter()->printResult(commandName,(logica.*(fun))(a, b),a,b);
}

void TermianlUserInterface::executeOperration(const char *commandName,
                                              unarLogicalFunction fun) {
    unsigned short a;
    try {
        a = readFromConsole();
    } catch (const char *error) {
        cout << "ОШИБКА: в " << error << endl;
        return;
    }
    logica.getPriinter()->printResult(commandName,(logica.*(fun))(a),a);
}

