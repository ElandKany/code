#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "project_common.h"

class Student
{
private:                //私有成员变量
    char     Name[30];  //name
    int      Chinese;   //语文成绩
    int      Math;      //数学成绩
    int      English;   //英语成绩

private:                //私有接口
    double    Average(int& Chinese, int& Math, int& English);                        //计算平均成绩
    double    Sum(int& Chinese, int& Math, int& English);                            //计算总成绩

public:                 //公共接口
    void      showStudentInfo();                                                            //展示学生信息
    Status    setStudentInfo(const char* name, int& chinese, int& math, int& english);     //填充学生信息
};

#endif // STUDENT_H_INCLUDED
