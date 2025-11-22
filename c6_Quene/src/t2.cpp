#include <iostream>
#include "LinkQuene.h"
using Quene = LinkQuene::LinkQuene;
using namespace LinkQuene;
using namespace std;

int DeleteTail(Quene *&qu) {
    if(qu == nullptr || QueneEmpty(qu)) return 1;
    SLinkNode::SLinkNode *p = qu->front;
    while (p->next != qu->rear) p = p->next;
    p->next = nullptr;
    free(qu->rear);
    qu->rear = p;
    return 0;
}

int main() {
    Quene *qu;
    InitQuene(qu);
    EnQuene(qu, 1);
    EnQuene(qu, 2);
    EnQuene(qu, 3);
    cout << "队列元素: ";
    DispQuene(qu);
    DeleteTail(qu);
    cout << "删除队尾后: ";
    DispQuene(qu);
    DestroyQuene(qu);
    return 0;
}
