/******
构造函数
 vector();                             无参构造函数, 将容器初始化成空的
 vector(int n);                        将容器初始化成有n个元素
 vector(int n, const T & val);         假定元素类型是T, 将容器初始化成 有n个元素, 每个元素的值都是val
 vector(iterator first, iterator last);将容器初始化为与别的容器上区间 [first, last)一致的内容
常用函数
 void pop_back();              删除容器末尾的元素
 void push_back(const T & val);将val添加到容器末尾
 int size();                   返回容器中元素的个数
 T & front();                  返回容器中第一个元素的引用
 T & back();                   返回容器中最后一个元素的引用

******/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i;
    int a[5]={1,2,3,4,5};
    vector<int> v(5);
    cout<<v.end()-v.begin()<<endl; //数组长度
    for(i=0;i<v.size();i++)
        v[i]=i;
    v.at(4)=100;
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    vector<int> v2(a,a+5);      //第四种构造函数
    v2.insert(v2.begin()+2,13);
    for(i=0;i<v2.size();i++)
        cout<<v2.at(i)<<" ";
    cout<<endl;
}
/******
二维动态数组 vector<vector<int>> v(3)
v有三个元素 每个元素都是vector<int>容器
******/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> v(3);
    for(int i=0; i<v.size(); ++i)
        for(int j=0; j<4; ++j)
        v[i].push_back(j);
    for(int i=0; i<v.size(); ++i){
            for(int j=0; j<v[i].size(); ++j)
                cout<<v[i][j]<<" ";
            cout<<endl;
        
    }
    return 0;
}
