//
// Created by 王予亮 on 2018/5/14`.
//

#include<iostream>
#include<vector>
#include "Read.h"
#include "Schedule.h"
#define MAXSIZE 50
using namespace std;
//TODO: Already checked FCFS SJF
Schedule::Schedule() {
    cout<<"No argument"<<endl;
    exit(0);
}
Schedule::Schedule(vector<_course> List) {
    //cout<<"Successful constructed"<<endl;
    RunningTime = 0;
    courseList = List;
}
void Schedule::FCFS() {
    int maxIndex = 0, i = 0;
    while(!this->allFinished()){
        //TimeFCFS();
        maxIndex =FindMaxWait(courseList);
        //cout<<"maxIndex(=FindMaxWait(courseList)):"<<maxIndex<<", RunningTime:"<<RunningTime<<endl;
        if(maxIndex == -1) {
            TimeFCFS(1);
            continue;
        }
        courseList[maxIndex].ifFinished = true;
        while(i<courseList[maxIndex].serveTime){
            TimeFCFS(1);
            i++;
        }i = 0;
        //TimeFCFS(courseList[maxIndex].serveTime);
        //showCourse(courseList);
    }
}
void Schedule::RR(int slot){
    int rear = 0, front = 0;
    vector<_course> Que(MAXSIZE);
    vector<int> hash(MAXSIZE,0);
    //for(int i = 0;i<courseList.size();i++){
    //    Que[(front++)%MAXSIZE] = courseList[i];//入队
    //}
    for(int i = 0;i<courseList.size();i++){
        if(RunningTime>=courseList[i].arriveTime&&hash[i]!=1){
            //hash[courseList[i]] = i;
            Que[(front++)%MAXSIZE]=courseList[i];
            front %=MAXSIZE;
            hash[i]=1;
        }
    }
    while(!allFinished()) {// not empty
        if((front+1)%MAXSIZE == rear){
            cout<<"Queue Full - try to enlarge MAXSIZE"<<endl;
            return;
        }
        if(rear==front){
            // queue empty, time pass by
            cout<<"Queue Empty"<<endl;
            for(int i = 0;i<courseList.size();i++){
                if(RunningTime==courseList[i].arriveTime&&hash[i]!=1){
                    //hash[courseList[i]] = i;
                    Que[(front++)%MAXSIZE]=courseList[i];
                    front %=MAXSIZE;
                    hash[i]=1;
                }
            }
            TimeFCFS();
            continue;
        }
        cout<<rear<<" "<<front<<" "<<RunningTime<<endl;
        for(int i = rear;i<front;i++){
            cout<<"Name:"<<courseList[i].CourseName<<endl;
        }
        cout<<endl;
        //showCourse(Que);
        //cout<<"rear:"<<rear<<", front:"<<front<<endl;
        //sortRR(rear, front, Que);//sort it! (small->big)
        _course temp = Que[rear];  //pop and get the first element
        if(temp.serveTime > slot) {
            temp.serveTime -= slot;
            TimeRR(slot, temp.CourseName);
            rear++;
            rear %= MAXSIZE;
            for(int i = 0;i<courseList.size();i++){
                if(RunningTime>=courseList[i].arriveTime&&hash[i]!=1){
                    //hash[courseList[i]] = i;
                    Que[(front++)%MAXSIZE]=courseList[i];
                    front %=MAXSIZE;
                    hash[i]=1;
                }
            }
            Que[(front++)%MAXSIZE] = temp;
            continue;
        }
        else if(temp.serveTime == slot){
            TimeRR(slot, temp.CourseName);
            rear++;
            rear %= MAXSIZE;
            for(int i = 0;i<courseList.size();i++){
                if(RunningTime>=courseList[i].arriveTime&&hash[i]!=1){
                    //hash[courseList[i]] = i;
                    Que[(front++)%MAXSIZE]=courseList[i];
                    front %=MAXSIZE;
                    hash[i]=1;
                }
            }
            FinishCourse(temp.CourseName);
            continue;
        }
        else if(temp.serveTime < slot){
            TimeRR(temp.serveTime, temp.CourseName);
            rear++;
            rear %= MAXSIZE;
            for(int i = 0;i<courseList.size();i++){
                if(RunningTime>=courseList[i].arriveTime&&hash[i]!=1){
                    //hash[courseList[i]] = i;
                    Que[(front++)%MAXSIZE]=courseList[i];
                    front %=MAXSIZE;
                    hash[i]=1;
                }
            }
            FinishCourse(temp.CourseName);
            continue;
        }
    }
}
void Schedule::SJF() {
    int minIndex = 0, i = 0;
    while(!this->allFinished()) {
        if(RunningTime>=200) break;
        //TimeFCFS();
        minIndex = FindMinServe(courseList);
        //cout<<"(minIndex:"<<minIndex<<")"<<endl;
        if(minIndex == -1){
            TimeFCFS();
            continue;
        }
        courseList[minIndex].ifFinished = true;
        while(i<courseList[minIndex].serveTime){
            TimeFCFS();
            i++;
        }
        i = 0;
        //TimeFCFS(courseList[minIndex].serveTime);
        //showCourse(courseList);
    }
}
//TODO: check the authenticity of HRRN
void Schedule::HRRN() {

    int maxIndex = 0, i = 0;
    while(!this->allFinished()){
        if(RunningTime>=200) break;
        maxIndex = FindMaxRes(courseList);
        if(maxIndex == -1){
            TimeFCFS();
            continue;
        }
        courseList[maxIndex].ifFinished = true;
        while(i<courseList[maxIndex].serveTime) {
            TimeFCFS();
            i++;
        }
        i = 0;
        //TimeFCFS(courseList[maxIndex].serveTime);
    }
}
void Schedule::TimeRR(int time, string Name){
    RunningTime += time;
    for(int i = 0;i < courseList.size();i++){
        if(courseList[i].CourseName == Name) continue;
        else if(RunningTime > courseList[i].arriveTime && !courseList[i].ifFinished)
            courseList[i].waitingTime +=time;
    }

}
// time is not allowed to assign 1 for safety reasons
void Schedule::TimeFCFS(int time) {
    RunningTime += time;
    for (int i = 0; i < courseList.size(); i++) {
        if (RunningTime > courseList[i].arriveTime && !courseList[i].ifFinished)
            courseList[i].waitingTime += time;
    }

}
bool Schedule::allFinished() {
    for(int i = 0;i<courseList.size();i++)
        if(!courseList[i].ifFinished)
            return false;
    return true;
}
int Schedule::FindMinServe(vector<_course> list) {
    bool FindOnce = false;
    if(list.empty()) return -2;
    int min = 100, minIndex = 0;
    for(int i = 0;i<list.size();i++){
        if(min>=list[i].serveTime && RunningTime >= list[i].arriveTime && !list[i].ifFinished){
            FindOnce = true;
            minIndex = i;
            min = list[i].serveTime;
        }
    }
    if(FindOnce) return minIndex;
    else return -1;
}
int Schedule::FindMaxWait(vector<_course> list) {
    bool FindOnce = false;
    if(list.empty()) return -2;
    int max = 0, maxIndex = 0;
    for(int i = 0;i<list.size();i++){
        if(max<=list[i].waitingTime && RunningTime >= list[i].arriveTime && !list[i].ifFinished){
            FindOnce = true;
            maxIndex = i;
            max = list[i].waitingTime;
        }
    }
    if(FindOnce) return maxIndex;
    else return -1;
}
int Schedule::FindMaxRes(vector<_course> list){//maxres = max{(waitingtime + servetime)/servetime}
    if(list.empty()) return -2;
    bool FindOnce = false;
    int maxIndex = 0;
    double resp = 0, max = 0;
    for(int i = 0;i<list.size();i++){
        resp = (list[i].waitingTime+list[i].serveTime)/list[i].serveTime;
        if(max<=resp && RunningTime >= list[i].arriveTime && !list[i].ifFinished){
            FindOnce = true;
            maxIndex = i;
            max = resp;
        }
    }
    if(FindOnce) return maxIndex;
    else return -1;
}
void Schedule::showResult(){
    double avgTOtime = 0, avgWTOtime = 0;
    if(!allFinished()){
        cout<<"Not Finished, cannot show result"<<endl;
        return;
    }
    for(int i=0;i<courseList.size();i++){
        int TOtime = courseList[i].waitingTime+courseList[i].serveTime;
        double WTOtime = (double)(courseList[i].waitingTime+courseList[i].serveTime)/courseList[i].serveTime;
        cout<<"Name:"<<courseList[i].CourseName<<", TurnOverTime:"<<TOtime<<", Weighted TurnOverTime: "<<WTOtime<<endl;
        avgTOtime += TOtime;
        avgWTOtime += WTOtime;
    }
    cout<<"Average TurnOver Time:"<<avgTOtime/courseList.size()<<endl;
    cout<<"Weighted Average TurnOver Time:"<<avgWTOtime/courseList.size()<<endl;
}
void Schedule::swapRR(_course &a, _course &b) {
    _course temp = a;
    a.CourseName = b.CourseName;
    a.waitingTime = b.waitingTime;
    a.ifFinished = b.ifFinished;
    //a.ifStarted = b.ifStarted;
    a.serveTime = b.serveTime;
    a.arriveTime = b.arriveTime;
    b.CourseName = temp.CourseName;
    b.waitingTime = temp.waitingTime;
    b.ifFinished = temp.ifFinished;
    //b.ifStarted = temp.ifStarted;
    b.serveTime = temp.serveTime;
    b.arriveTime = temp.arriveTime;
}
void Schedule::sortRR(int rear, int front, vector<_course>& list){//rear is the first eleent's index, front-1 is the last one's
    if(rear == front){
        cout<<"Empty in SortRR()"<<endl;
        return;
    }
    for(int i = rear;i<front;i++){
        for(int j = front-1;j>i;j--){
            if(list[j].waitingTime<list[j-1].waitingTime){
                swap(list[j],list[j-1]);
            }
        }
    }
}
void Schedule::FinishCourse(string name) {
    for(int i = 0;i<courseList.size();i++){
        if(courseList[i].CourseName == name){
            courseList[i].ifFinished = true;
            return;
        }
    }
}