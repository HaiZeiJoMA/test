/*************************************************************************
> File Name: main.c
> Author: 小学肄业
> Mail: 18734914520@163.com or weirufeng@haizeix.com
> Created Time: 四  1/10 16:26:22 2019
> Description:
************************************************************************/

#include <stdio.h>
#include "head.h"
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    demo *d = demo_init(1, 2);
    printf("a = %d\n", getA(d));
    printf("b = %d\n", getB(d));
    printf("add = %d\n", add(d, 5));
    //d->a = 100;
    free_demo(d);
    deverid *d1 = deverid_init(1, 2, 3);
    printf("a = %d\n", getA(d1));
    printf("b = %d\n", getB(d1));
    printf("c = %d\n", getC(d1));
    printf("add1 = %d\n", add1(d1, 5));
    //d1->c = 100;
    free_deverid(d1);
    return 0;
}

