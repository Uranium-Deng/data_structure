/*************************************************************************
	> File Name: haizei537.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月19日 星期四 15时14分04秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <set>
using namespace std;

char let[30];
int n, l, num[30], cnt;
set<string> se;

bool judge(string str) {
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] >= str[i + 1]) return false;
    }
    return true;
}

bool judge1(string str) {
    int a = 0, b = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            a++;
        } else {
            b++;
        }
    }
    if (a >= 1 && b >= 2) return true;
    return false;
}

void func(int s, int left) {
    if (left == 0) {
        string ans;
        for (int i = 0; i < cnt; i++) {
            ans += let[num[i]];
        }
        if (judge(ans) && judge1(ans)) se.insert(ans);
        return ;
    }
    for (int i = s; i <= n - left + 1; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    scanf("%d %d", &l, &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%c", &let[i]);
        getchar();
    }
    func(1, l);
    printf("se.size() = %d\n",(int)se.size());
    int size = (se.size() < 25000 ? se.size() : 25000);
    set<string>::iterator it;
    int cnt = 0;
    for (it = se.begin(); it != se.end(); it++) {
        cout << *it << endl;
        cnt++;
        if (cnt >= size) break;
        //printf("%s\n", *it);
    }
    return 0;
}
