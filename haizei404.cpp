/*************************************************************************
	> File Name: haizei404.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 14时35分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[3005][3005], mark[3005][3005];
int ans = 1;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != mmap[x][y] && mark[xx][yy] == 0 && mmap[xx][yy]) {
            ans++;
            mark[xx][yy] = 1;
            func(xx, yy);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%s", &(mmap[i][1]));
        getchar();
    }
    int sx, sy;
    scanf("%d %d", &sx, &sy);
    mark[sx][sy] = 1;
    func(sx, sy);
    printf("%d\n", ans);
    return 0;
}
