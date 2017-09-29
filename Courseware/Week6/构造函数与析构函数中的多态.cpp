/********
在构造函数和析构函数中调用虚函数，不是多态。编译时即可确定，调用的函数是自
己的类或基类中定义 的函数,不会等到运行时才决定调用自己的还是派生类的函数。
*********/

#include <iostream>
using namespace std;
class myclass {
public:
    virtual void hello(){cout<<"hello from myclass"<<endl;}
    virtual void bye(){ cout<<"bye from myclass"<<endl;}
};
class son:public myclass{
public:
    void hello(){ cout<<"hello from son"<<endl;}  //派生类中和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数
    son(){ hello(); }
    ~son(){ bye(); }
};
class grandson:public son{
public:
    void hello(){cout<<"hello from grandson"<<endl;}
    void bye() { cout << "bye from grandson"<<endl;}
    grandson(){cout<<"constructing grandson"<<endl;}
    ~grandson(){cout<<"destructing grandson"<<endl;}
};
int main(){
    grandson gson; //自顶向下调用构造函数
    son *pson;
    pson=&gson;
    pson->hello(); //多态
    return 0;
}
/*输出
hello from son
constructing grandson
hello from grandson
destructing grandson
bye from myclass
*/
