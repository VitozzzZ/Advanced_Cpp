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
 
