#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "../const.h"

using namespace std;

int main() {
    int countNums;
    cout << "enter count of nums :: ";
    std::cin >> countNums;
    ofstream textOut(DEFAULT_VALUES::textFilePath);
    FILE *binaryOut = fopen(DEFAULT_VALUES::binaryFilePath,"w");
    if(!textOut.is_open() ||!binaryOut)
    {
        cout << "can not open files";
        return  1;
    }
    srand(time(NULL));
    for(int i=0;i<countNums;i++)
    {
        textOut<<(rand()%DEFAULT_VALUES::maxNum)<<" ";
        unsigned short buf = (unsigned short) (rand() % DEFAULT_VALUES::maxNum);
        fwrite(&buf, sizeof(unsigned short),1,binaryOut);
    }
    textOut.close();
    fclose(binaryOut);
	system("pause");
    return 0;
}