/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月30日 星期四 10时52分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;


class String {
public :
    String();
    String(const char *str);
    String(const String &b);
    ~String();

    int length() const { return this->__length; }
    int getCapacity() const {return this->__capacity; }
    char *getString() const {return this->__str; }
    void setLength(int length) { this->__length = length; }
    void setCapacity(int capacity) { this->__capacity = capacity; }
    void setString(char *add) {this->__str = add; }

    // 重载 +=
    String &operator+=(const String &b);
    // 重载 +
    String operator+(const String &b);
    // 重载 ==
    bool operator==(const String &b);
    // 重载 !=
    bool operator!=(const String &b);
    // 重载 <
    bool operator<(const String &b);
    // 重载 <=
    bool operator<=(const String &b);
    // 重载 >
    bool operator>(const String &b);
    // 重载 >=
    bool operator>=(const String &b);
    // 重载 []
    char operator[](int ind) {
        char *p = (char *)this->__str + ind;
        return *p;
    }
    // 重载 =
    void operator=(const char *str) {
        __length = strlen(str);
        __capacity = __length + 8;
        char *tmp = nullptr;
        if (__str != nullptr) tmp = __str;
        __str = new char[__capacity];
        strcpy(__str, str);
        if (tmp != nullptr) delete tmp;
    }
    void operator=(const String &b) {
        __length = b.length();
        __capacity = b.getCapacity();
        char *tmp = nullptr;
        if (__str != nullptr) tmp = __str;
        __str = new char[__capacity];
        strcpy(__str, b.getString());
        if (tmp != nullptr) delete tmp;
    }

private : 
    char *__str;
    int __length;
    int __capacity;
};


// 构造函数
String::String() : __str(nullptr), __length(0), __capacity(32) {}

String::String(const char *str) : __str(nullptr), __length(0), __capacity(32) {
    if (str == nullptr) return ;
    __length = strlen(str);
    __capacity = __length + 8;
    __str = new char[__capacity];
    strcpy(__str, str);
}

String::String(const String &b) : __str(nullptr), __length(0), __capacity(32) {
    __length = b.length();
    __capacity = b.getCapacity();
    __str = new char[__capacity];
    strcpy(__str, b.getString());
}


// 析构函数
String::~String() {
    if (__str != nullptr) {
        delete[] __str;
    }
    __length = 0;
    __capacity = 0;
}

// 重载 ==
bool String::operator==(const String &b) {
    if (!this->getString() && !b.getString()) return true;
    if (this->getString() && !b.getString()) return false;
    if (!this->getString() && b.getString()) return false;
    return !strcmp(this->getString(), b.getString());
}

// 重载 !=
bool String::operator!=(const String &b) {
    if (!this->getString() && !b.getString()) return false;
    if (this->getString() && !b.getString()) return true;
    if (!this->getString() && b.getString()) return true;
    return strcmp(this->getString(), b.getString());
}

// 重载 <
bool String::operator<(const String &b) {
    if (!this->getString() && !b.getString()) return false;
    if (this->getString() && !b.getString()) return false;
    if (!this->getString() && b.getString()) return true;
    if (strcmp(this->getString(), b.getString()) < 0) return true;
    return false;
}
// 重载 <=
bool String::operator<=(const String &b) {
    if (!this->getString() && !b.getString()) return false;
    if (this->getString() && !b.getString()) return false;
    if (!this->getString() && b.getString()) return true;
    if (strcmp(this->getString(), b.getString()) <= 0) return true;
    return false;
}

// 重载 >
bool String::operator>(const String &b) {
    if (!this->getString() && !b.getString()) return true;
    if (this->getString() && !b.getString()) return true;
    if (!this->getString() && b.getString()) return false;
    if (strcmp(this->getString(), b.getString()) > 0) return true;
    return false;
}

// 重载 >=
bool String::operator>=(const String &b) {
    if (!this->getString() && !b.getString()) return true;
    if (this->getString() && !b.getString()) return true;
    if (!this->getString() && b.getString()) return false;
    if (strcmp(this->getString(), b.getString()) >= 0) return true;
    return false;
}

// 重载 << 输出
ostream &operator<<(ostream &out, String &b) {
    out << b.getString();
    return out;
}

// 重载 >> 输入
istream &operator>>(istream &in, String &b) {
    char *in_str = new char[128];
    in >> in_str;
    int len = strlen(in_str);
    int cap = strlen(in_str) + 8;
    char *old = b.getString();
    char *tmp = nullptr;
    if (old != nullptr) {
        tmp = new char[cap];
        strcpy(tmp, in_str);
        delete[] old;
    } else {
        tmp = new char[cap];
        strcpy(tmp, in_str);
    }
    b.setString(tmp);
    b.setLength(len);
    b.setCapacity(cap);
    return in;
}


// 重载 +=
String &String::operator+=(const String &b) {
    int len = __length + b.length();
    int cap = __capacity + b.getCapacity();
    char *tmp = new char[cap];
    strcpy(tmp, __str);
    strcpy(tmp + __length, b.getString());
    delete[] this->getString();
    this->setString(tmp);
    this->setLength(len);
    this->setCapacity(cap);
    return *this;
}

// 重载 +
String String::operator+(const String &b) {
    String ans;
    ans.setLength(__length + b.length());
    ans.setCapacity(__capacity + b.getCapacity());
    char *tmp = new char[__capacity + b.getCapacity()];
    strcpy(tmp, __str);
    strcpy(tmp + __length, b.getString());
    ans.setString(tmp);
    return ans;
}


int main() {
    
    String a = "time";
    cout << "a.length: " << a.length() << endl;
    cout << a << endl;

    cout << a[2] << endl;
    
    String b;
    b = a;
    String c = "IIIII";
    cout << b << endl;
    b = c;
    cout << b << endl;

    cout << "b == a: " << (a == b) << endl;
    cout << "b == c: " << (b == c) << endl;
    
    String d = a + b;
    cout << d << endl;

    a += b;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    cin >> a;
    cout << "a: " << a << endl;

    return 0;
}
