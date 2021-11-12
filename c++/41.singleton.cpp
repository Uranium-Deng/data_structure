/*************************************************************************
	> File Name: 41.singleton.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月30日 星期三 10时34分35秒
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
#include <mutex>
#include <vector>
using namespace std;

class Singleton {
public :
    static Singleton *getInstance() {
        if (instance == nullptr) {
            // 外层 if 防止多次加锁，影响效率
            std::unique_lock<std::mutex>(m_mutex);
            // std::unique_lock<std:mutex>(m_mutex); 加锁,防止多线程
            if (instance == nullptr) {
                // 若去除内层 if，若A, B两线程都通过外层if判断，A先拿到锁，
                // B阻塞，A执行完之后，释放锁，B将会拿到锁，再次进行实例化，
                // 这就背离的单例模式的设计思想
                instance  = new Singleton();
            }
        }
        return instance;
    }

private :
    static Singleton *instance;
    static std::mutex m_mutex;

    Singleton() {}
    Singleton(Singleton &) = delete;
    ~Singleton() {}
};


// 类成员变量，在类中只是声明，需要在类外定义。
Singleton *Singleton::instance = nullptr;
std::mutex Singleton::m_mutex; 


int main() {
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    cout << p1 << " " << p2 << endl;


    return 0;
}
