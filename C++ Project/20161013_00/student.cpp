#include <iostream>
#include <cstring>
#include "project_common.h"
#include "student.h"

using namespace std;

double Student::Average(int& Chinese, int& Math, int& English)
{
    double sum = 0;
    if(Chinese < 0 || Math < 0 || English < 0 || Chinese > 150 || Math > 150 || English > 150)
    {
        return ret_invalid;
    }
    else
    {
        sum = Sum(Chinese, Math, English);
        return sum / 3;
    }
}

double Student::Sum(int& Chinese, int& Math, int& English)
{
    if(Chinese < 0 || Math < 0 || English < 0 || Chinese > 150 || Math > 150 || English > 150)
    {
        return ret_invalid;
    }
    else
    {
        return Chinese + Math + English;
    }
}


void Student::showStudentInfo()
{
    double Sum_mark = Sum(Chinese, Math, English);
    double Average_mark = Average(Chinese, Math, English);

    cout << "Current Student Name is: " << Name
         << " , Chinese Mark = " << Chinese
         << " , Math Mark = " << Math
         << " , English Mark = " << English
         << " , Sum Mark = " << Sum_mark
         << " , Average Mark = " << Average_mark << endl;
}

Status Student::setStudentInfo(const char* name, int& chinese, int& math, int& english)
{
    if(chinese < 0 || math < 0 || english < 0 || chinese > 150 || math > 150 || english > 150)
    {
        return ret_invalid;
    }
    else if(name == NULL)
    {
        return ret_invalid;
    }
    else
    {
        strcpy(Name, name);
        Chinese = chinese;
        Math = math;
        English = english;
    }
    return ret_success;
}
