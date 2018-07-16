#include <iostream>
#include <sstream>
#include "File.h"
using namespace std;
int main() {
    int i = 0, s = 0;
    //stringstream ss;
    srand(time(NULL));
    _FILE test(1000);
    test.showBlockList();
    test.showFileList();
    for(int i = 0;i<50;i++){
        stringstream ss;
        ss<<i+1;
        s = rand()%10+2;
        //cout<<"input:"<<s<<"K ,"<<ss.str()+".txt"<<endl;
        test.LoadFILE(s, ss.str()+".txt");
        //test.showBlockList();
    }
    test.showBlockList();
    test.showFileList();
    for(int i = 0;i<50;i++){
        if(i%2==0) continue;
        else{
            stringstream ss;
            ss<<i;
            test.DeleteFile(ss.str()+".txt");
        }
    }

//    for(int i = 0;i<50;i++){
//        stringstream ss;
//        ss<<i+1;
//        test.DeleteFile(ss.str()+".txt");
//    }
    test.defrag();
    test.showBlockList();
    test.showFileList();

    test.LoadFILE(7,"A.txt");
    test.LoadFILE(5,"B.txt");
    test.LoadFILE(2,"C.txt");
    test.LoadFILE(9,"D.txt");
    test.LoadFILE((int)3.5,"E.txt");

    test.defrag();
    test.showBlockList();
    test.showFileList();
    return 0;
}