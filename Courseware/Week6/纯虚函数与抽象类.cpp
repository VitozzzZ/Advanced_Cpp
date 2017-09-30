#include <iostream>
using namespace std;
class A{
public:
    virtual void f()=0;  //纯虚函数
    void g(){this->f();} //抽象类的成员函数能够调用纯虚函数
    A(){}                //抽象类的构造析构函数不能够调用纯虚函数
};
class B:public A{
public:
    void f(){cout<<"B:f()"<<endl;} //实现了纯虚函数故B不再是抽象类
};
int main(){
    B b;
    b.g();    //输出B:f()
    return 0;
}
