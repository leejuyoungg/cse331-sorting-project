#include "basic_sort.h"
#include <limits>

void merge(int* arr, int p, int q, int r);

void merge(int* arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* left_arr = new int[n1 + 1];
    int* right_arr = new int[n2 + 1];
    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[q + 1 + j];
    }
    left_arr[n1] = std::numeric_limits<int>::max();
    right_arr[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i = i + 1;
        }
        else {
            arr[k] = right_arr[j];
            j = j + 1;
        }
    }

    delete [] left_arr;
    delete [] right_arr;
}

void merge_sort(int* arr, int p, int r) {
     if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
     }
}