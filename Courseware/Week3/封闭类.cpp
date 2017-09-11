//封闭类构造函数的初始化列表 类名::构造函数(参数表):成员变量1(参数表),成员变量2(参数表),...{}
#include <iostream>
using namespace std;
class CTyre{
private:
    int radius;
    int width;
public:
    CTyre(int r ,int w):radius(r),width(w){}  //初始化列表
};
class CEngine{
};
class CCar{         //封闭类
private:
    int price;
    CTyre tyre;
    CEngine engine;
public:
    CCar(int p,int tr,int tw);
};
CCar::CCar(int p,int tr,int w):price(p),tyre(tr,w){};
int main(){
    CCar car(20000,17,225);
    return 0;
}
