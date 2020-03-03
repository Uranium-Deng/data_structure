/*************************************************************************
	> File Name: 12.quick_find.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月24日 星期一 11时08分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct UnionSet {
    int *color;
    int size;
} UnionSet;

UnionSet *init(int size) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->size = size;
    u->color = (int *)malloc(sizeof(int) * (size + 1));
    for (int i = 1; i <= u->size; i++) u->color[i] = i;
    return u;
}

int find(UnionSet *u, int x) {
    return u->color[x];
}

int merge(UnionSet *u, int a, int b) {
    if (u->color[a] == u->color[b]) return 0;
    int color_a = u->color[a];
    for (int i = 1; i <= u->size; i++) {
        if (u->color[i] - color_a) continue;
        u->color[i] = u->color[b];
    }
    return 1;
}

void print(UnionSet *u) {
    for (int i = 1; i <= u->size; i++) {
        printf("num %d's color = %d\n", i, u->color[i]);
    }
}

void clear(UnionSet *u) {
    if (!u) return ;
    free(u->color);
    free(u);
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    print(u);
    clear(u);
    return 0;
}
