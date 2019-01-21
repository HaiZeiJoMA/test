/*************************************************************************
	> File Name: 并查集Leetcode130.cpp
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 一  1/21 09:50:23 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
//编号
int getInd(int i, int j, int m) {
    return i * m + j + 1;
}

void solve(char** board, int n, int m) {
    UnionSet *u = init(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue;
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                merge(u, 0, getInd(i, j, m));
            }
            if (i - 1 >= 0 && board[i-1][j] == 'O') {
                merge(u, getInd(i, j, m), getInd(i-1, j, m));
            }
            if (j - 1 >= 0 && board[i][j-1] == 'O') {
                merge(u, getInd(i, j, m), getInd(i, j-1, m));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue;
            if (find(u, getInd(i, j, m)) != find(u,0)) board[i][j] = 'X';
        }
    }
    clear(u);
    return;
}
