/*************************************************************************
	> File Name: Oprator.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 四  1/17 21:05:22 2019
 ************************************************************************/

#include "Operator.h"

void Operator::setValue(double a,  double b) {
    m = a;
    n = b;
    return;
}

bool Operator::setOp(char c) {
    bool ret = false;
    if((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
        ret = true;
        op = c;
    }
    return ret;
}

bool Operator::result(double &r) {
    bool ret = true;
    switch(op) {
        case '+' : {
            r = m + n;
            break;
        }
        case '-': {
            r = m - n;
            break;
        }
        case '*' :{
            r = m * n;
            break;
        }
        case '/' : {
            if ((n >= -0.000001) && (n <= 0.000001)) {
                ret = false;
                r = 0;
                break;
            } else {
                r = m / n;
                break;
            }
        }
        default:{
            ret = false;
            break;
        }
    }
    return ret;
}
