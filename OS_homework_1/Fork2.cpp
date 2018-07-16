#include<iostream>
#include<math.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char* const argv[]){
	pid_t pid1, pid2;
	pid1 = fork();
	if(pid1 == 0){
		pid2 = fork();
		if(pid2 == 0){
			cout<<"This is grandson"<<endl;
			cout<<"My pid is "<<getpid()<<endl<<endl;
			return 0;
		}
		else{
			cout<<"This is son"<<endl;
			cout<<"My pid is "<<getpid()<<endl;
			cout<<"My son's pid is "<<pid2<<endl<<endl;
			return 0;
		}
	}
	else{
		cout<<"This is father"<<endl;
		cout<<"My pid is "<<getpid()<<endl;
		cout<<"My son's pid is "<<pid1<<endl<<endl;
	}
	return 0;
}
