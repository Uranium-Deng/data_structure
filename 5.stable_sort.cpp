/*************************************************************************
	> File Name: sort.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月20日 星期四 21时37分10秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

//稳定排序有：插入排序，冒泡排序，归并排序


#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}
#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) * n); \
    printf("%s:\n", #func); \
    output(num, n); \
    func(args); \
    output(num, n); \
    printf("\n"); \
    free(num); \
}

void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j - 1], arr[j]);
        }
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            flag = 1;
        }
        if (!flag) break;
    }
}

void merge_sort(int *arr, int head, int tail) {
    if (tail - head <= 1) {
        if (tail - head == 1 && arr[head] > arr[tail]) {
            swap(arr[head], arr[tail]);
        }
        return ;
    }
    int mid = (head + tail) >> 1;
    merge_sort(arr, head, mid);
    merge_sort(arr, mid + 1, tail);
    int *num = (int *)malloc(sizeof(int) * (tail - head + 1));
    int p1 = head, p2 = mid + 1, ind = 0;
    while (p1 <= mid || p2 <= tail) {
        if (p2 > tail || (p1 <= mid && arr[p1] <= arr[p2])) {
            num[ind++] = arr[p1++];
        } else {
            num[ind++] = arr[p2++];
        }
    }
    memcpy(arr + head, num, sizeof(int) * (tail - head + 1));
    free(num);
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

void randInt(int *a, int n) {
    while (n--) a[n] = rand() % 100;
}

int main() {
    #define MAX_N 20
    srand(time(0));
    int arr[MAX_N] = {0};
    randInt(arr, MAX_N);
    TEST(arr, MAX_N, insert_sort, num, MAX_N);
    TEST(arr, MAX_N, bubble_sort, num, MAX_N);
    TEST(arr, MAX_N, merge_sort, num, 0, MAX_N - 1);
    return 0;
}
