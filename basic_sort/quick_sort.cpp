#include "basic_sort.h"
#include <algorithm>
#include <cstdlib>

int partition(int* arr, int p, int r);

int partition(int* arr, int p, int r) {
    int pivot_index = p + rand() % (r - p + 1);
    std::swap(arr[r], arr[pivot_index]);
    int pivot = arr[r];
    int i = p - 1; /* i + 1이 안 되고 arr[i] 할 일 없으니까 i = -1 되는 거 신경 안 써도 되는 거 맞나 */
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}