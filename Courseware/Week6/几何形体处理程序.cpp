/*****
几何形体处理程序: 
输入若干个几何形体的参数， 要求按面积排序输出。输出时要指明形状。
Input:
第一行是几何形体数目n(不超过100).下面有n行，每行以一个字母c开头.
若 c 是 ‘R’，则代表一个矩形，本行后面跟着两个整数，分别是矩形的宽和高; 
若 c 是 ‘C’，则代表一个圆，本行后面跟着一个整数代表其半径
若 c 是 ‘T’，则代表一个三角形，本行后面跟着三个整数，代表三条边的长度
Output:
按面积从小到大依次输出每个几何形体的种类及面积。每行一个几何形体，输 出格式为:
形体名称:面积
Sample Input:
3
R3 5 
C9 
T3 4 5
Sample Output
Triangle:6 
Rectangle:15 
Circle:254.34
*****/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class CShape{
public:
    virtual double Area()=0;   //纯虚函数
    virtual void PrintInfo()=0;
};
class CRectangle:public CShape{
public:
    int w,h;
    virtual double Area();
    virtual void PrintInfo();
};
class CCircle:public CShape {
public:
    int r;
    virtual double Area();
    virtual void PrintInfo();
};
class CTriangle:public CShape {
public:
    int a,b,c;
    virtual double Area();
    virtual void PrintInfo();
};
double CRectangle::Area(){
    return w*h;
}
void CRectangle::PrintInfo(){
    cout<<"Rectangle"<<Area()<<endl;
}
double CCircle::Area(){
    return 3.14*r*r;
}
void CCircle::PrintInfo() {
    cout << "Circle:" << Area() << endl;
}
double CTriangle::Area() {
    double p = ( a + b + c) / 2.0;
    return sqrt(p * ( p - a)*(p- b)*(p - c));
}
void CTriangle::PrintInfo() {
    cout << "Triangle:" << Area() << endl;
}
CShape * pShapes[100];
/*用基类指针数组存放指向各种派生类对象的指
 针，然后遍历该数组，就能对各个派生类对象
 做各种操作，是很常用的做法*/
int MyCompare(const void *s1,const void *s2){  // s1,s2指向pShapes数组中的元素，数组元素的类型是CShape*
    double a1,a2;
    CShape ** p1=(CShape **)s1;  //由于s1,s2是void*,不可以写出*s1来取代s1指向的内容,故强制类型转换
    CShape ** p2=(CShape **)s2;  //使*p1 *p2的类型是CShape*（基类指针）
    a1=(*p1)->Area();    //多态
    a2=(*p2)->Area();    //多态
    if(a1<a2)
        return -1;
    else if(a2<a1)
        return 1;
    else
        return 0;
}
int main(){
    int i;int n;
    CRectangle * pr; CCircle * pc; CTriangle * pt;
    cin>>n;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        switch (c) {
            case 'R':
                pr=new CRectangle();
                cin>>pr->w>>pr->h;
                pShapes[i]=pr;
                break;
            case 'C':
                pc = new CCircle();
                cin >> pc->r;
                pShapes[i] = pc;
                break;
            case 'T':
                pt = new CTriangle();
                cin >> pt->a >> pt->b >> pt->c;
                pShapes[i] = pt;
                break;
        }
    }
    qsort(pShapes, n, sizeof(CShape*), MyCompare);
    for(i=0;i<n;i++){
        pShapes[i]->PrintInfo();
    }
    return 0;
}
