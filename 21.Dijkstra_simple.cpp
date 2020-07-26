/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月26日 星期日 11时10分38秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 100000
#define MAX_M 200000
#define INF 0x3f3f3f3f

struct Data {
    int now, dis;
    Data(int x, int y) : now(x), dis(y) {}
    bool operator< (const Data &b) const {
        return this->dis > b.dis;
    }
};

struct edge {
    int to, val, next;
} edg[MAX_M + 5];


int head[MAX_N + 5], dis[MAX_N + 5], edg_cnt;

void add_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

void dijkstra(int n, int s) {
    priority_queue<Data> q;
    q.push(Data(s, 0));
    while (!q.empty()) {
        Data tmp = q.top();
        q.pop();
        int ind = tmp.now;
        if (dis[ind] != INF) continue;
        dis[ind] = tmp.dis;
        for (int i = head[ind]; i != -1; i = edg[i].next) {
            if (dis[edg[i].to] == INF) {
                q.push(Data(edg[i].to, edg[i].val + dis[ind]));
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    dijkstra(n, s);
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << dis[i];
    }
    cout << endl;
    return 0;
}
