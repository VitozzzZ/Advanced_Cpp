#include <iostream>
#include <string>
using namespace std;
class CDemo{
private:
    int n;
public:
    CDemo(int i=0):n(i){}
    CDemo & operator++();           //用于前置++，成员函数
    CDemo operator++(int);          //用于后置++，成员函数
    operator int(){return n;}       //*****用于直接cout CDemo
    friend CDemo & operator--(CDemo &);     //用于前置--，非成员函数
    friend CDemo operator--(CDemo &,int);   //用于后置--，非成员函数
};
CDemo & CDemo::operator++(){     //前置++
    n++;
    return *this;
}
CDemo CDemo::operator++(int){  //后置++
    CDemo tmp(*this);            //记录修改前的对象
    n++;
    return tmp;                  //返回修改前的对象
}
CDemo & operator--(CDemo & d){   //前置--
    d.n--;
    return d;
}
CDemo operator--(CDemo & d,int){
    CDemo tmp(d);
    d.n--;
    return tmp;
}
int main(){
    CDemo d(5);
    cout << (d++) << ",";  //等价于 d.operator++(0);
    cout << d << ",";
    cout << (++d) << ",";  //等价于 d.operator++();
    cout << d << endl;
    cout << (d--) << ",";  //等价于 operator--(d,0);
    cout << d << ",";
    cout << (--d) << ",";  //等价于 operator--(d);
    cout << d << endl;
    return 0;
}
