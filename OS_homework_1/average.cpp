#include<iostream>
#include<math.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char const *argv[]){
	double result = 0;
	double a = 0, b = 0, c = 0;
	cout<<"  Average Installed"<<endl;
	cout<<"  PID: "<<getpid()<<endl;
	if(argc != 4){
		cout<<"  Invalid Argument"<<endl;
		return -1;
	}
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	result = (a+b+c) / 3;
	cout<<"  Result: "<<result<<endl;
	return 0;
}
