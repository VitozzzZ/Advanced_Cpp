#include <iostream>
using namespace std;
class CRectangle{
private:
    int w,h;
    static int nTotalArea;
    static int nTotalNumber;
public:
    CRectangle(int w_,int h_);
    CRectangle(CRectangle&r){   //复制构造函数
        w=r.w;
        h=r.h;
        nTotalNumber++;
        nTotalArea+=w*h;
    }

    ~CRectangle();
    static void PrintTotal();
};
CRectangle::CRectangle(int w_,int h_){
    w=w_;
    h=h_;
    nTotalNumber++;
    nTotalArea+=w*h;
}
CRectangle::~CRectangle(){
    nTotalNumber--;
    nTotalArea-=w*h;
}
void CRectangle::PrintTotal(){
    cout<<nTotalNumber<<","<<nTotalArea<<endl;
}
int CRectangle::nTotalNumber=0;
int CRectangle::nTotalArea=0;  // 必须在定义类的文件中对静态成员变量进行一次说明或初始化。否则编译能通过，链接不能通过。
int main(){
    CRectangle r1(3,3),r2(2,2);
    CRectangle::PrintTotal();
    r1.PrintTotal();
/*****
 如何访问静态成员
1) 类名::成员名  CRectangle::PrintTotal();
2) 对象名.成员名 CRectangle r; r.PrintTotal(); 
3) 指针->成员名  CRectangle * p = &r; p->PrintTotal(); 
4) 引用.成员名   CRectangle & ref = r; int n = ref.nTotalNumber;
*****/
    return 0;
}
