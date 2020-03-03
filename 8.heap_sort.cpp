/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月19日 星期三 09时34分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

void update(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int tmp = ind, lchild = ind * 2, rchild = lchild + 1;
        if (arr[tmp] < arr[lchild]) tmp = lchild;
        if (rchild <= n && arr[rchild] > arr[tmp]) tmp = rchild;
        if (tmp == ind) break;
        swap(arr[tmp], arr[ind]);
        ind = tmp;
    }
}

void heap_sort(int *arr, int n) {
    arr--;
    for (int i = n >> 1; i >= 1; i--) {
        update(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        update(arr, i - 1, 1);
    }
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}



int main() {
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP + 5] = {0};
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    return 0;
}
