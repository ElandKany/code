#include <iostream>
#include "project_common.h"
#include "student.h"

using namespace std;

int main()
{
    Student std1, std2;
    char name[30];
    int chinese, math, english;
    double sum, average;

    cin>>name>>chinese>>math>>english;
    int ret = std1.setStudentInfo(name, chinese, math, english);
    while(ret)
    {
        cout<<"ERROR: input student information invalid, Please input again: "<<endl;
        cin >> name>>chinese>>math>>english;
        ret = std1.setStudentInfo(name, chinese, math, english);
    }
    cout<<"set student information successfully."<<endl;
    std1.showStudentInfo();

#if 0
    cout << "Hello world!" << endl;
#endif
    return 0;
}
