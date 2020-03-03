/*************************************************************************
	> File Name: stack.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月13日 星期四 21时57分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return s;
}

bool empty(Stack *s) {
    return s->top == -1;
}
int top(Stack *s) {
    if (!s) return 200;
    return s->data[s->top];
}
bool expand(Stack *s) {
    int *old_data = s->data;
    s->data = (int *)malloc(sizeof(int) * 2 * s->size);
    if (!s->data) return false;
    s->size *= 2;
    for (int i = 0; i <= s->top; i++) s->data[i] = old_data[i];
    return true;
}
bool push(Stack *s, int val) {
    if (!s) return false;
    if (s->top + 1 == s->size) {
        if (expand(s)) printf("expand success\n");
        else {
            printf("expand failed\n");
            return false;
        }
    }
    s->data[++s->top] = val;
    return true;
}
bool pop(Stack *s) {
    if (!s || empty(s)) return false;
    s->top--;
    return true;
}

void output(Stack *s) {
    if (!s) return ;
    printf("Stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; i++) {
        if (i) printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
}

int main() {
#define MAX_OP 10
    Stack *s = init(MAX_OP);
    srand(time(0));
    int op, val;
    for (int i = 0; i < 5 + MAX_OP; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to stack = %d\n", val, push(s, val));
                break;
            }
            case 3: {
                printf("pop %d to stack", top(s));
                printf(" = %d\n", pop(s));
                break;
            }
            default: {
                printf("it is impossible\n");
            }
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
