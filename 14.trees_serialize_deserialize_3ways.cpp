/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月05日 星期四 08时33分52秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *lchild, *rchild;
    TreeNode(int x) : val(x), lchild(NULL), rchild(NULL) {}
};

TreeNode *table_to_tree(string str) {
    TreeNode *pre = NULL, *top_p = NULL;
    int flag = 0;
    stack<TreeNode *> s;

    string tmp = "";
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '(': {
                flag = 0;
                s.push(pre);
                pre = NULL;
                break;
            }
            case ')': {
                top_p = s.top();
                s.pop();
                break;
            }
            case ',': {
                flag = 1;
                pre = NULL;
                break;
            }
            default: {
                tmp += str[i];
                if (str[i + 1] == '(' || str[i + 1] == ')' || str[i + 1] == ',') {
                    int num = stoi(tmp);
                    pre = new TreeNode(num);
                    if (!flag && !s.empty()) {
                        s.top()->lchild = pre;
                    } else if (flag && !s.empty()) {
                        s.top()->rchild = pre;
                    }
                    tmp = "";
                }
            }
        }
    }
    if (pre && !top_p) top_p = pre;
    return top_p;
}

void _tree_to_table(TreeNode *root, string& ret) {
    if (!root) return ;
    ret += to_string(root->val);
    if (!root->lchild && !root->rchild) return ;
    ret += "(";
    _tree_to_table(root->lchild, ret);
    ret += ",";
    _tree_to_table(root->rchild, ret);
    ret += ")";
}
string tree_to_table(TreeNode *root) {
    string ret;
    _tree_to_table(root, ret);
    return ret;
}


string serialize(TreeNode *root) {
    if (!root) return "[]";
    string ans = "[";

    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode *top = q.front();
        q.pop();
        if (top) {
            q.push(top->lchild);
            q.push(top->rchild);
            ans += to_string(top->val);
        } else {
            ans += "null";
        }
        ans += ",";
    }
    
    int end = ans.length() - 1;
    while (!(ans[end] >= '0' && ans[end] <= '9')) end--;
    string ret = ans.substr(0, end + 1);
    ret += "]";
    return ret;
}

TreeNode *deserialize(string str) {
    int len = str.length();
    if (len <= 2) return NULL;
    
    vector<TreeNode *> v;
    string word = "";
    for (int i = 1; i < len - 1; i++) {
        if (str[i] == ',') {
            TreeNode *tmp = NULL;
            if (word == "null") {
                v.push_back(tmp);
            } else {
                tmp = new TreeNode(stoi(word));
                v.push_back(tmp);
            }
            word = "";
        } else {
            word += str[i];
        }
    }
    if (word != "" && word != "null") {
        v.push_back(new TreeNode(stoi(word)));
    }

    int cnt = v.size();
    int p = 0, q = 1;
    while (q < cnt) {
        if (!v[p]) p++;
        else {
            v[p]->lchild = v[q];
            if (q + 1 < cnt) v[p]->rchild = v[q + 1];
            p++, q += 2;
        }
    }
    return v[0];
}

void pre_serialize(ostringstream& oss, TreeNode *root) {
    if (root) {
        oss << root->val << " ";
        pre_serialize(oss, root->lchild);
        pre_serialize(oss, root->rchild);
    } else {
        oss << "#" << " ";
    }
}
string pre_serialize(TreeNode *root) {
    ostringstream oss;
    pre_serialize(oss, root);
    return oss.str();
}

TreeNode *pre_deserialize(istringstream& iss) {
    string tmp;
    iss >> tmp;
    if (tmp == "#") {
        return NULL;
    } else {
        TreeNode *root = new TreeNode(stoi(tmp));
        root->lchild = pre_deserialize(iss);
        root->rchild = pre_deserialize(iss);
        return root;
    }
}
TreeNode *pre_deserialize(string str) {
    istringstream iss(str);
    return pre_deserialize(iss);
}




void pre_order(TreeNode *root) {
    if (!root) return ;
    printf("%d ", root->val);
    pre_order(root->lchild);
    pre_order(root->rchild);
}
void in_order(TreeNode *root) {
    if (!root) return ;
    in_order(root->lchild);
    printf("%d ", root->val);
    in_order(root->rchild);
}
void print(TreeNode *root) {
    if (!root) return ;
    printf("pre_order: ");
    pre_order(root);
    printf("\n");
    printf("in_order: ");
    in_order(root);
    printf("\n");
}

int main() {
    string str = "101(203(-1,),405(2(-10,-110),3(,20)))";
    TreeNode *root = table_to_tree(str);
    string ans = tree_to_table(root);
    cout << "ans = " << ans << endl;
    print(root);
    printf("**************************************************\n\n");
    string str1 = serialize(root);
    cout << "str1 = " << str1 << endl;
    TreeNode *root1 = deserialize(str1);
    print(root1);
    printf("**************************************************\n\n");
    string str2 = pre_serialize(root);
    cout << "str2 = " << str2 << endl;
    TreeNode *root2 = pre_deserialize(str2);
    print(root2);
    printf("**************************************************\n\n");
    return 0;
}
