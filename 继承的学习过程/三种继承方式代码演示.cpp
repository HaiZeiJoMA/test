/*************************************************************************
	> File Name: 三种继承方式代码演示.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:19:51 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Parent {
    private :
        int a;
    public :
        int b;
        void set(int v1, int v2, int v3) {
            a = v1;
            b = v2;
            c = v3;
        }
    protected :
        int c;

};

class Child1 : public Parent {
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};

class Child2 : private Parent {
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};

class Child3 : protected Parent {
    public:
    void print() {

    }
};

class Test : public Child3 {
    void set(int v) {
        b = v;
    }
};

int main() {
    Child2 c;
    Child3 c1;
    c1.b = 100;
    return 0;
}

