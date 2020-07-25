/*************************************************************************
	> File Name: 3.Floyd_martix_4779.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月25日 星期六 09时45分30秒
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

// 其中first, second 分别表示点和到该点到原点的最小距离
struct Data {
    int first, second;
    // struct中常用的构造函数
    Data(int a, int b) : first(a), second(b) {}
    // 重载<
    bool operator< (const Data &b) const {
        return this->second > b.second;
    }
};

struct edge {
    int to, val, next;
};
edge edg[MAX_M + 5];

int head[MAX_N + 5], vis[MAX_N + 5], dis[MAX_N + 5];
int edg_cnt;

void add_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

void dijkstra(int n, int s) {
    dis[s] = 0;
    priority_queue<Data> que;
    que.push(Data(s, 0));
    
    for (int i = 1; i < n && !que.empty(); i++) {
        int ind = que.top().first;
        que.pop();
        while (vis[ind] && !que.empty()) {
            ind = que.top().first;
            que.pop();
        }
        for (int j = head[ind]; j != -1; j = edg[j].next) {
            if (dis[edg[j].to] > dis[ind] + edg[j].val) {
                dis[edg[j].to] = dis[ind] + edg[j].val;
                if (vis[edg[j].to]) vis[edg[j].to] = 0;
                que.push(Data(edg[j].to, dis[edg[j].to]));
            }
        }
        vis[ind] = 1;
    }
}

/*void dijkstra(int n, int s) {
    dis[s] = 0;
    for (int i = 1; i < n; i++) {
        int ind = -1;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (ind == -1 || dis[j] < dis[ind]) ind = j;
        }
        for (int j = head[ind]; j != -1; j = edg[j].next) {
            if (dis[edg[j].to] > dis[ind] + edg[j].val) {
                dis[edg[j].to] = dis[ind] + edg[j].val;
            }
        }
        vis[ind] = 1;
    }
}*/

int main() {
    memset(dis, 0x3f, sizeof(dis));
    memset(head, -1, sizeof(head));
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
