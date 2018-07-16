//
// Created by 王予亮 on 2018/5/20.
//
#include<iostream>
#include<iomanip>
#include"Page.h"
#include<algorithm>
using namespace std;
Page::Page(){
    cout<<"error constructed in Page()"<<endl;
    exit(0);
}
Page::Page(vector<int> list, int size){
    pageList = list;
    cacheSize = size;
    hit = 0;
    miss = 0;
}
//find number in vector
//begin and end are indexs
//both begin and end would be searched
int Page::find2element(vector<int> list,int num2find, int begin, int end){
    for(int i = begin;i<=end;i++){
        if(list[i]==num2find)
            return i;
    }
    return -1;
}
void Page::showResult(){
    cout<<"淘汰序列:";
    for(int i = 0;i<resultList.size();i++){
        if(i==resultList.size()-1) cout<<resultList[i]<<endl;
        else cout<<resultList[i]<<", ";
    }
    cout<<"命中数:"<<hit<<",缺失数:"<<miss<<",缺页率"<<((double)miss)/pageList.size()<<endl;
}
void Page::LRU() {
    cout<<"cacheSize:"<<cacheSize<<endl;
    vector<int> cache(cacheSize);
    int rear = 0, front = 0, it = 0, itnum = 0;
    for(int i=0;i<pageList.size();i++){
        it = find2element(cache,pageList[i],rear,front-1);
        if(it==-1){
            cout<<"[not found]";
        }
        else cout<<"[ found:"<<it<<" ]";
        if(it == -1) {//not found, cache is reverse order
            miss++;
            //queue full
            if ((front + 1) % cacheSize == rear) {
                //pop()
                resultList.push_back(pageList[(rear++)%cacheSize]);
                rear = rear % cacheSize;
                //push()
                cache[(front++)%cacheSize] = pageList[i];
                front = front % cacheSize;
            }
            else{
                cache[(front++)%cacheSize] = pageList[i];
                front = front % cacheSize;
                itnum++;
            }
        }
        else {
            hit++;
            reverse(cache, it, front - 1);
            reverse(cache, it, front - 2);
        }
        cout<<"[rear: "<<rear<<", front: "<<front<<"]";
        cout<<"[itnum: "<<itnum<<"]"<<endl;
        cout<<"Cache(newer->older): ";
        if(rear==front){
            cout<<"empty"<<endl;
        }
        else for(int j=0;j<itnum;j++){
                if(j==0) cout<<cache[(front-j-1)%cacheSize];
                else cout<<", "<<cache[(front-j-1)%cacheSize];
            }
        cout<<endl;
    }
}
void Page::FIFO(){
    cout<<"cacheSize:"<<cacheSize<<endl;
    vector<int> cache(cacheSize);
    int rear = 0, front = 0, it = 0, itnum = 0;
    for(int i=0;i<pageList.size();i++){
        it = find2element(cache,pageList[i],rear,front-1);
        if(it==-1){
            cout<<"[ not found ]"<<endl;
        }
        else cout<<"[ found:"<<it<<" ]";
        if(it == -1) {//not found, cache is reverse order
            miss++;
            //queue full
            if ((front + 1) % cacheSize == rear) {
                //pop()
                resultList.push_back(pageList[(rear++)%cacheSize]);
                rear = rear % cacheSize;
                //push()
                cache[(front++)%cacheSize] = pageList[i];
                front = front % cacheSize;
                //itnum = itnum +1 -1;
            }
            else {
                cache[(front++)%cacheSize] = pageList[i];
                front = front % cacheSize;
                itnum++;
            }
        }
        else{
            hit++;
        }
        cout<<"[rear: "<<rear<<", front: "<<front<<"]";
        cout<<"[itnum: "<<itnum<<"]"<<endl;
        cout<<"Cache(newer->older): ";
        if(rear==front){
            cout<<"empty"<<endl;
        }
        else for(int j=0;j<itnum;j++){
                if(j==0) cout<<cache[(front-j-1)%cacheSize];
                else cout<<", "<<cache[(front-j-1)%cacheSize];
            }
        cout<<endl;
    }
}
void Page::reverse(vector<int>& list, int j, int k) {
    int temp = 0;
    while(j<k){
        temp = list[j];
        list[j] = list[k];
        list[k] = temp;
        j++;
        k--;
    }
}
// ramsize is the size of ram, listsize is the length of ram request
vector<int> generateList(int ramsize, int listsize){
    vector<int> result;
    srand(time(NULL));
    for(int i=0;i<listsize;i++){
        result.push_back(rand()%ramsize+1);
    }
    return result;
}