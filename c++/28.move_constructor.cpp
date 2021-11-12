/*************************************************************************
	> File Name: 28.move_constructor.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月06日 星期四 09时40分39秒
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
#include <cstring>
#include <vector>
using namespace std;

namespace haizei {
class string {
public :
    string() {
        cout << "string : defalut constructor, " << this << endl;
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        cout << "string : const char constructor, " << this << endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    string(const string &s) {
        cout << "string : const string constructor, " << this << endl;
        this->__length = s.size();
        this->__buff_size = this->__length + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, s.c_str());
    }
    // 对左值进行深拷贝，右值进行移动构造move
    
    string(string &&s) {
        cout << "string : move constructor, " << this << endl;
        this->__length = s.size();
        this->__buff_size = this->__length + 1;
        this->buff = s.buff;
        s.buff = nullptr;
    }

    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error: out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const {
        return buff;
    }
    string operator+(const string &s) {
        cout << "string : operator+" << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() const { return this->__length; }

    ~string() {
        cout << "default destructor, " << this << endl;
        delete[] buff;
    }

private : 
    int __length, __buff_size;
    char *buff;
    char __end;
};

};

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}


int main() {
    haizei::string s = "hello world", s2 = ", haizei", s3 = ", harbin";
    cout << "_____________before s4____________" << endl;
    haizei::string s4 = s + s2 + s3;
    cout << "_____________after s4____________" << endl;


    haizei::string s5 = s4;
    cout << s4 << endl;
    cout << s5 << endl;
    s4[2]='='; 
    cout << s4 << endl;
    cout << s5 << endl;

    cout << s << endl; 
    s[1] = 'A';
    cout << s << endl;
    cout << s + s2 + s3 << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }

    return 0;
}
