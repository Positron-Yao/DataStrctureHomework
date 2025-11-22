#include <iostream>
#include "ElemType.h"
#include "LinkQuene.h"
using Quene = LinkQuene::LinkQuene;
using namespace LinkQuene;
using namespace std;

int main(int argc, char** argv) {
    Quene *qu;
    ElemType x;
    InitQuene(qu);
    EnQuene(qu, 1);
    EnQuene(qu, 2);
    EnQuene(qu, 3);
    DispQuene(qu);
    DeQuene(qu, x);
    cout << "DeQuene x: " << x << "\n";
    DispQuene(qu);
    DeQuene(qu, x);
    DispQuene(qu);
    cout << "front: " << qu->front->next->data << "\n";
    cout << "rear: " << qu->rear->data << "\n";
    DestroyQuene(qu);
    return 0;
}
