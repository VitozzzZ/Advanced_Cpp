// 非静态成员函数中可以直接使用this来代表指向该函数作用对象的指针。

#include <iostream>
using namespace std;
class Complex{
public:
    double real,imag;
    void Print(){
        cout<<real<<","<<imag<<endl;
    }
    Complex(double r,double i):real(r),imag(i){}
    Complex AddOne(){
        this->real++;
        this->Print();
        return *this;
    }
};
int main(){
    Complex c1(1,1),c2(0,0);
    c2=c1.AddOne();
    return 0;   //输出2 1
}



#include <iostream>
using namespace std;
class A{
    int i;
public:
    void Hello(){cout<<"hello"<<endl;} //深入理解this指针，编译器在碰到非静态成员函数时会多加一个参数 即void Hello(A *this){}
};
int main(){
    A *p=NULL;
    p->Hello();   //Hello(p)
}
