/*************************************************************************
	> File Name: haizei236.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 11时52分28秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if (left == 0) {
        for (int i = 0; i < m; i++) {
            if (i) printf(" ");
            printf("%d", num[i]);
        }
        printf("\n");
        return ;
    }
    for (int i = s; i <= n - left + 1; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    func(1, m);
    return 0;
}
