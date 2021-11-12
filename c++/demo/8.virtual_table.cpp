/*************************************************************************
	> File Name: 8.virtual_table.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月24日 星期四 10时50分07秒
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

class Animal {
public : 
    virtual void say() {
        cout << "I don't how to say" << endl;
    }
    virtual void run() {
        cout << "I don't how to run" << endl;
    }
private :
    int x, y;
};

class Cat : public Animal {
public :
    void say() override {
        cout << "miao miao miao" << endl;
    }
    virtual void run() {
        cout << "I can run with four legs" << endl;
    }
private :
};

typedef void (* func)();

// 打印从地址q开始的n个字节的内容
void output_raw_data(void *q, int n) {
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < n; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

int main() {
    cout << sizeof(Animal) << endl;
    cout << sizeof(Cat) << endl;

    Cat a, b;
    output_raw_data(&a, sizeof(a));
    output_raw_data(&b, sizeof(b));

    ((func **)(&a))[0][0]();

    return  0;
}
