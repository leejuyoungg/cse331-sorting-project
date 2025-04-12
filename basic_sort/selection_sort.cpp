#include "basic_sort.h"
#include <algorithm> /*std::swap 써도 되는지*/

void selection_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);  // 교환
        }
    }
}