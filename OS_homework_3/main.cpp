//
// Created by 王予亮 on 2018/5/20.
//
#include<iostream>
#include"Page.h"
using namespace std;
int main(int argv, char* const argc[]){
    vector<int> input = generateList(10,20);
    for(int i=0;i<input.size();i++){
        if(i==0) cout<<input[0];
        else cout<<","<<input[i];
    }cout<<endl;
    Page pa(input,6),pb(input,6);
    pa.LRU();
    pa.showResult();
    pb.FIFO();
    pb.showResult();
    return 0;
}
