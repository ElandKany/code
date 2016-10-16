#include <iostream>

#define PI  3.1415926

using namespace std;


struct Circle{
    float  radius;

    float Circunference(){
        return radius * 2 * PI;
    }

    double CirArea()
    {
        return radius * radius * PI;
    }
};

inline double getArea(Circle * p_circle)
{
    return  p_circle->CirArea();
}

inline float getLength(Circle * p_circle)
{
    return p_circle->Circunference();
}
int main()
{
    float radius;
    cout << "Please input the Radius : " ;
    cin>>radius;

    Circle Pool = {radius};
    Circle Poolin = {radius + 3};

    cout<<"The Area of Pool         = " << getArea(&Pool)<< endl;
    cout<<"The Length of Pool     = " << getLength(&Pool)<< endl;
    cout<<"The Area of Poolin      = " << getArea(&Poolin)<< endl;
    cout<<"The Length of Poolin  = " << getLength(&Poolin)<< endl;


    return 0;
}
