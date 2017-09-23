//非引用的函数返回值不可以作为左值使用
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
    
    get_val(s, 0) = 'A';  //若改成const char 这里会报错
    cout << s << endl;
    
    return 0;
}
