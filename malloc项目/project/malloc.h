/*************************************************************************
	> File Name: malloc.h
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 日  3/10 10:43:32 2019
 ************************************************************************/

#ifndef MYLLOC_H
#define MYLLOC_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/*
#define malloc(size) mylloc(size)
#define calloc(numitems, size) mycalloc(numitems, size)
#define realloc(ptr, size) myrealloc(ptr, size)
#define free(ptr) myfree(ptr)
*/

#define malloc(size) printf("CHEATING by using malloc\n");
#define calloc(numitems, size) printf("CHEATING by using calloc\n");
#define realloc(ptr, size) printf("CHEATING by using realloc\n");
#define free(ptr) printf("CHEATING by using free\n");

void *mylloc(size_t sizes);
void *mycalloc(size_t numitems, size_t size);
void *myrealloc(void *ptr, size_t size);
void myfree(void *ptr);

#endif


