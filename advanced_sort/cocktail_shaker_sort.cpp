#include "advanced_sort.h"
#include <algorithm>

void cocktail_shaker_sort(int* arr, int size) {
    bool swapped = true;

    for (int i = 0; i < size / 2 && swapped; i++) {
        swapped = false;

        for (int j = i; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        for (int k = size - i - 2; k > i; k--) {
            if(arr[k] < arr[k - 1]) {
                std::swap(arr[k], arr[k - 1]);
                swapped = true;
            }
        }
    }
}