/*************************************************************************
	> File Name: haizei534.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 14时46分43秒
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

int num[25], cnt, n, v[25];
set<int> se;

void add_sum() {
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        ans += v[num[i]];
    }
    se.insert(ans);
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        add_sum();
        func(i + 1);
        cnt--;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    func(1);
    printf("%d\n", (int)se.size());
    return 0;
}
