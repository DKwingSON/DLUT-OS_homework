//
// Created by 王予亮 on 2018/5/22.
//

#ifndef OS_HOMEWORK_4_MEMORY_H
#define OS_HOMEWORK_4_MEMORY_H
#include<vector>
using namespace std;
typedef struct{
    int pos;
    bool iffind;
}request;
class Disk{
    vector<request> requestList;
    vector<int> resultList;
    int moveLength;
    int moveNum;
    int initpos, radius;
    void initDisk(int position);
    void showRequest();
    bool ifallFinished();
    int find_closest(int pos);
public:
    Disk();
    Disk(vector<int> list,int radius, int pos);
    void SSTF();
    void SCAN();
    void showResult();
};
#endif //OS_HOMEWORK_4_MEMORY_H
