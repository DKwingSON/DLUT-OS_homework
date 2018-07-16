//
// Created by 王予亮 on 2018/5/15.
//
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include "Read.h"
using namespace std;

vector<string> split(string& str,const char* c)
{
    char *cstr, *p;
    vector<string> result;
    cstr = new char[str.size()+1];
    strcpy(cstr,str.c_str());
    p = strtok(cstr,c);
    while(p!=NULL)
    {
        result.push_back(p);
        p = strtok(NULL,c);
    }
    return result;
}
vector<string> ReadData2str(string const path){
	int i = 0;
	vector<string> result;
	ifstream fin(path);
	string s;
	cout<<"Read from: "<<path<<endl;
	while(getline(fin,s)){
		cout<<i++<<": "<<s<<endl;
		result.push_back(s);
	}
	return result;
}
vector<_course> str2course(vector<string> info){
	vector<_course> result;
	for(int i = 0;i<info.size();i++){
		vector<string> spinfo = split(info.at(i)," ");
		_course temp;
		temp.CourseName = spinfo.at(0);
		temp.arriveTime = atoi(spinfo.at(1).c_str());
		temp.serveTime = atoi(spinfo.at(2).c_str());
        temp.waitingTime = 0;
        temp.ifFinished = false;
        //temp.ifStarted = false;
		result.push_back(temp);
	}
	return result;
}
void showCourse(vector<_course> list){
    _course temp;
    cout<<"~~~~~~~~~~~"<<endl;
    for(int i=0;i<list.size();i++){
        temp = list[i];
        cout<<"Name:"<<temp.CourseName
            <<", ArriveTime:"<<temp.arriveTime
            <<", ServiceTime:"<<temp.serveTime
            <<", WaitingTime:"<<temp.waitingTime
            <<", ifFinished:"<<temp.ifFinished
            //<<", ifStarted:"<<temp.ifStarted
            <<endl;
    }
    cout<<"~~~~~~~~~~~"<<endl;
}

