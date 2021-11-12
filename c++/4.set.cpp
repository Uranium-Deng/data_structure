/*************************************************************************
	> File Name: 4.set.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月23日 星期四 18时13分33秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(345);
    s.insert(3454523);
    s.insert(0);
    cout << s.size() << endl;

    s.insert(0);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *(s.begin()) << endl;

    return 0;
}
