/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月03日 星期二 22时16分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

//顺序表结构体
typedef struct Vector {
    int length, size;  //顺序表的长度以及大小
    int *data;         //指向数组的指针
}Vector;

//顺序表的初始化以及删除
void init(Vector *vector, int init_size) {
    vector->length = 0;
    vector->size = init_size;
    vector->data = (int *)malloc(sizeof(int) * init_size);
}
void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}


//插入操作以及顺序表的扩建
void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size *= 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) 
        vector->data[i] = old_data[i];
    free(old_data);
}
bool insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) return false;
    if (vector->length >= vector->size) expand(vector);
    for (int i = vector->length; i > loc; i--) 
        vector->data[i + 1] = vector->data[i];
    vector->data[loc] = value;
    vector->length++;
    return true;
} 

//删除loc处的元素
bool delete_node(Vector *vector, int loc) {
    if (loc < 0 || loc >= vector->length) return false;
    for (int i = loc; i < vector->length - 1; i--) 
        vector->data[i] = vector->data[i + 1];
    vector->length--;
    return true;
}

//找到值为value元素的位置
int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == value) return i;
    }
    return -1;
}

//打印输出顺序表中的元素
void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
        if (i) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}


int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int m = 0;
    scanf("%d", &m);
    while (m--) {
        int t;
        scanf("%d", &t);
        switch(t) {
            case 1: {
                int loc, value;
                scanf("%d %d", &loc, &value);
                if (insert(a, loc, value)) printf("insert success\n");
                else printf("insert failed\n");
                break;
            }
            case 2: {
                int loc;
                scanf("%d", &loc);
                if (delete_node(a, loc)) printf("delete success\n");
                else printf("delete failed\n");
                break;
            }
            case 3: {
                int value;
                scanf("%d", &value);
                int index = search(a, value);
                if (index + 1) printf("find success, index = %d\n", index);
                else printf("find failed\n");
                break;
            }
            case 4: {
                print(a);
                break;
            }
            default: {
                printf("something wrong\n");
            }
        }
    }
    clear(a);
    return 0;
}

/* 对应输入输出
9
1 0 1
insert success
1 5 2
insert failed
1 1 2
insert success
1 2 3
insert success
3 2
find success, index = 1
2 2
delete success
2 9
delete failed
3 3
find failed
4
1 2
*/

