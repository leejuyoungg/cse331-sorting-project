#include "advanced_sort.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "../basic_sort/basic_sort.h"

int partition_for_intro(int* arr, int f, int b);
void insertion_for_intro(int* arr, int f, int b);
int median_of_3(int f, int m, int b);
void introsort_loop(int* arr, int f, int b, int depth_limit);


int partition_for_intro(int* arr, int f, int b, int p) {
    std::swap(arr[b - 1], arr[p]);
    int pivot = arr[b - 1];
    int i = f - 1; 
    for (int j = f; j < b - 1; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[b - 1]); 
    return i + 1;
}

void insertion_for_intro(int* arr, int f, int b) {
    int size = b - f;
    for (int j = 1; j < size; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

int median_of_3(int* arr, int f, int m, int b) {
    if ((arr[f] <= arr[m] && arr[m] <= arr[b]) || (arr[b] <= arr[m] && arr[m] <= arr[f])) {
        return m;
    } else if ((arr[m] <= arr[f] && arr[f] <= arr[b]) || (arr[b] <= arr[f] && arr[f] <= arr[m])) {
        return f;
    } else {
        return b;
    }
}

void introsort_loop(int* arr, int f, int b, int depth_limit) {
    while (b - f > 16) { 
        if (depth_limit == 0) {
            heap_sort(arr, f, b);
            return;
        }
        depth_limit = depth_limit - 1;
        int q = median_of_3(arr, f, f + (b - f) / 2, b - 1);
        int p = partition_for_intro(arr, f, b, q);
        introsort_loop(arr, p + 1, b, depth_limit);
        b = p - 1;
    }
}

void introsort(int* arr, int f, int b) {
    introsort_loop(arr, f, b, 2* floor(log2(b - f)));
    insertion_for_intro(arr, f, b);
}






