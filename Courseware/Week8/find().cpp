//template<class InIt, class T>
//InIt find(InIt first, InIt last, const T& val);
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() { //find算法示例
    int array[10] = {10,20,30,40};
    vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); //v={1,2,3,4}
    vector<int>::iterator p;
    p = find(v.begin(),v.end(),3);
    if( p != v.end())
        cout << * p << endl; //输出3
    p = find(v.begin(),v.end(),9);
    if( p == v.end())
        cout << "not found " << endl;
    p = find(v.begin()+1,v.end()-2,1); //整个容器:[1,2,3,4]， 查找区间:[2,3)
    if( p != v.end())  //p指向3
    cout << * p << endl;
    int * pp = find( array,array+4,20);//数组名是迭代器 cout << * pp << endl;
    cout<< *pp<<endl;
}
