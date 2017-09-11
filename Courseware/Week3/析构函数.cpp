//析构函数  成员函数的一种  名字与类名相同 没有参数和返回值
class String{
private:
    char *p;
public:
    String(){
        p=new char[10];
    }
    ~String();
};
String::~String(){
    delete []p;
}

//典例

#include <iostream>
using namespace std;
class Demo {
    int id;
public:
    Demo( int i ) {
        id = i;
        cout<<"id="<<id<<"Constructed"<<endl;
    }
    ~Demo() {
    cout<<"id="<<id<<"Destructed"<<endl;
    }
};
Demo d1(1);
void Func(){
    static Demo d2(2);
    Demo d3(3);
    cout<<"Func"<<endl;
}
int main (){
    Demo d4(4); d4 = 6;
    cout<<"main"<<endl;
    { Demo d5(5); }
    Func();
    cout<<"main ends"<<endl;
    return 0;
}
/*输出
id=1Constructed
id=4Constructed
id=6Constructed
id=6Destructed
main
id=5Constructed
id=5Destructed
id=2Constructed
id=3Constructed
Func
id=3Destructed
main ends
id=6Destructed
id=2Destructed
id=1Destructed
*/
