/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月18日 星期二 23时01分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __tmp = a;\
    a = b, b = __tmp;\
}

typedef struct priority_queue {
    int *data;
    int size, cnt;
} priority_queue;

priority_queue *init(int size) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->data = (int *)malloc(sizeof(int) * (size + 1));
    p->size = size;
    p->cnt = 0;
    return p;
}

int empty(priority_queue *p) {
    return p->cnt == 0;
}
int top(priority_queue *p) {
    return p->data[1];
}

int push(priority_queue *p, int val) {
    if (!p) return 0;
    if (p->cnt == p->size) return 0;
    p->cnt++;
    p->data[p->cnt] = val;
    int tmp = p->cnt;
    while (tmp >> 1 && p->data[tmp] > p->data[tmp >> 1]) {
        swap(p->data[tmp], p->data[tmp >> 1]);
        tmp >>= 1;
    }
    return 1;
}
int pop(priority_queue *p) {
    if (!p) return 0;
    if (empty(p)) return 0;
    int ret = p->data[1];
    p->data[1] = p->data[p->cnt--];
    int ind = 1;
    while (ind << 1 <= p->cnt) {
        int tmp = ind, l = 2 * ind, r = 2 * ind + 1;
        if (p->data[l] > p->data[tmp]) tmp = l;
        if (r <= p->cnt && p->data[r] > p->data[tmp]) tmp = r;
        if (tmp == ind) break;
        swap(p->data[ind], p->data[tmp]);
        ind = tmp;
    }
    return ret;
}

void output(priority_queue *p) {
    if (!p) return ;
    printf("priority_queue(%d) = [", p->cnt);
    for (int i = 0; i < p->cnt; i++) {
        if (i) printf(" ");
        printf("%d", p->data[i]);
    }
    printf("\n");
}

void clear(priority_queue *p) {
    if (!p) return ;
    free(p->data);
    free(p);
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    priority_queue *p = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(p, val);
        printf("push %d into priority_queue\n", val);
    }
    printf("\n");
    printf("遍历输出数组元素：\n");
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n\n");
    printf("不断取队首元素并将其弹出队列：\n");
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", top(p));
        pop(p);
    }
    printf("\n");
    clear(p);
    return 0;
}
