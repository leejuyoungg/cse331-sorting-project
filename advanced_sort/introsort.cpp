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
    int i = f - 1; /* i + 1이 안 되고 arr[i] 할 일 없으니까 i = -1 되는 거 신경 안 써도 되는 거 맞나 */
    for (int j = f; j < b - 1; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[b - 1]); // 이 부분 이상
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
    while (b - f > 16) { // size_threshold = 16 고민
        if (depth_limit == 0) {
            heap_sort(arr, f, b);
            /*std::cout << "Entered heap_sort" << std::endl;
            for (int k = 0; k < 50; k++) {
                std::cout << arr[k] << " ";
            }
            std::cout << "\n";*/
            return;
        }
        depth_limit = depth_limit - 1;
        int q = median_of_3(arr, f, f + (b - f) / 2, b - 1);
        int p = partition_for_intro(arr, f, b, q);
        /*std::cout << "After partition with" << "f: " << f << " b: " << b << " pivot index: " << q << std::endl;
        for (int k = 0; k < 50; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << "\n";*/
        introsort_loop(arr, p + 1, b, depth_limit);
        /*std::cout << "After introsort_loop with" << "f: " << p + 1 << " b: " << b  << " depth_limit: " << depth_limit << std::endl;
        for (int k = 0; k < 50; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << "\n";*/
        b = p - 1;
    }
}

void introsort(int* arr, int f, int b) {
    /*int size = b - f;
    for (int k = 0; k < size; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << "\n";*/
    introsort_loop(arr, f, b, 2* floor(log2(b - f)));
    /*for (int k = 0; k < size; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << "\n";*/
    insertion_for_intro(arr, f, b);
    /*for (int k = 0; k < size; k++) {
        std::cout << arr[k] << " ";
    }*/
}








/*void introsort(int* arr, int maxdepth, int p, int r) {

    int n = size; // size 말고 index로 생각
    if (n <= 1) { // size 말고 index로 생각각
        return;
    }
    else if (maxdepth = 0) {
        heap_sort()
    }
}*/







