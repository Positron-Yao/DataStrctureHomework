#include <cstdio>
#include "SLinkNode.h"

int main(int argc, char** argv) {
    size_t const size = 5;
    ElemType data[size] = {1, 2, 3, 4, 5};
    SLinkNode *head;
    CreateListL(head, data, size);
    printf("创建链表: \t");
    DispList(head);

    InsElem(head, 2, 9);
    printf("在第2位插入9: \t");
    DispList(head);

    DelElem(head, 4);
    printf("删除第4位: \t");
    DispList(head);

    DestroyNodeList(head);
    // std::cout << "hello world!" << std::endl;
    return 0;
}
