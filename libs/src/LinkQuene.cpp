#include <cstdlib>
#include "LinkQuene.h"
#include "SLinkNode.h"

namespace LinkQuene {

void InitQuene(LinkQuene *&qu) {
    qu = (LinkQuene*)malloc(sizeof(LinkQuene));
    SLinkNode::InitList(qu->front);
    UpdateTail(qu);
}

void DestroyQuene(LinkQuene *&qu) {
    SLinkNode::DestroyNodeList(qu->front);
    free(qu);
}

void UpdateTail(LinkQuene *&qu) {
    SLinkNode::TailNode(qu->front, qu->rear);
}

void DispQuene(LinkQuene *qu) {
    SLinkNode::DispList(qu->front);
}

int EnQuene(LinkQuene *&qu, ElemType x) {
    SLinkNode::Append(qu->front, x);
    UpdateTail(qu);
    return 0;
}

int DeQuene(LinkQuene *&qu, ElemType &x) {
    if (QueneEmpty(qu)) return 1;
    SLinkNode::GetElem(qu->front, 1, x);
    SLinkNode::DelElem(qu->front, 1);
    UpdateTail(qu);
    return 0;
}

int GetHead(LinkQuene * const &qu, ElemType &x) {
    if (QueneEmpty(qu)) return 1;
    x = qu->front->next->data;
    return 0;
}

bool QueneEmpty(LinkQuene * const &qu) {
    return qu->front->next == nullptr;
}

} // LinkQuene
