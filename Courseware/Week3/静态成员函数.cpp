#include <iostream>
using namespace std;
class CRectangle{
private:
    int w,h;
    static int nTotalArea;
    static int nTotalNumber;
public:
    CRectangle(int w_,int h_);
    CRectangle(CRectangle&r){
        w=r.w,h=r.h;
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
int CRectangle::nTotalArea=0;
int main(){
    CRectangle r1(3,3),r2(2,2);
    CRectangle::PrintTotal();
    r1.PrintTotal();
    return 0;
}
