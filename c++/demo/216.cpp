/*************************************************************************
	> File Name: 216.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月23日 星期四 18时26分58秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    set<PSI> s;
    string name;
    int n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        int ind = name.find(".");
        // 传入足够大的一个值，截至到最后
        name = name.substr(name.find(".") + 1, name.size());
        s.insert(PSI(name, i));
    }
    for (auto iter  = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;
    }



    return 0;
}
