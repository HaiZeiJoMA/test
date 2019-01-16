/*************************************************************************
> File Name: head.c
> Author: 小学肄业
> Mail: 18734914520@163.com or weirufeng@haizeix.com
> Created Time: 四  1/10 16:19:11 2019
> Description:
************************************************************************/
#include "head.h"
#include <stdlib.h>
typedef struct  class_demo {
    int a;
    int b;
}class_demo;
typedef struct class_derived 
{
    class_demo d;
    int c;
} class_derived;
demo* demo_init(int i, int j) {
    class_demo *p = (class_demo*) malloc(sizeof(class_demo));
    if(p != NULL) {
        p->a = i;
        p->b = j;
    }
    return p;
}

int getA(demo *pthis) {
    class_demo *p = (class_demo*) pthis;
    return p->a;
}

int getB(demo* pthis) {
    class_demo *p = (class_demo*)pthis;
    return p->b;
}

int add(demo *pthis, int value) {
    class_demo *p = (class_demo *)pthis;
    return p->a + p->b + value;
}

void free_demo(demo *pthis) {
    free(pthis);
    return ;
}

deverid* deverid_init(int i, int j, int k) {
    class_derived *p = (class_derived *) malloc(sizeof(class_derived));
    if(p != NULL) {
        p->d.a = i;
        p->d.b = j;
        p->c = k;
    }
    return p;
}

int getC(deverid *pthis) {
    class_derived *p = (class_derived *) pthis;
    return p->c;
}
int add1(deverid *pthis, int value) {
    class_derived *p = (class_derived *) pthis;
    return p->d.a + p->d.b + p->c + value;
}
void free_deverid(deverid *pthis) {
    free(pthis);
}
