#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int main(int argc, char const *argv[]){
	double result = 0;
	double a = 0, b = 0;
	cout<<"  Max Installed"<<endl;
	cout<<"  PID: "<< getpid()<<endl;
	if(argc!=3){
		cout<<"  Invalid Argument"<<endl;
		return -1;
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = (a>=b?a:b);
	cout<<"  Result: "<<result<<endl;
	return 0;
}       
