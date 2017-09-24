#include <iostream>
using namespace std;
class CStudent{
public:
    int nAge;
};
ostream & operator<<(ostream & o,const CStudent &s){
    o<<s.nAge;
    return o;
}
int main(){
    CStudent s ;
    s.nAge = 5;
    cout << s <<"hello"<<endl;
    return 0;
}



#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex {
    double real,imag;
public:
    Complex( double r=0, double i=0):real(r),imag(i){ };
    friend ostream & operator<<( ostream & os,const Complex & c);
    friend istream & operator>>( istream & is,Complex & c);
};
ostream & operator<<( ostream & os,const Complex & c)
{
    os << c.real << "+" << c.imag << "i"; //以"a+bi"的形式输出
    return os;
}
istream & operator>>( istream & is,Complex & c)
{
    string s;
    is >> s; //将"a+bi"作为字符串读入, “a+bi” 中间不能有空格
    unsigned long pos = s.find("+",0);
    string sTmp = s.substr(0,pos); //分离出代表实部的字符串
    c.real = atof(sTmp.c_str());//atof库函数能将const char*指针指向的内容转换成float
    sTmp = s.substr(pos+1, s.length()-pos-2); //分离出代表虚部的字符串
    c.imag = atof(sTmp.c_str());
    return is; }
int main() {
    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}
