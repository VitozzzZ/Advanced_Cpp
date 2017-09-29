//用法一


#include <iostream>
using namespace std;
class CBase {
public:
    virtual void SomeVirtualFunction() { }
};
class CDerived:public CBase {
public :
    virtual void SomeVirtualFunction() { }
};
int main() {
    CDerived ODerived;
    CBase * p = & ODerived;
    p -> SomeVirtualFunction(); //调用哪个虚函数取决于p指向哪种类型的对象 此处调用派生类虚函数
    return 0;
}


//用法二
#include <iostream>
using namespace std;
class CBase {
public:
    virtual void SomeVirtualFunction() { }
};
class CDerived:public CBase {
public :
    virtual void SomeVirtualFunction() { }
};
int main() {
    CDerived ODerived;
    CBase & r = ODerived;
    r.SomeVirtualFunction(); //调用哪个虚函数取决于r引用哪种类型的对象 此处调用派生类虚函数
    return 0;
}


//用法三
#include <iostream>
using namespace std;
class Base {
public:
    void fun1() { fun2(); }
    virtual void fun2() { cout << "Base::fun2()" << endl; }
};
class Derived:public Base {
public:
    virtual void fun2() { cout << "Derived:fun2()" << endl; }
};
int main() {
    Derived d;
    Base * pBase = & d;
    pBase->fun1();    //在非构造函数，非析构函数的成员函数中调用虚函数，是多态!!!
    return 0;         //会输出Derived:fun2()
}
