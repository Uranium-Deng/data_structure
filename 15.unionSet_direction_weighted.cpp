/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 17时42分57秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i, val[i] = 0;
        }
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int x, int y, int t) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return ;
        fa[fx] = fy;
        val[fx] = (t + val[y] - val[x] + 3) % 3;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionSet s;
    s.init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            s.merge(b, c, 2);
        } else {
            int bb = s.get(b), cc = s.get(c);
            if (bb - cc) printf("Unknown\n");
            else {
                switch((s.val[b] - s.val[c] + 3) % 3) {
                    case 0: printf("Tie\n"); break;
                    case 1: printf("Loss\n"); break;
                    case 2: printf("Win\n"); break;
                }
            }
        }
    }
    return 0;
}
