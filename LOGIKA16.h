//
// Created by Yura Braiko on 27.01.17.
//

#ifndef IDZ2_LOGIKA16_H
#define IDZ2_LOGIKA16_H

#include <vector>
#include "OutPrinter.h"

using namespace std;

//��������� �� ������ ������� � ������������ ���������� ����������� -
// ���������� ������ ������ � �������� ����� � ������ � ���� �����
// �������� ������� SRP(������� ������ �������������) �� ���� �����,
//�������������� ��� ������ � ����������� ����������� �� ������ �������� ��
// ���������� ������������ �����/����� ������� 7 ����� ������� ������� ��
// ������ ���������,  ��������� ������������� �������� � ������ � �������
// � ����� ������������.

//�� ������� ���������� ������� ��� ��, ��� ���������������� ��������
// ��� �� ����� ��������� � ���� ������ ��� ����������� ��� � ������
//�����������  God object

// ��������� ������� ��������� ��������� � ������������ ��������� ������ OutPrinter,
// ������� ������������� �������� ���������
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
