#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
private:
    int * a;
    int i, j;
public:
    Array2() {a = NULL;}
    Array2(int i_, int j_) {
        i = i_;
        j = j_;
        a = new int[i*j];
    }
    Array2(Array2 &t){
        i = t.i;
        j = t.j;
        a = new int[i * j];
        memcpy(a, t.a, sizeof(int)*i*j);
    }
    Array2 & operator=(const Array2 &t) {
        if (a != NULL) delete []a;
        i = t.i;
        j = t.j;
        a = new int[i*j];
        memcpy(a, t.a, sizeof(int)*i*j);
        return *this;
    }
    ~Array2() {if (a != NULL) delete []a;}
    // 将返回值设为int的指针，则可以应用第二个【】，不用重载第二个【】操作符
    int *operator[](int i_) {
        return a+i_*j;
    }
    int &operator()(int i_, int j_) {
        return a[i_*j + j_];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
