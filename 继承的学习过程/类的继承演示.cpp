/*************************************************************************
	> File Name: 类的继承演示.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:15:22 2019
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public :
    Animal(string name) : __name(name) {
        cout << "Animal constructor" << endl;
    }
    void set_name(string name) {
        this->__name = name;
    }
    void tell_me_your_name() {
        cout << "my name is : " << this->__name << endl;
    }
protected :
    string __name;
};

class Cat : protected Animal {
public :
    Cat() : Animal("temp_name") {
        this->tail = 1;
        cout << "Cat constructor" << endl;
    }
    Cat(string name) : Animal(name) {
        cout << "Cat constructor" << endl;
    }
    void output_tail() {
        cout << this->tail << endl;
    }
    void tell_me_your_name() {
        cout << "cat name is : " << this->__name << endl;
    }
private:
    int tail;
};

class Tail {
public :
    Tail(int length) : __length(length) {
        cout << "Tail constructor" << endl;
    }
private:
    int __length;
};

class HasTailCat : public Cat {
public :
    HasTailCat(string name) : tail(6) {
        cout << "HasTailCat constructor" << endl;
        this->__name = name;
    }
private:
    Tail tail;
};

int main() {
    HasTailCat a("garfiled");
    a.tell_me_your_name();
    a.output_tail();
    return 0;
}

