/*************************************************************************
	> File Name: 类的组合关系.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:16:15 2019
 ************************************************************************/

#include <iostream>
using namespace std;
class Mem {
    public:
    Mem() {
        cout << "Mem" << endl; 
    }
    ~Mem() {
        cout << "~Men" << endl;
    }
};
class Disk{
    public:
    Disk() {
        cout << "Disk" << endl;
    }
    ~Disk() {
        cout << "~Disk" << endl;
    }
};
class CPU {
    public:
    CPU() {
        cout << "CPU" << endl;
    }
    ~CPU() {
        cout << "~CPU" << endl;
    }
};

class Computer {
    private:
        Mem m;
        Disk d;
        CPU c;
    public:
    Computer() {
        cout << "Computer" << endl;
    }
    void PowerOn() {
        cout << "Power on" << endl;
    }
    ~Computer() {
        cout << "~Computer" << endl;
    }

};
int main() {
    Computer c;
    return 0;
}
