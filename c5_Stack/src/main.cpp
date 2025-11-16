#include <cstdio>
#include "SqStack.h"

int main(int argc, char** argv) {
    SqStack st;
    printf("初始化st\n");
    InitStack(st);
    printf("栈为 %s\n", StackEmpty(st) ? "空" : "非空");
    printf("入栈\n");
    Push(st, 'a');
    Push(st, 'b');
    Push(st, 'c');
    Push(st, 'd');
    printf("栈为 %s\n", StackEmpty(st) ? "空" : "非空");
    ElemType x;
    GetTop(st, x);
    printf("栈顶元素: %c\n", x);

    printf("出栈: ");
    while (!StackEmpty(st)) {
        Pop(st, x);
        printf("%c ", x);
    }
    printf("\n");
    return 0;
}
