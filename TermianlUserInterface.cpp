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
                cout << "������: ������� �����, �� ��������������� ������ ����";
            case eFinish: {
                isWork = false;
                break;
            }
        }
    }
}

void TermianlUserInterface::printInstruction() {
    cout << ("������������ ������.���������� ��������\n"\
            " 1-���������� �������� � (&)\n"\
            " 2-���������� �������� ��� (|)\n"\
            " 3-���������� �������� ����.��� (^)\n"\
            " 4-���������� �������� ���.����� ����� (<<)\n"\
            " 5-���������� �������� ���.����� ������ (>>)\n"\
            " 6-���������� �������� �������� (~)\n"\
            " 7-��������� ���������� ���������\n");


}

void TermianlUserInterface::executeOperration(const char *commandName,
                                              binaryLogicalFunction fun) {
    unsigned short a;
    unsigned short b;

    printf("������� ��� �������� �� [0,65535]: \n");
    try {
        a = readFromConsole();
    } catch (const char *error) {
        cout << "������: � 1-� " << error << endl;
        return;
    }
    try {
        b = readFromConsole();
    } catch (const char *error) {
        cout << "������: � 2-� " << error << endl;
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
        cout << "������: � " << error << endl;
        return;
    }
    logica.getPriinter()->printResult(commandName,(logica.*(fun))(a),a);
}

