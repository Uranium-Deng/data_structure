/*************************************************************************
	> File Name: 329.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年10月03日 星期六 10时19分28秒
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
int c[MAX_N + 5];
inline int lowbit(int x) { return  x & (-x); }

// 树状数组，修改是向后修改，查询时向前查询

// 树状数组单点修改，修改树状数组
// 将a[x]加上val，依次修改后面的值
void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

// 根据树状数组获得前x项的和
int query(int x) {
    int sum = 0;
    while (x) { sum += c[x], x -= lowbit(x); }
    return sum;
}

void print_array(int n) {
    cout << "array: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m, pre = 0, now;
    cin >> n;

    // 树状数组初始化
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        print_array(n);
        pre = now;
    }
    
    cin >> m;
    char str[10];
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'C' : {
                int a, b, c;
                cin >> a >> b >> c;
                add(a, c, n);
                add(b + 1, -c, n);
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
