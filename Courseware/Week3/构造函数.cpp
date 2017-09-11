//构造函数 成员函数的一种 名字与类名相同，可以有参数，不能有返回值(void也不行),作用是对对象进行初始化，如给成员变量赋初值
//构造函数最好设在public下

#include <iostream> 
using namespace std;
class Complex {
private :
    double real, imag;
public:
    void Set( double r, double i );
    Complex(double r, double i );
    Complex (double r );
    Complex (Complex c1, Complex c2);
};
Complex::Complex(double r, double i) {
    real = r; imag = i;
}
Complex::Complex(double r) {
    real = r; imag = 0; }
Complex::Complex (Complex c1, Complex c2)
{
    real = c1.real+c2.real;
    imag = c1.imag+c2.imag; }
Complex c1(3) , c2 (1,0), c3(c1,c2);
// c1 = {3, 0}, c2 = {1, 0}, c3 = {4, 0};


#include<iostream>
using namespace std;
class CSample{
    int x;
public:
    CSample(){
        cout<<"Constructor1 Called"<<endl;
    }
    CSample(int n){
        x=n;
        cout<<"Constructor2 Called"<<endl;
    }
};
int main(){
    CSample array1[2];
    cout<<"step1"<<endl;
    CSample array2[2]={4,5};
    cout<<"step2"<<endl;
    CSample array3[2]={3};
    cout<<"step3"<<endl;
    CSample * array4=new CSample[2];
    delete []array4;
    return 0;
}


//复制构造函数
//系统默认
class Complex{
private:
    double real,imag;
};
Complex c1;//调用缺省无参构造函数
Complex c2(c1);//调用缺省复制构造函数，将c2初始化成c1一样 等价于Complex c2=c1(初始化语句非赋值语句）

//自己编写
class Complex{
public:
    double real,imag;
Complex(){}
Complex(const Complex&c){
    real=c.real;
    imag=c.imag;
    cout<<"Copy Constructor called";
}
    
};
Complex c1;
Complex c2(c1);//输出Copy Constructor called

/*复制构造函数起作用的三种情况
1.用一个对象去初始化同类的另一个对象时
Complex c2(c1) 或者 Complex c2=c1
2.如果某函数有一个参数是类A的对象，调用该函数时，类A的复制构造函数也会被调用，去初始化这个参数*/
class A{
public:
    A(){};
    A(A&a){
        cout<<"Copy constructor called"<<endl;
    }
};
void Func(A a1){}
int main(){
    A a2;
    Func(a2);//输出Copy constructor called
    return 0;
}
//3.如果函数的返回值是类A的对象，则函数返回时，A的复制构造函数会被调用，去初始化以返回值存在的类A的对象
#include <iostream>
using namespace std;
class A{
public:
    int v;
    A(int n){v=n;}
    A(const A&a){
        v=a.v;
        cout<<"Copy constructor called"<<endl;
    }
};
A Func(){
    A b(4);
    return b;
}
int main(){
    cout<<Func().v<<endl;
    return 0;
}


//强制类型转换构造函数

#include <iostream>
using namespace std;
class Complex{
public:
    double real,imag;
    Complex(int i){  //类型转换构造函数
        cout<<"IntConstructor called"<<endl;
        real=i;imag=0;
    }
    Complex(double r ,double i){
        real=r;imag=i;
    }
};
int mian(){
    Complex c1(7,8);
    Complex c2(12);
    c1=9; //9被自动转换成一个临时Complex对象
    cout<<c1.real<<","<<c1.imag<<endl;
    return 0;
}
