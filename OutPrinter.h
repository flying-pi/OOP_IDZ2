//
// Created by Yura Braiko on 17.11.16.
//

#ifndef IDZ1_OUTPRINTER_H
#define IDZ1_OUTPRINTER_H

#include <list>

using namespace std;

class IPrinter {
public:
    virtual void printResult(const char *str,
                             const unsigned int &val3,
                             const unsigned int &val1,
                             const unsigned int &val2);


    virtual void printResult(const char *str, const unsigned int &val3, const unsigned int &val1);

    virtual void printInstruction();

    virtual void printMessage(const char*message);

    virtual void printMessage(int num);

    virtual ~IPrinter() {

    }

protected:
    void getbin(unsigned int n, char *out);

    virtual ostream *getOutStream() = 0;
};

class PrintComposer : public IPrinter {
public:
    ~PrintComposer();


    PrintComposer *addConsolePrinter();

    PrintComposer *addFilePrinter();

    PrintComposer *add(IPrinter *newPrinter);

    void printResult(const char *str,
                     const unsigned int &val3,
                     const unsigned int &val1,
                     const unsigned int &val2);
    void printResult(const char *str, const unsigned int &val3, const unsigned int &val1);

    void printMessage(const char*message);
    void printMessage(int num);

    void printInstruction();

protected:
    virtual ostream *getOutStream() {
        return nullptr;
    }

private:
    list<IPrinter *> printers;

};

#endif //IDZ1_OUTPRINTER_H
