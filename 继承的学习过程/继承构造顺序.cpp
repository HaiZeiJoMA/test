/*************************************************************************
	> File Name: 继承构造顺序.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:21:31 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Parent {
    protected:
        int i;
    public:
    Parent(int v = 0) {
        i = v;
    }
};
class Child : public Parent {
    public:
    Child() : Parent(5){
        cout << "Child()" << endl;
    }
    int getI() {
        return i;
    }
};
class A {
    public:
        A() {
            cout << "A()" << endl;
        }
};
class B : public A {
    public:
        B() {
            cout << "B()" << endl;
        }
};
class C {
    public:
        C() {
            cout << "C()" << endl;
        }       
};
class D : public C {
    private:
        B b;
    public:
    D() {
        cout << "D()" << endl;
    }
        
};

int main() {
    D d;
    return 0;
}


