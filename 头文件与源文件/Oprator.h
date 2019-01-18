/*************************************************************************
	> File Name: Oprator.h
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:04:40 2019
 ************************************************************************/

#ifndef _OPRATOR_H
#define _OPRATOR_H
class Operator{
    private:
        double m;
        double n;
        char op;
    public:
        void setValue(double a, double b);
        bool setOp(char c);
        bool result(double &r);
};
#endif
