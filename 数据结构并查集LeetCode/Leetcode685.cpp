/*************************************************************************
	> File Name: Leetcode685.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 一  1/21 11:28:16 2019
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct UnionSet {
    int *father;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i= 0; i < n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] != x)
        return (u->father[x] = find(u, u->father[x]));
    return x;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);//取出来
    if (fa == fb) return 0;//不进行连接
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->father[fb] = fa;//把fb的根节点改成fa
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return;
    free(u->father);
    free(u->size);
    free(u);
    return;
}

int* solve(int** edges, int n, int m, int* returnSize) {
    
}

