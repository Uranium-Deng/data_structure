/*************************************************************************
	> File Name: 29.template.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月06日 星期四 11时46分16秒
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
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    int x;
};

class B {
public: 
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}
/*
template<typename T, typename ...ARGS>
struct ARG {
    typedef T __type;
    typedef ARG<ARGS...> __rest;
};

template<typename T>
struct ARG<T> {
    typedef T __type;
};*/


template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};


// 参数列表中还有元素，已找到想要的元素
template<typename T, typename ...ARGS> 
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

// 递归到最后一个
template<typename T>
struct ARG<0, T> {
    typedef T __type;
};


template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    /*
    T operator()(
        typename ARG<0, ARGS...>::__type a, 
        typename ARG<1, ARGS...>::__type b) {
        return a + b;
    }*/
    T operator()(ARGS ...args) {
        return add<T>(args...);
    }
private : 
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args) {
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) { return a; }
};


template<typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(int (*func)(double)) {
    cout << func(2.3) << endl;
}

template<typename T> struct remove_reference {
    typedef T type;
};
template<typename T> struct remove_reference<T &> {
    typedef T type;
};
template<typename T> struct remove_reference<T &&> {
    typedef T type;
};

template<typename T>
typename remove_reference<T>::type add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return c;
}

/*
// begin remove pointer
template<typename T> struct remove_pointer {
    typedef T type;
};
template<typename T> struct remove_pointer<T *> {
    typedef T type;
};
template<typename T1, typename T2> 
void print_is_same() {
    cout << is_same<T1, T2>() << endl;
}

// begin add const
template<typename T> struct add_const {
    typedef const T type;
};
struct TestAddConst {
    void print() { cout << "normal" << endl; }
    void print() const { cout << "add const successfully" << endl; }
};


// beign add lvalue(rvalue) reference 
template <typename T>
struct type_identity { using type = T; };
 
template <typename T>
auto try_add_lvalue_reference(int) -> type_identity<T&>;
template <typename T>
auto try_add_lvalue_reference(...) -> type_identity<T>;
 
template <typename T>
auto try_add_rvalue_reference(int) -> type_identity<T&&>;
template <typename T>
auto try_add_rvalue_reference(...) -> type_identity<T>;

template <typename T>
struct add_lvalue_reference : decltype(try_add_lvalue_reference<T>(0)) {};
 
template <typename T>
struct add_rvalue_reference : decltype(try_add_rvalue_reference<T>(0)) {};
*/


template<typename T> struct add_lvalue_reference { typedef T &type; };
template<typename T> struct add_lvalue_reference<T &> { typedef T &type; };
template<typename T> struct add_lvalue_reference<T &&> { typedef T &type; };

template<typename T> struct add_rvalue_reference { typedef T &&type; };
template<typename T> struct add_rvalue_reference<T &> { typedef T &&type; };
template<typename T> struct add_rvalue_reference<T &&> { typedef T &&type; };

template<typename T> struct remove_pointer { typedef T type; };
template<typename T> struct remove_pointer<T *> { typedef typename remove_pointer<T>::type type; };

// move 函数
// 函数参数前两个&& 在模板函数中只是单纯的表示引用
template<typename T>
typename add_rvalue_reference<T>::type move(T &&a) {
    return typename add_rvalue_reference<T>::type(a);
}

void f(int &x) {
    cout << "f function : left value" << endl;
}

void f(int &&x) {
    cout << "f function : right value" << endl;
}

} // end of haizei

int main() {
    int inta = 123, intb = 456;
    cout << haizei::add2(inta, intb) << endl;
    cout << haizei::add2(123, 456) << endl;

    /*
    cout << "********* begin remove pointer *********" << endl;
    haizei::print_is_same<int, haizei::remove_pointer<int *>::type>();
    cout << "********* end   remove pointer *********" << endl << endl;;

    cout << "********* begin add const *********" << endl;
    haizei::TestAddConst demo_const;
    demo_const.print();
    haizei::add_const<haizei::TestAddConst>::type demo_add_const;
    demo_add_const.print();
    cout << "********* end   add const *********" << endl << endl;
    
    cout << "********* begin add lvalue(rvalue) reference *********" << endl;
    using nonref = int;
    using lref = typename haizei::add_lvalue_reference<nonref>::type;
    using rref = typename haizei::add_rvalue_reference<nonref>::type;
 
    // std::cout << boolalpha;
    // std::cout << is_lvalue_reference<nonref>::value << endl;
    std::cout << is_lvalue_reference<lref>::value << endl;
    std::cout << is_rvalue_reference<rref>::value << endl;
    cout << "********* end   add lvalue(rvalue) reference *********" << endl << endl;

    */
    // 模板函数作为参数，传递时的间接类型推导
    haizei::func2(haizei::test_param_func);

    A a(1000);
    B b(645);
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;

    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(1, 2, 3, 4) << endl;
    haizei::Test<int(int, int, int, int, int)> f5;
    cout << f5(1, 2, 3, 4, 5) << endl;

    haizei::f(n);
    haizei::f(haizei::move(n));

    return 0;
}

