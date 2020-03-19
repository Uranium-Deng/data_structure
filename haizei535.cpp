/*************************************************************************
	> File Name: haizei535.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 13时28分18秒
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[55][55];
int ans = 1;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            ans++;
            mmap[x][y] = '0';
            func(xx, yy);
        }
    }
}

int main() {
    int n, m, sx, sy;
    scanf("%d %d", &m, &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &mmap[i][j]);
            if (mmap[i][j] == '@') {
                sx = i; sy = j;
            }
        }
        getchar();
    }
    func(sx, sy);
    printf("%d\n", ans);
    return 0;
}
