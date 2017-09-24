#include <iostream>
using namespace std;
class Father {
private:
    int nPrivate; //私有成员
public:
    int nPublic; //公有成员
protected:
    int nProtected; // 保护成员
};
class Son :
public Father {
    void AccessFather () {
        nPublic = 1; // ok;
        nPrivate = 1; // wrong
        nProtected = 1; // OK, 访问从基类继承的protected成员(派生类的成员函数可以访问当前对象的基类的保护成员)
        Son f;
        f.nProtected = 1; //wrong, f不是当前对象
    }
};

int main(){
    Father f;
    Son s;
    f.nPublic = 1; // Ok
    s.nPublic = 1; // Ok
    f.nProtected = 1; // error
    f.nPrivate = 1; // error
    s.nProtected = 1; //error
    s.nPrivate = 1; // error
    return 0;
}
