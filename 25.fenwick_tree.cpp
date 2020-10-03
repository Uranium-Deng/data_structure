/*************************************************************************
	> File Name: 1.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年10月03日 星期六 14时39分08秒
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
#include <vector>
using namespace std;

#define MAX_N 100000
inline int lowbit(int x) { return x & (-x); }
int c[MAX_N + 5], n, m;

// 树状数组单点修改
void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

// 求解前x项和
int query(int x) {
    int sum = 0;
    while (x) {
        sum += c[x], x -= lowbit(x);
    }
    return sum;
}


int main() {
    cin >> n;
    int now, pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    char str[10];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'C' : {
                int l, r, val;
                cin >> l >> r >> val;
                add(l, val, n);
                add(r + 1, -val, n);
            } break;
            case 'Q' : {
                int x;
                cin >> x;
                cout << query(x) << endl;
            }
        }
    }


    return 0;
}


// 区间加法 差分数组 ！！！
// 树状数组 只支持 单点修改 ！！！


// 所以现在的关键是如何初始化c[i]数组
// 我们假设一开始的c[]就已经是一个关于差分的树状数组了，
// 我们现在要对差分数组进行修改，调用add函数就是对应修改了树状数组

// 区间加法时，若最终仅仅需要求解数组某位置的值
// 此时可以采用差分数组
// 1. 区间加法，对于差分数组而言进需要改变两个点
// 2. 差分数组的前n项的和，就是原数组第n项的值


// 本例中对应的是求解原来数组中的某一项

// 若想求解数组某区间的加和，可以进行公式变换，采用两个树状数组
