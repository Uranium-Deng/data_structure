/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年10月10日 星期六 18时28分24秒
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


class A {
public :
    A() = default;
    A(int age, string name) : age(age), name(name) {}

    int getAge() { return this->age; }
    string getName() {return this->name;}

    void output_attributes() {
        cout << "age: " << this->age << endl;
        cout << "name: " << this->name << endl;
    }

private :
    int age;
    string name;
};

ostream & operator<<(ostream &out, A a) {
    cout << "override" << endl;
    cout << "age: " << a.getAge() << ", name: " << a.getName();
    return out;
}

int main() {

    A a(20, "DRZ");
    a.output_attributes();

    cout << a << endl;

    return 0;
}
