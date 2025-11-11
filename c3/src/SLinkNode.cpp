#include <cstdlib>
#include <cstdio>
#include "SLinkNode.h"

void DispList(SLinkNode *L) {
    if (L != NULL && L->next != NULL) {
        L = L->next;
        printf("%d", L->data);
        while (L->next != NULL) {
            L = L->next;
            printf(" -> %d", L->data);
        }
    }
    printf("\n");
}

void InitList(SLinkNode *&L) {
    L = (SLinkNode*)malloc(sizeof(SLinkNode));
    L->next = NULL;
}

void MakeNode(SLinkNode *&p, ElemType e) {
    p = (SLinkNode*)malloc(sizeof(SLinkNode));
    p->data = e;
    p->next = NULL;
}

void Append(SLinkNode *&L, ElemType e) {
    SLinkNode *p;
    MakeNode(p, e);
    if (L == NULL) {
        L = p;
    } else {
        SLinkNode *q = L;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void Prepend(SLinkNode *&L, ElemType e) {
    SLinkNode *n = L->next, *p;
    MakeNode(p, e);
    p->next = n;
    L->next = p;
}

void DestroyNodeList(SLinkNode *&L) {
    SLinkNode *pre = L, *p = pre->next;
    while (p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

size_t GetLength(SLinkNode *L) {
    size_t i = 0;
    SLinkNode *p = L->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

int GetElem(SLinkNode *L, size_t i, ElemType &e) {
    size_t j = 0;
    SLinkNode *p = L;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    if (p == NULL) return 0;
    else {
        e = p->data;
        return 1;
    }
}

int GetNode(SLinkNode *L, size_t i, SLinkNode *&g) {
    size_t j = 0;
    SLinkNode *p = L;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    if (p == NULL) return 0;
    else {
        g = p;
        return 1;
    }
}

size_t Locate(SLinkNode *L, ElemType e) {
    SLinkNode *p = L->next;
    int j = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        j++;
    }
    if (p == NULL) return 0;
    else return j;
}

int InsElem(SLinkNode *&L, size_t index, ElemType e) {
    if (index == 0) return 0;
    else if (index == 1) Prepend(L, e);
    else {
        SLinkNode *g, *p;
        if (!GetNode(L, index - 1, g)) return 0;
        MakeNode(p, e);
        p->next = g->next;
        g->next = p;
    }
    return 1;
}

int DelElem(SLinkNode *&L, size_t i) {
    if (i == 0) return 0;
    else if (i == 1) {
        SLinkNode *p = L->next;
        L->next = p->next;
        free(p);
    } else {
        SLinkNode *g, *p;
        if (!GetNode(L, i - 1, g)) return 0;
        if (g->next == NULL) return 0;
        p = g->next;
        g->next = p->next;
        free(p);
    }
    return 1;
}

int CreateListL(SLinkNode *&L, ElemType *arr, size_t n) {
    InitList(L);
    for (size_t i = 0; i < n; i++) {
        Append(L, arr[i]);
    }
    return 1;
}

int CreateListR(SLinkNode *&L, ElemType *arr, size_t n) {
    InitList(L);
    for (size_t i = 0; i < n; i++) {
        Prepend(L, arr[i]);
    }
    return 1;
}
