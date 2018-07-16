#ifndef OS_HW_2_SCHEDULE_H
#define OS_HW_2_SCHEDULE_H
#include"Read.h"
using namespace std;
class Schedule{
    int RunningTime;
    vector<_course> courseList;
    int FindMaxWait(vector<_course> list);
    int FindMinServe(vector<_course> list);
    int FindMaxRes(vector<_course> list);
    void FinishCourse(string name);//对事务置结束标签
    inline void TimeFCFS(int time = 1);//运行，时间加一(或者若干)
    inline void TimeRR(int time = 1, string Name = "CAN'T BE THERE?"); //传入参数是时间片
    inline bool allFinished();//检查所有任务是否都完成了
    inline void swapRR(_course& a, _course& b);
    //bool ifempty();//检查对是否满
    void sortRR(int rear, int front, vector<_course>& list);
public:
    Schedule();
    Schedule(vector<_course> List);
    void FCFS();
    void HRRN();
    void SJF();
    void RR(int slot = 1);
    void showResult();
};

#endif