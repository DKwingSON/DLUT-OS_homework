#ifndef OS_HW_2_READ_H
#define OS_HW_2_READ_H

#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

typedef struct{
    string CourseName;
    int arriveTime;
    int serveTime;
    int waitingTime;
    bool ifFinished;
    //bool ifStarted;
}_course;

vector<string> split(string& str,const char* c);
vector<string> ReadData2str(string const path);
vector<_course> str2course(vector<string> info);
void showCourse(vector<_course> list);
#endif