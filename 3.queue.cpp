/*************************************************************************
	> File Name: queue.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月13日 星期四 21时19分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, size, cnt;
} Queue;

Queue *init(int size) {  //q->tail表示队尾后面一个位置
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = q->cnt = 0;
    q->size = size;
    return q;
}

bool empty(Queue *q) {
    return q->cnt == 0;
}
int front(Queue *q) {
    if (empty(q)) return 200;
    return q->data[q->head];
}
bool push(Queue *q, int val) {
    if (!q || q->cnt == q->size) return false;
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail = 0;
    q->cnt++;
    return true;
}
bool pop(Queue *q) {
    if (!q || empty(q)) return false;
    q->head++;
    if (q->head == q->size) q->head = 0;
    q->cnt--;
    return true;
}

void output(Queue *q) {
    if (!q) return ;
    printf("Queue(%d) = [", q->cnt);
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        if (j) printf(", ");
        printf("%d", q->data[(i + j) % q->size]);
    }
    printf("]\n");
}


void clear(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}


int main() {
    #define MAX_OP 10
    Queue *q = init(MAX_OP);
    srand(time(0));
    int op, val;
    for (int i = 0; i < 2 * MAX_OP; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d into Queue = %d\n", val, push(q, val));
                break;
            }
            case 3: {
                printf("pop %d from Queue", front(q));
                printf(" = %d\n", pop(q));
                break;
            }
            default: {
                printf("it is impossible\n");
            }
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
