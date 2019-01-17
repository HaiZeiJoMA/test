/*************************************************************************
	> File Name: 继承演示.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:17:57 2019
 ************************************************************************/

#include <iostream>
#include <sting>
#include <sstream>
using namespace std;

class Object {
    protected:
        string m_name;
        string m_info;
    public:
    Object() {
        m_name = "Object";
        m_info = "";
    }
    string name() {
        return m_name;
    }
    string info() {
        return m_info;
    }
};

class Line : public Object {
    private :
        Point m_p1;
        Point m_p2;
    public:
    Line(Point &p1, Point &p2) {
        m_p1 = p1;
        m_p2 = p2;
        m_name  = "Line";
        ostringstream s;
        s << "Line from" << m_p1.info() << " to " << m_p2.info();
        m_info = s.str();
    }
    Point begin() {
        return m_p1;
    }
    Point end() {
        return m_p2;
    }
};

int main() {
    Object o;
    cout << o.name() << endl;
    cout << o.info() << endl;
    cout << endl;
    Point p1(4, 5), p2(8, 9);
    cout << p1.name() << " " << p1.info() << endl;
    cout << p2.name() << " " << p2.info() << endl;
    cout << endl;
    Line l(p1, p2);
    cout << l.name() << " " << l.info() << endl;
    return 0;
}

