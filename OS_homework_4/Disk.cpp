//
// Created by 王予亮 on 2018/5/22.
//
#include<iostream>
#include<vector>
#include<cmath>
#include"Disk.h"
using namespace std;
Disk::Disk() {
    cout<<"Error Constructed"<<endl;
    exit(0);
}
Disk::Disk(vector<int> list,int radius, int pos){
    if(list.empty()){
        cout<<"Error Constructed, empty list"<<endl;
        exit(0);
    }
    for(int i = 0;i<list.size();i++){
        request a;
        a.pos = list[i];
        a.iffind = false;
        requestList.push_back(a);
    }
    //requestList = list;
    this->radius = radius;
    moveLength = 0;
    moveNum = 0;
    //showRequest();
    if(pos<0 && pos>radius)
        initDisk(0);
    else initDisk(pos);
}
bool Disk::ifallFinished() {
    for(int i = 0;i<requestList.size();i++)
        if(requestList[i].iffind==false)
            return false;
    return true;
}
void Disk::initDisk(int position) {
    initpos = position;
}
void Disk::showRequest() {
    cout<<"RequestList:";
    for(int i=0;i<requestList.size();i++){
        cout<<'['<<requestList[i].pos<<", "<<requestList[i].iffind<<']';
    }
    cout<<endl;
}
void Disk::SSTF() {
    int temp = initpos;
    cout<<"initpos:"<<initpos<<endl;
    for(int i = 0;i<requestList.size();i++){
        int nextpos = find_closest(temp);// nextpos is index, list[nextpos].pos is the value of track
        moveLength += abs(requestList[nextpos].pos-temp);
        cout<<"[nextpos: "<<nextpos<<']'<<"[moveLength: "<<moveLength<<']';
        temp = requestList[nextpos].pos;
        requestList[nextpos].iffind = true;
        resultList.push_back(requestList[nextpos].pos);
        cout<<"[currentpos: "<<temp<<']'<<endl;
        //showRequest();
    }
    moveNum  = (int)requestList.size();
}
//track's range 0~Radius(not include Radius itself)
//track's motion: current_pos->0->radius
void Disk::SCAN() {
    int temp = initpos, movingDir = 1;//movingDir = 1: current_pos->0, -1: current_pos->radius
    cout<<"initpos:"<<initpos<<endl;
    vector<int> hash(radius,-1);//mimic a hash list
    for(int i = 0;i<requestList.size();i++){
        hash.at(requestList[i].pos) = i;
    }
    cout<<"[tmep:"<<temp<<"][moveLenght:"<<moveLength<<"]"<<endl;
    while(ifallFinished()==false){
        if(hash[temp] != -1){//find
            if(requestList[hash[temp]].iffind == false) {
                resultList.push_back(temp);
                requestList[hash[temp]].iffind = true;
                moveNum++;
            }
        }
        temp -= movingDir;
        moveLength += 1;
        if(temp==0 || temp==radius-1){
            movingDir *= -1;
        }
        cout<<"[tmep:"<<temp<<"][moveLenght:"<<moveLength<<"]"<<endl;
        //showRequest();
    }
}
void Disk::showResult() {
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"响应请求顺序:"<<endl;
    for(int i = 0;i<resultList.size();i++){
        if(i == resultList.size()-1)
            cout<<"["<<resultList.at(i)<<"]"<<endl;
        else cout<<"["<<resultList.at(i)<<"]->";
    }
    cout<<"移臂总量:"<<moveLength<<endl;
    cout<<"移臂次数:"<<moveNum<<endl;
    cout<<"平均移臂长度:"<<(double)moveLength/moveNum<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
}
vector<int> generateList(int radius, int listsize){
    vector<int> result;
    srand(time(NULL));
    for(int i=0;i<listsize;i++){
        result.push_back(rand()%radius);
    }
    return result;
}
//find closest track, return index
int Disk::find_closest(int pos){
    int distance = radius, index = -1;
    for(int i = 0;i<requestList.size();i++){
        if(abs(requestList[i].pos - pos) < distance && requestList[i].iffind==false) {
            distance = abs(requestList[i].pos - pos);
            //cout<<"[distance:"<<distance<<"]["<<requestList[i].pos<<"]"<<endl;
            index = i;
        }
    }
    return index;
}
