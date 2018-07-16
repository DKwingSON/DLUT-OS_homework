#include<iostream>
#include<unistd.h>
#include<string>
#include<vector>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
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
int switchCharP(char const *argv){
	if(!strncmp(argv,"avg",3)) return 1;
	if(!strncmp(argv,"max",3)) return 2;
	if(!strncmp(argv,"min",3)) return 3;
	if(!strncmp(argv,"exit",4)) return 0;
	return -1;
}
int switchString(string argv){
	if(argv == "avg"||argv=="AVG") return 1;
	if(argv == "max"||argv=="MAX") return 2;
	if(argv == "min"||argv=="MIN") return 3;
	if(argv == "exit"||argv =="exit()"||argv=="EXIT") return 0;
	return -1;
}
int main(int argc, char const *argv[]){
	vector<string> input;
	string s;
	int status;
	//char *p = (char*)malloc(sizeof(char)*10);
	//pid_t pid1;
	cout<<"HQ@SHELL: Running in PID: "<<getpid()<<endl;
	cout<<"HQ@SHELL>";
	while(getline(cin,s)){
		input = split(s," ");
		if(input.at(0) == "exit"){
			cout<<"  BYB~"<<endl;
			exit(0);
		}
		if(fork() == 0) {
			switch (switchString(input[0])) {
				case 1: {
					if(input.size()!=4) {
						cout << "  Invalid Argument" << endl;
						exit(0);
					}
					execlp("/Users/drakewong/Desktop/OS_homework_1/average", "./average", input.at(1).c_str(),
						   input.at(2).c_str(), input.at(3).c_str(),
						   NULL);
					exit(0);

				}
				case 2: {
					if(input.size()!=3){
						cout<<"  Invalid Argument"<<endl;
						exit(0);
					}
					execlp("/Users/drakewong/Desktop/OS_homework_1/max", "./max", input.at(1).c_str(),
						   input.at(2).c_str(), NULL);
					exit(0);

				}
				case 3: {
					if(input.size()!=3){
						cout<<"  Invalid Argument"<<endl;
						exit(0);
					}
					execlp("/Users/drakewong/Desktop/OS_homework_1/min", "./min", input.at(1).c_str(),
						   input.at(2).c_str(), NULL);
					exit(0);
				}
				default: {
					cout << "  Undefined Command" << endl;
					exit(0);
				}
			}
		}
		//sleep(1);
		wait(&status);
		//cout<<"status"<<status<<endl;
		cout<<"HQ@SHELL>";
	}
	return 0;
}

