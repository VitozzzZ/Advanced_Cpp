#include <iostream>
#include <string>

using namespace std;

char &get_val(string &str, int ix)  
{
    return str[ix];
}

int main()
{
    string s("a value");
    cout << s << endl;
    
    get_val(s, 0) = 'A';  
    cout << s << endl;
    
    return 0;
}

/*****
对&和const的彻底理解
参数中
1.第六行处 string &str 若不加&的话，str则被复制一份，函数中对str的操作实质上是对其复制品的操作，原str的值并不会改变。
  就本题来说的话，输出2行a value
2.加&的话，传入的str即是调用层的实际参数，这样省去了复制过程，效率会提高，并且如果函数中修改了str，str就会变。
3.如果变成 const string &str，编译出错，因为const类型的str不可以作为函数返回值（const类型不可以赋值给非const）
函数中
1.第六行处 char &get_val 可以想象成函数在返回str[ix]的同时也返回了它的地址，其实和参数中的&类似，可以被修改，可以作为左值。
2.char get_val不能作为左值，函数会返回一个str[ix]的复制品
3.const char &get_val同样不能作为左值因为加了const限定不能被修改，但不会产生str[ix]的复制
4.const char get_val 不能作为左值 函数返回str[ix]的复制但不能被修改
*****/
