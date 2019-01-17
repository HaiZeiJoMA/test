/*************************************************************************
	> File Name: 继承基本使用.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:17:25 2019
 ************************************************************************/

#include <iostream>
using namespace std;

class Father {
    protected:
        int i;
    public:
    Father() {
        i = 100;
    }
    int get() {
        return i;
    }
};

class Son : public Father {
};



int main() {
    Father f;
    Son s;
    cout << s.get() << endl;
    return 0;
}
