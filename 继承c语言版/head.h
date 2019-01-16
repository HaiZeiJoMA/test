/*************************************************************************
> File Name: head.h
> Author: 小学肄业
> Mail: 18734914520@163.com or weirufeng@haizeix.com
> Created Time: 四  1/10 16:17:08 2019
> Description:
************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
typedef void demo;
typedef void deverid;

demo* demo_init(int i, int j);
int getA(demo *pthis);
int getB(demo *pthis);
int add(demo *pthis, int value);
void free_demo(demo *pthis);

deverid* deverid_init(int i, int j, int k);
int getC(deverid *pthis);
int add1(deverid *pthi, int value);
void free_deverid(deverid *pthis);
#endif
