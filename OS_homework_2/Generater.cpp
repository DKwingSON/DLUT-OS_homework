//
// Created by 王予亮 on 2018/5/17.
//

#include<string>
#include<vector>
#include<iostream>
#include"Generater.h"
#include "Read.h"

using namespace std;
Generater::Generater(){
    cout<<"Generater err_constructed"<<endl;
    exit(0);
}
Generater::Generater(int min, int max) {
    minsize = min;
    maxsize = max;
    if(max<=min){
        cout<<"Generate constructed (min,max)"<<endl;
        exit(0);
    }
    listsize = rand()%(max-min+1)+min;
    cout<<"Generater constructed"<<endl;
}
vector<_course> Generater::Generate() {
    vector<_course> result;
    for(int i = 0;i<listsize;i++){
        _course temp;
        temp.CourseName = i + 'A';
        temp.serveTime = rand()%10+1;
        temp.arriveTime = i*5 + rand()%10+1;
        temp.waitingTime = 0;
        temp.ifFinished = false;
        result.push_back(temp);
    }
    return result;
}