/*************************************************************************
	> File Name: 13.quick_union.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月24日 星期一 12时37分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

UnionSet *init(int size) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->n = size;
    u->size = (int *)malloc(sizeof(int) * (size + 1));
    u->father = (int *)malloc(sizeof(int) * (size + 1));
    for (int i = 1; i <= size; i++) {
        u->size[i] = 1;
        u->father[i] = i;
    }
    return u;
}

int find(UnionSet *u, int x) {   //找到元素x的最终代表元素,并将最终父结点改为自己的直系父结点
    //return (u->father[x] == x ? x : find(u, u->father[x]));
    //if (u->father[x] == x) return x;
    //return u->father[x] = find(u, u->father[x]);
    return u->father[x] = (u->father[x] == x ? x : find(u,u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
    if (!u) return 0;
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) swap(fa, fb);
    if (u->size[fa] >= u->size[fb]) {
        u->father[fb] = fa;
        u->size[fa] += u->size[fb];
    } else {
        u->father[fa] = fb;
        u->size[fb] += u->size[fa];
    }
    return 1;
}


void clear(UnionSet *u) {
    if (!u) return ;
    free(u->size);
    free(u->father);
    free(u);
}

int main() {
    int size, ops;
    scanf("%d %d", &size, &ops);
    UnionSet *u = init(size);
    for (int i = 0; i < ops; i++) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        switch (op) {
            case 1: merge(u, a, b); break;
            case 2: printf("%s\n", find(u, a) == find(u, b) ? "Yes" : "No");
        }
    }
    clear(u);
    return 0;
}
