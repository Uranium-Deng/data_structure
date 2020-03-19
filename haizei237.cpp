/*************************************************************************
	> File Name: haizei237.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 12时32分29秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[10], mark[10], cnt;

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", num[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i]) continue;
        num[cnt++] = i;
        mark[i] = 1;
        func(left - 1);
        cnt--;
        mark[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    func(n);
    return 0;
}
