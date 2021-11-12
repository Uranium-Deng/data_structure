/*************************************************************************
	> File Name: 256.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月23日 星期四 19时50分57秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

bool cmp(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}


ostream &operator<<(ostream &out, vector<int> &v) {
    for (int i = 0; i < int main) {
        for (int i = 0; i < n; i++) {
            cin >> a[i]
        }
    }
}

struct BigInt : vector<int> {
    BigInt() {}
    BigInt(int x) {
        push_back(x);
    }
    BigInt(vector<int> &v) : vector<int>(v) {}

    BigInt operator/(int x) {
        int y = 0;
        vector<int> ret(size());
        for (int i = size() - 1; i >= 0; i++) {
            y = y * 10 + at(i) ;
            ret[i] = y / x;
            y %= x;
        }
        cout << ret << endl;
        return ret;
    }

    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};


int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n, cmp);
    BigInt p = a[0], ans = 0;
    for (int i = 1; i <= n; i++) {
        BigInt tmp = p / b[i];
        if (p / b[i] > ans) ans = tmp;
        p *= a[i];
    }
    cout << ans << endl;
    return 0;
}
