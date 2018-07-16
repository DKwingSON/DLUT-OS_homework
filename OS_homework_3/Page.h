//
// Created by 王予亮 on 2018/5/20.
//

#ifndef OS_HOMEWORK_3_PAGE_H
#define OS_HOMEWORK_3_PAGE_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> generateList(int ramsize, int listsize = 10);
class Page{
    vector<int> pageList;
    vector<int> resultList;//淘汰序列
    int hit, miss;//命中数和未命中数
    int cacheSize;
    int find2element(vector<int> list, int num2find, int begin, int end);
    inline void reverse(vector<int>& list, int j, int k);//reverse j~k, j and k are indexes.
public:
    Page();
    Page(vector<int> list, int size);
    void LRU();
    void showResult();
    void FIFO();
};
#endif //OS_HOMEWORK_3_PAGE_H
