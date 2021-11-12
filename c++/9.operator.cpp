/*************************************************************************
	> File Name: 9.operator.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月27日 星期一 18时29分02秒
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
#include <vector>
using namespace std;


namespace haizei {

class istream {
public:
    istream &operator>> (int &n) {
        std::cin >> n;
        return *this;
    }
    

private:
    
};

class ostream {
public:
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }

private:

};

istream cin;
ostream cout;

};

// 重载运算符只可改变运算符的逻辑，但是不可以是改变运算的优先级
haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

// 73行8,9,10都是字面量，字面量肯定是不允修改的
// int &n,引用的是变量，若是普通变量的引用，肯定是可以的，但若是字面量，肯定是不可以修改的，所以加上const
ostream &operator+(ostream &out, const int &n) {
    out << n << endl;
    return out;
}

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << " " << m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    cout + 8 + 9 + 10;

    return 0;
}
