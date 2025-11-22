#pragma once
#include "ElemType.h"
#include "SLinkNode.h"

namespace LinkQuene {

struct LinkQuene {
    SLinkNode::SLinkNode *front;
    SLinkNode::SLinkNode *rear;
};

void InitQuene(LinkQuene *&qu);
void DestroyQuene(LinkQuene *&qu);
void UpdateTail(LinkQuene *&qu);
void DispQuene(LinkQuene *qu);
int EnQuene(LinkQuene *&qu, ElemType x);
int DeQuene(LinkQuene *&qu, ElemType &x);
int GetHead(LinkQuene * const &qu, ElemType &x);
bool QueneEmpty(LinkQuene * const &qu);

} // LinkQuene
