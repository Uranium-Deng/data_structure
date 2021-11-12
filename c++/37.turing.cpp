/*************************************************************************
	> File Name: 37.turing.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月13日 星期四 14时27分41秒
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

template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};


template<int n, int m>
struct Add {
    static constexpr int r = n + m;
};

template<int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};

template<>
struct Sum<1> {
    static constexpr int r = 1;
};

template<int n>
struct Fac {
    static constexpr int r = n * Fac<n - 1>::r;
};

template<>
struct Fac<1> {
    static constexpr int r = 1;
};

/*
template<int i, int x>
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};


template<int i, int x, int k> 
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
};

template<int i, int x>
struct Test<i, x, 0> {
    constexpr static int r = 1;
};

template<int i, int x>
struct Test<i, x, 1> {
    constexpr static int r = 0;
};

template<int x> 
struct Is_prime {
    constexpr static int r = Test<2, x, 2>::r;
};*/

template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};


template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};

template<int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template<int n>
struct IsTest<n, 0> {
    static constexpr int r = 0;
};

template<int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};


template<int n>
struct SumPrime {
    static constexpr int r = (IsPrime<n>::r * n) + SumPrime<n - 1>::r;
};

template<>
struct SumPrime<1> {
    static constexpr int r = 0;
};


bool judge(int i, int n) {
    if (n % i == 0) return false; //k = 1
    if (i * i > n) return true; // k = 0
    return judge(i + 1, n);
}

bool judge(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

template<int i, int x>
struct getNextK2 {
    constexpr static int r = (i > x ? 0 : 1);
};

template<int x>
struct PrintPrime {
    template<int i, int k>
    struct __output {
        static void run() {
            if (IsPrime<i>::r) {
                cout << i << endl;
            }
            PrintPrime<x>::__output<i + 1, getNextK2<i + 1, x>::r >::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
            return ;
        }
    };
    static void output() {
        PrintPrime<x>::__output<2, 1>::run();
        return ;
    }
};


int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;

    cout << Add<100, 200>::r << endl;
    cout << Sum<100>::r << endl;

    cout << Fac<5>::r << endl;
    cout << Fac<10>::r << endl;
    
    cout << IsPrime<9973>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;
    
    cout << SumPrime<10>::r << endl;
    cout << SumPrime<40>::r << endl;
    cout << "*************************" << endl;
    PrintPrime<100>::output();


    return 0;
}


// 输出 n以内 所有的素数


