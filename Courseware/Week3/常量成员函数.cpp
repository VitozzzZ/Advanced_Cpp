//常量成员函数在执行期间不能修改所作用的对象。So，也不能修改成员变量的值不能调用同类的非常量成员函数

#include <iostream>
using namespace std;
class Sample{
public:
    int value;
    void GetValue() const;
    void func();
    Sample(){};
};
void Sample::GetValue() const{
    value=0;   //wrong
    func()     //wrong
}
int main(){
    const Sample o;  
    o.value=100;   //err.常量对象不可以被修改
    o.func();      //err.常量对象上不能执行非常量成员函数
    o.GetValue();  //ok，常量对象可以执行常量成员函数
    return 0;
}
