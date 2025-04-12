#include "basic_sort.h"

void insertion_sort(int* arr, int size) {
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