#include "basic_sort.h"
#include <algorithm>

void bubble_sort(int* arr, int size) {
    int n = size;
    while (n > 1) {
        int new_n = 0;
        for (int i = 0; i < n - 1; i++) { // 마지막 값은 자동 정렬되므로 n-1번까지만 반복한다.
            if(arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                new_n = i + 1;
            }
        }
        n = new_n;
    }
}