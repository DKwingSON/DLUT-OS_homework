//
// Created by 王予亮 on 2018/5/24.
//

#ifndef OS_HOMEWORK_1_FILE_H
#define OS_HOMEWORK_1_FILE_H
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
    int startIndex;
    int Length;
    string Flag;
}_block;
typedef struct{
    int startIndex;
    int Length;
    string fileName;
    int next;//下一块，没有是-1
}_file;
class _FILE{
    int ramSize;
    vector<_block> blockList;//块表
    vector<_file> fileList;//占用表
    static bool compare(_block a,_block b);
public:
    _FILE();
    _FILE(int Size);
    void LoadFILE(int fileSize, string fileName);
    void DeleteFile( string fileName);
    void showBlockList();
    void showFileList();
    void defrag();
};
#endif //OS_HOMEWORK_1_FILE_H
