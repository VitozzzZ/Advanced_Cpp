class A {
public:
    int val;
    // 在此处补充你的代码
public:
    A(int n = 0)
    {
        val = n;
    }
    A& GetObj() {
        return *this;
    }
};

int main(int argc, const char * argv[]) {
    A a;
    cout << a.val << endl;
    a.GetObj() =5;
    cout << a.val << endl;
}
