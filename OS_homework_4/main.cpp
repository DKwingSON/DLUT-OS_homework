#include <iostream>
#include "Disk.h"
using namespace std;
int main(int argc, char* const argv[]) {
    vector<int> input = {0,22,5,7,11,21,2};
    Disk testa(input,30,4), testb(input,30,4);
    //test.SSTF();
    testa.SCAN();
    testa.showResult();
    testb.SSTF();
    testb.showResult();
    return 0;
}