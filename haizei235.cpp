/*************************************************************************
	> File Name: haizei235.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 11时07分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n, cnt, num[15];

void print() {
    for (int i = 0; i < cnt; i++) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        print();
        func(i + 1);
        cnt--;
    }
}

int main() {
    scanf("%d", &n);
    func(1);
    return 0;
}
