#include<iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    double radius;
    Point pnt;
public:
    void Init(int x, int y, int r)
    {
        pnt.Init(x,y);
        radius = r;
    }
    void ShowCircleInfo() const
    {
        cout<<"radius: "<<radius<<endl;
        pnt.ShowPointInfo();
    }
};
class Ring
{
private:
    Circle circ;
    Circle circ2;
public:
    void Init(int a, int b, int c, int d, int e, int f)
    {
        circ.Init(a, b, c);
        circ2.Init(d,e,f);
    }
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        circ.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        circ2.ShowCircleInfo();
    }
};

int main()
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();

    return 0;
}