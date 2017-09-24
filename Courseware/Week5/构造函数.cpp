#include <iostream>
using namespace std;
//Skill
class Skill {
public:
    Skill(int n) { }
};
// Bug
class Bug {
    private :
    int nLegs; int nColor;
public:
    int nType;
    Bug (int legs, int color);
    void PrintBug () { };
};
// FlyBug
class FlyBug: public Bug {
    int nWings;
    Skill sk1, sk2;
public:
    FlyBug(int legs, int color, int wings);
};

Bug::Bug( int legs, int color) {
    nLegs = legs;
    nColor = color;
}

FlyBug::FlyBug( int legs, int color, int wings):Bug(legs, color), sk1(5), sk2(color) {
    nWings = wings;
}       //重点 注意构造函数
