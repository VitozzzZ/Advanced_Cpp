#include <iostream>
using namespace std;
class Complex{
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i){ };
    Complex operator+(double r);
};
Complex Complex::operator+(double r){ //能解释 c+5
    return Complex(real + r, imag); }
int main(){
    Complex c(0,1);
    c=c+5;  //c.operator+(5)
    c=5+c;  //5.operator+(c) 报错
}


//修改
#include <iostream>
using namespace std;
class Complex{
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i){ };
    Complex operator+(double r);
    friend Complex operator+ (double r, const Complex & c) { //能解释 5+c
        return Complex( c.real + r, c.imag); }
};
Complex Complex::operator+(double r){ //能解释 c+5
    return Complex(real + r, imag); }
int main(){
    Complex c(0,1);
    c=c+5;
    c=5+c;   //operator+(5,c)
}
