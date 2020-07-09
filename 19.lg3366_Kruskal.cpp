/*************************************************************************
	> File Name: 19.lg3366_Kruskal.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月09日 星期四 15时33分53秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 5000
#define MAX_M 200000

struct edge {
    int from, to, val;
};

edge edg[MAX_M + 5];

int n, m, already = 1,  ans, my_union[MAX_N];

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if (x != my_union[x]) {
        return my_union[x] = find_root(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
    }
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i < m; i++) {
        int aroot = find_root(edg[i].from);
        int broot = find_root(edg[i].to);
        if (aroot != broot) {
            // 不会成环，该边可以加入
            already++;
            ans += edg[i].val;
            my_union[aroot] = broot;
            if (already == n) break;
        }
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << "org" << endl;
    }

    return 0;
}

