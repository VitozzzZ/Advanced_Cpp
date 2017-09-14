//运算符重载为普通函数
class Complex{
public:
    Complex(double r=0.0,double i=0.0){
        real=r;
        imag=i;
    }
    double real;
    double imag;
};
Complex operator+(const Complex & a,const Complex & b){  //重载为普通函数时，参数个数为运算符目数
    return Complex(a.real+b.real,a.imag+b.imag);
}
Complex a(1,2),b(2,3),c;
c=a+b;


//运算符重载为成员函数
class Complex{
public:
    Complex(double r=0.0,double i=0.0):real(r),imag(i){}
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);                   //参数个数为运算符目数减一
private:
    double real;
    double imag;
};
Complex Complex::operator+(const Complex & operand2){
    return Complex(real+operand2.real,imag+operand2.imag);
}
Complex Complex::operator-(const Complex & operand2){
    return Complex(real-operand2.real,imag-operand2.imag);
}
int main(){
    Complex x,y(4.3,8.2),z(3.3,1.1);
    x=y+z;   //相当于x=y.operator+(z)
    x=y-z;   //相当于x=y.operator-(z)
    return 0;
}

//赋值运算符= 只能重载为成员函数
