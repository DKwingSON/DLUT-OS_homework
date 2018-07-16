#include<iostream>
#include<stdio.h>
#include<math.h>
#include<unistd.h>
using namespace std;
int main(){
	pid_t pid1, pid2;
	pid1 = fork();
	if(pid1 == 0){
		cout<<"This is son 1"<<endl;
		cout<<"My pid is "<<getpid()<<endl;
		return 0;
	}
	else{
		pid2 = fork();
		if(pid2 == 0){
			cout<<"This is son 2"<<endl;
			cout<<"My pid is "<<getpid()<<endl;
			return 0;
		}
		cout<<"This is father"<<endl;
		cout<<"My pid is "<<getpid()<<endl;
		cout<<"My sons' pid is "<< pid1<<" and "<<pid2<<endl;
	}
	return 0;
}
