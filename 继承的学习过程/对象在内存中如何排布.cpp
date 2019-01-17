/*************************************************************************
	> File Name: 对象在内存中如何排布.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:24:35 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Test{
    private:
        int i;
        int j;
    public:
    Test(int v1 = 0, int v2 = 0) {
        i = v1;
        j = v2;
    }
    int getI() {
        return i;
    }
    int getJ() {
        return j;
    }
    int add(int value) {
        return i + j + value;
    }
    ~Test() {

    }
};

class A {
    int a;
    int b;
    char c;
    double d;
    public:
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }
};

struct B {
    int a;
    int b;
    char c;
    double d;
};

int main() {
    A a1;
    B *p = reinterpret_cast<B*>(&a1);
    cout << "befor.." << endl;
    a1.print();
    cout << "after.." << endl;
    p->a = 100;
    p->b = 1000;
    p->c = 'C';
    p->d = 3.14;
    a1.print();
    /*
    Test a1(1, 2);
    cout << sizeof(A) << "  " << sizeof(B) << endl;
    cout << a1.getI() << endl;
    cout << a1.getJ() << endl;
    cout << a1.add(5) << endl;
    */
    return 0;
}

