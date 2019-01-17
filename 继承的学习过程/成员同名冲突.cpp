/*************************************************************************
	> File Name: 成员同名冲突.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:22:57 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class A {
    public:
        int i;
    public:
    A(int v = 0) {
        i = v;
    }
    int add(){
        return i + 1;
    }
    int add(int a, int b, int c) {
        return i + a + b + c;
    }
    int get() {
        cout << "A::i = " << i << endl;
        return i;
    }
    void say() {
        cout << "hello i 'm a" << endl;
    }
};

class B : public A {
    public:
        int i;
    public:
    B(int v): A(0) {
        i = v;
    }
    int add(int a) {
        return i + a;
    }
    /*
    int add(int a, int b) {
        return a + b + i;
    }
    int get() {
        cout << "B::i = " << i << endl;
        return i;
    }
    */
    void say() {
        cout << "hello i'm b" << endl;
    }
};

void how_to_say(A *p) {
    p->say();
    return ;
}

int main() {
    A a(100);
    B b(3);
    cout << b.A::add() << endl; // 1
    cout << b.A::add(1, 2, 3) << endl; // 6
    cout << b.get() << endl;
    /*
    cout << b.i << endl; // 优先使用子类的属性，将父类同名属性隐藏
    b.A::i = 100000;
    cout << b.A::i << endl; // 通过作用域分辨符来指定使用父类的还是子类的<F5>
    */
    how_to_say(&a);
    how_to_say(&b);
    return 0;
}

