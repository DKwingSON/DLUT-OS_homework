#ifndef OS_HW_2_GENERATER_H
#define OS_HW_2_GENERATER_H
#include"Schedule.h"
#include"Read.h"
#include<string>
#include<vector>
class Generater{
    int maxsize;
    int minsize;
    int listsize;
    vector<_course> courseList;

    //void Generate_course(int size);
public:
    vector<_course> Generate();
    Generater();
    Generater(int min = 5, int max = 15);
};
#endif //OS_HW_2_GENERATER_H
