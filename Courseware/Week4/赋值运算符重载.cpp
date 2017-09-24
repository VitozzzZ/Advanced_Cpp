#include <iostream>
using namespace std;
class String{
private:
    char *str;
public:
    String():str(NULL){}     //构造函数 初始化str为NULL
    const char*c_str(){return str;}
    char* operator =(const char* s);
    ~String();
};
char* String::operator=(const char *s){    //浅拷贝
    if(str)
        delete []str;
    if(s){
        str= new char[strlen(s)+1];
        strcpy(str,s);
    }
    else
        str=NULL;
    return str;
}
String::~String(){
    if(str) delete []str;
}
int main(){
    String s;
    s="Good Luck";
    cout<<s.c_str()<<endl;
    s="zsq";
    cout<<s.c_str()<<endl;
    return 0;
}


String & String::operator =(const String &s){   //深拷贝
    if(str==s.str)
        return *this;
    if(str)
        delete []str;
    if(s.str){
        str=new char[strlen(s.str)+1];
        strcpy(str,s.str);
    }
    else
        str=NULL;
    return *this;
}
