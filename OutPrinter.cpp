//
// Created by Yura Braiko on 17.11.16.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "OutPrinter.h"
#include "const.h"

PrintComposer *PrintComposer::add(IPrinter *newPrinter) {
    printers.push_back(newPrinter);
    return this;
}

void PrintComposer::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument,
                                const unsigned int &secondArgument) {
    for (auto i:printers)
        i->printResult(str, operationResult, firstArgument, secondArgument);

}

void
PrintComposer::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument) {
    for (auto i:printers)
        i->printResult(str, operationResult, firstArgument);

}

PrintComposer::~PrintComposer() {
    for (auto i:printers)
        delete i;
}

void IPrinter::getbin(unsigned int n, char *out) {
    for (int i = 0; i < 16; i++) {
        out[i] = n & 0x8000 ? '1' : '0';
        n = n << 1;
    }
    out[17] = '\0';
}

void
IPrinter::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument,
                      const unsigned int &secondArgument) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;

    char *binaryValue = new char[17];
    (*out) << ("ОТВЕТ:\n");
    (*out) << setfill(' ') << setw(18) << dec << firstArgument << " 0x" << setfill('0') << setw(8) << hex
           << firstArgument << " ";
    getbin(firstArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << str << setfill(' ') << setw(10) << dec << secondArgument << " 0x" << setfill('0') << setw(8) << hex
           << secondArgument
           << " ";
    getbin(secondArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n==============================================\n";
    (*out) << setfill(' ') << setw(18) << dec << operationResult << " 0x" << setfill('0') << setw(8) << hex
           << operationResult << " ";
    getbin(operationResult, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n";

    delete binaryValue;
}


void IPrinter::printResult(const char *str, const unsigned int &operationResult, const unsigned int &firstArgument) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;

    char *binaryValue = new char[17];
    (*out) << ("ОТВЕТ:\n");

    (*out) << str << setfill(' ') << setw(9) << dec << firstArgument << " 0x" << setfill('0') << setw(8) << hex
           << firstArgument << " ";
    getbin(firstArgument, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n==============================================\n";
    (*out) << setfill(' ') << setw(18) << dec << operationResult << " 0x" << setfill('0') << setw(8) << hex
           << operationResult << " ";
    getbin(operationResult, binaryValue);
    (*out) << binaryValue;
    (*out) << "\n";

    delete binaryValue;
}

void IPrinter::printInstruction() {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;
    (*out) << ("ТЕСТИРОВАНИЕ ПОРАЗР.ЛОГИЧИСКИХ ОПЕРАЦИЙ\n"\
            " 1-выполнение операции И (&)\n"\
            " 2-выполнение операции ИЛИ (|)\n"\
            " 3-выполнение операции ИСКЛ.ИЛИ (^)\n"\
            " 4-выполнение операции ЛОГ.СДВИГ ВЛЕВО (<<)\n"\
            " 5-выполнение операции ЛОГ.СДВИГ ВПРАВО (>>)\n"\
            " 6-выполнение операции ИНВЕРСИИ (~)\n"\
            " 7-завершить выполнение программы\n");
}

void IPrinter::printMessage(const char *message) {
    ostream *out = getOutStream();
    if (out == nullptr)
        return;
    (*out) << message;
}

class ConsolePrinter : public IPrinter {
public:
protected:
    virtual ostream *getOutStream() override {
        return &cout;
    }
};

class FilePrinter : public IPrinter {
public:
    FilePrinter() {
        isOpenFile = false;
        cout << "please enter file name for store application log :: ";
        char *fileName = new char[LIMITS::maxFileNameSize + 2];
        cin >> fileName;
        if (strlen(fileName) > LIMITS::maxFileNameSize) {
            cout << "ОШИБКА: файл вывода не открыт для записи – в имени файла количество символов больше 37\n";
        }
        if (fileName[strlen(fileName) - 1] == '.') {
            cout << "ОШИБКА: файл вывода не открыт для записи – в конце имени файла недопустимый символ (точка)\n";
        }
        try {

            file.open(fileName, std::ofstream::out | std::ofstream::app);
            isOpenFile = true;
        }
        catch (std::ios_base::failure &e) {
            std::cerr << e.what() << '\n';
        }
    }

    ~FilePrinter() {
        (file).close();
    }

protected:
    ofstream file;
    bool isOpenFile;

    virtual ostream *getOutStream() override {
        if (!isOpenFile)
            return nullptr;
        return &file;
    }
};

PrintComposer *PrintComposer::addConsolePrinter() {
    return add(new ConsolePrinter());
}

PrintComposer *PrintComposer::addFilePrinter() {
    IPrinter *printer;
    printer = new FilePrinter();
    return add(printer);
}
