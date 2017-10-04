//C++ string类的初步实现


#include <stdio.h>
#include <string.h>
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
    printf("%s", s.c_str());
    s="zsq";
    printf("%s", s.c_str());
    return 0;
}


String & String::operator =(const String &s){   //深拷贝
    if(str==s.str)    //解决s=s的bug
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
