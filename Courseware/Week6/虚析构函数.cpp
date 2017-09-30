#include <iostream>
using namespace std;
class son{
public:
    ~son() { cout<<"bye from son"<<endl; }
};
class grandson : public son{
public:
    ~grandson(){ cout<<"bye from grandson"<<endl; }
};
int main() {
    son *pson;
    pson= new grandson;
    delete pson;   //会引起只析构掉*pson而不析构存放派生类对象内存空间的问题
    return 0;
}
//程序输出bye from son

#include <iostream>
using namespace std;
class son{
public:
    virtual ~son() { cout<<"bye from son"<<endl; }   //虚析构函数
};
class grandson : public son{
public:
    ~grandson(){ cout<<"bye from grandson"<<endl; }  //虚析构函数
};
int main() {
    son *pson;
    pson= new grandson;
    delete pson;
    return 0;
}
//程序输出bye from grandson
//*******bye from son
