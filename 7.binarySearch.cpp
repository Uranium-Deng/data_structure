/************************************************************************
	> File Name: 7.binarySearch.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月20日 星期四 23时42分11秒
 ************************************************************************/

#include <iostream>
using namespace std;


#define P(func, args...) { \
    printf("%s = %d\n", #func, func(args)); \
}

int binarySearch_1(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//1111100000 找到最后一个1
int binarySearch_2(int *arr, int n) {
    int head = -1, tail = n - 1;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (arr[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//000000111111找到第一个1
int binarySearch_3(int *arr, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}


int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    printf("num %d's index = %d\n", 7, binarySearch_1(arr1, 10, 7));
    P(binarySearch_2, arr2, 10);
    P(binarySearch_3, arr3, 10);
    return 0;
}
