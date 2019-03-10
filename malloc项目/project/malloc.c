/*************************************************************************
	> File Name: malloc.c
	> Author: HaiZeiJoMA
	> Mail: 860007544@qq.com
	> Created Time: 日  3/10 10:43:24 2019
 ************************************************************************/

#include "malloc.h"
typedef struct __metadata {
    size_t size;
    size_t free;
    struct __metadata *next;
    struct __metadata *prev;
    void *begin;
} MetaData, *pMetaData;

static pMetaData __memory_head = NULL;

void print_log(char *str) {
    printf("[%s:%d]: %s\n", __func__, __LINE__, str);
    fflush(stdout);
}

static void initMetaData(pMetaData p, size_t size, size_t free, pMetaData prev, pMetaData next) {
    p->size = size;
    p->free = free;
    p->prev = prev;
    p->next = next;
    p->begin = ((char *)p) + sizeof(MetaData);
}

static void dataCopyTo(void *dest, void *src, size_t len) {
    size_t i;
    char *p1 = (char *)dest;
    char *p2 = (char *)src;
    for (i = 0; i < len; ++i) {
        p1[i] = p2[i];
    }
    return ;
}

void *mylloc(size_t sizes){
    pMetaData p, q;
    size_t msize = sizes + sizeof(MetaData);
    if (__memory_head == NULL) {
        p = sbrk(0);
        if (sbrk(msize) == (void *)-1) {
            return NULL;
        }
        initMetaData(p, sizes, 0, NULL, NULL);
        __memory_head = p;
    } else {
        p = __memory_head;
        while (p) {
            if (p->free && p->size >= msize) {
                q = (pMetaData)(((char *)p->begin) + sizes);
                initMetaData(q, p->size - msize, 1, p, p->next);
                p->size = sizes;
                if (p->next !=NULL) {
                    p->next->prev = q;
                }
                p->next = q;
                p->free = 0;
                break;
            } else if (p->free && p->size >= sizes) {
                p->free = 0;
                break;
            }
            if (p->next == NULL) break;
            p = p->next;
        }
        if (p->next == NULL) {
            q = sbrk(0);
            if (sbrk(msize) == (void *)-1) {
                return NULL;
            }
            initMetaData(q, sizes, 0, p, NULL);
            p->next = q;
            p = q;
        }
    }
    return p->begin;
}

void myfree(void *p){
    pMetaData q, k;
    q = (pMetaData)(((char *)p) - sizeof(MetaData));
    q->free = 1;
    if (q->prev && q->prev->free) {
        k = q->next;
        q = q->prev;
        q->size += q->next->size + sizeof(MetaData);
        q->next = k;
        if (k != NULL) {
            k->prev = q;
        }
    }
    if (q->next != NULL && q->next->free) {
        k = q->next->next;
        q->size += q->next->size + sizeof(MetaData);
        q->next = k;
        if (k != NULL) {
            k->prev = q;
        }
    }
    size_t msize;
    if (q->next == NULL) {
        if (q->prev != NULL) {
            q->prev->next = NULL;
        } else {
            __memory_head = NULL;
        }
        msize = q->size + sizeof(MetaData);
        sbrk(-msize);
    }
}

void *mycalloc(size_t numitems, size_t size){
    void *ret = mylloc(numitems * size);
    char *p = (char *)ret;
    size_t i = numitems * size;
    while (i--) {
        (*p) = 0;
        ++p;
    }
    return ret;
}

void *myrealloc(void *ptr, size_t size){
    pMetaData p, q, k;
    p = (pMetaData)(((char *)ptr) - sizeof(MetaData));
    if (p->size >= size) return p->begin;
    if (p->next == NULL) {
        if (sbrk(size - p->size) == (void *)-1) {
            return NULL;
        }
        p->size = size;
    }
    if (p->size < size && p->next && p->next->free) {
        if (p->size + p->next->size >= size) {
            q = (pMetaData)(((char *)p->begin) + size);
            initMetaData(q, p->size + p->next->size - size, 1, p, p->next->next);
            p->next = q;
            p->size = size;
        } else if (p->size + p->next->size + sizeof(MetaData) >= size) {
            p->size = p->size + p->next->size + sizeof(MetaData);
            q = p->next->next;
            p->next = q;
            if (q != NULL) {
                q->prev = p;
            }
            p->size = size;
        }
    }
    if (p->size < size && p->prev && p->prev->free) {
        if (p->size + p->prev->size >= size) {
            q = p->next;
            p = p->prev;
            size_t ksize = p->size + p->next->size - size;
            dataCopyTo(p->begin, p->next->begin, p->next->size);
            k = (pMetaData)(((char *)p->begin) + size);
            initMetaData(k, ksize, 1, p, q);
            p->next = k;
            if (q != NULL) {
                q->prev = k;
            }
            p->size = size;
            p->free = 0;
        } else if (p->size + p->prev->size + sizeof(MetaData) >= size) {
            q = p->next;
            p = p->prev;
            size_t totalsize = p->size + p->next->size + sizeof(MetaData);
            dataCopyTo(p->begin, p->next->begin, p->next->size);
            p->next = q;
            if (q != NULL) {
                q->prev = p;
            }
            p->size = totalsize;
            p->free = 0;
        }
    }
    if (p->size < size) {
        void *ret = mylloc(size);
        if (ret == NULL) return NULL;
        dataCopyTo(ret, p->begin, p->size);
        myfree(p->begin);
        p = (pMetaData)(((char *)ret) - sizeof(MetaData));
    }
    return p->begin;
}


