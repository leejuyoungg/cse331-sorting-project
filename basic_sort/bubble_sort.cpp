#include "basic_sort.h"
#include <algorithm>

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) { // 마지막 값은 자동 정렬되므로 n-1번까지만 반복한다.
        for (int j = 0; j < size - i - 1; j++) { // i번 돌때마다 마지막 값에는 큰 값이 들어오므로 끝까지 비교할 필요가 없다. 따라서 n-i-1번까지만 비교한다.
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}