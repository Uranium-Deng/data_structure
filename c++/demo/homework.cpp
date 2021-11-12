/*************************************************************************
	> File Name: 1.homework.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月30日 星期四 07时50分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

void test_string() {
    string a, b;
    a = "hello ";
    b = "This is B";
    cout << "a + b = " << a + b << endl;
    if (a == b) {
        cout << "a == b" << endl;
    } else if (a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "a > b" << endl;
    }
    a += string("world");
    cout << "a = " << a << endl;
    cout << "a[3] = " << a[3] << endl;
    cout << "a.length() = " << a.length();
    cout << "a != b: " << (a != b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
}

void test_map() {
    map<string, int> m;
    m.insert(map<string, int>::value_type("Tom", 1));
    m.insert(pair<string, int>("Jerry", 2));
    m["Jack"] = 3;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    map<string, int> a;
    a = m;
    // a["Tam"] = 0;
    // a["Tom"] = 1;
    a.erase("Jerry");
    a["Joy"] = 2;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "a == m: " << (a == m) << endl;
    cout << "a < m: " << (a < m) << endl;
    cout << "a != m: " << (a != m) << endl;
    cout << "a <= m: " << (a <= m) << endl;
    cout << "a > m: " << (a > m) << endl;
    cout << "a >= m: " << (a >= m) << endl;
}

void test_vector() {
    vector<int> m;
    for (int i = 0; i < 10; i++) {
        m.push_back(i);
    }
    vector<int> a;
    a = m;
    cout << "a's address: " << (&a) << endl;
    cout << "m's address: " << (&m) << endl;
    cout << "m[0] = " << m[0] << endl;
    
    a.push_back(-1);
    cout << "a == m: " << (a == m) << endl;
    cout << "a < m: " << (a < m) << endl;
    cout << "a != m: " << (a != m) << endl;
    cout << "a <= m: " << (a <= m) << endl;
    cout << "a > m: " << (a > m) << endl;
}


void test_unordered_map() {
    unordered_map<int, string> h;
    h[1] = "Tom";
    h.insert(pair<int, string>(2, "Jack"));
    cout << h[1] << endl;
    
    for (auto it = h.begin(); it != h.end(); it++) {
        cout << it->first  << " " << it->second << endl;
    }
    unordered_map<int, string> a;
    a = h;
    cout << "a == h : " << (a == h) << endl;
    cout << "a != h : " << (a != h) << endl;
    
    
}


int main() {
    // test_map();
    // cout << "****************华丽的分割线**********************" << endl;
    // test_vector();

    test_unordered_map();

    return 0;
}
