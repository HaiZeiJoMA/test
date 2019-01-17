/*************************************************************************
	> File Name: 多继承带来问题-1一个对象多个地址.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:25:55 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class A {
    private:
        string name;
        int age;
    public:
    void print() {
        cout << name << " " << age << endl;
    }
};
class B : public A {};
class C : public A {};
class D : public C, public B {};
int main() {
    D d;
    A *a = &d;
    B *pb = &d;
    C *pc = &d;
    void *pbb = pb;
    void *pcc = pc;
    if(pbb == pcc) {
        cout << "point the same address!" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "B : " << pb << " " << pbb << endl;
    cout << "C: "<< pc << " " << pcc << endl;
    cout << &d << endl;
    return 0;
}

