//
// Created by 王予亮 on 2018/5/17.
//
#include<iostream>
#include<stdio.h>
#include<vector>
#include"Read.h"
#include"Schedule.h"
#include"Generater.h"

vector<_course> HandleData(string path){
    vector<string> info = ReadData2str(path);
    vector<_course> result = str2course(info);
    return result;
}
using namespace std;
int main(int argc, char* argv[]){
    Generater gen(5,10);
    vector<_course> testList = gen.Generate();
    vector<_course> courseList = HandleData("/Users/drakewong/Desktop/OS_homework_2/course.txt");
    Schedule HandlerA(courseList), HandlerB(courseList), HandlerC(courseList), HandlerD(courseList);
    //showCourse(courseList);
    //Handler.FCFS();
    //Handler.RR(4);
    //Handler.SJF();
    //cout<<"Random List"<<endl;
    //showCourse(testList);
    //cout<<"~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
//    HandlerA.FCFS();
//    HandlerA.showResult();
//    HandlerB.SJF();
//    HandlerB.showResult();
//    HandlerC.RR(1);
//    HandlerC.showResult();
    HandlerD.RR(1);
    HandlerD.showResult();
    return 0;
}