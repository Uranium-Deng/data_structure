/*************************************************************************
	> File Name: 6.unstable_sort.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月20日 星期四 22时59分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

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


void select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        if (ind == i) continue;
        swap(arr[ind], arr[i]);
    }
}

void quick_sort(int *arr, int head, int tail) {
    if (head > tail) return ;
    int left = head, right = tail;
    int tmp = arr[head];
    while (left != right) {
        while (left < right && arr[right] >= tmp) right--;
        while (left < right && arr[left] <= tmp) left++;
        if (left != right) swap(arr[left], arr[right]);
    }
    arr[head] = arr[left];
    arr[left] = tmp;
    quick_sort(arr, head, left - 1);
    quick_sort(arr, left + 1, tail);
}

void randInt(int *arr, int n) {
    while (n--) arr[n] = rand() % 100;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    #define MAX_N 20
    srand(time(0));
    int arr[MAX_N];
    randInt(arr, MAX_N);
    TEST(arr, MAX_N, select_sort, num, MAX_N)
    TEST(arr, MAX_N, quick_sort, num, 0, MAX_N - 1)
    return 0;
}
