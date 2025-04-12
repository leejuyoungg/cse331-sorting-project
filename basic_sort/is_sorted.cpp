#include "is_sorted.h"

bool is_sorted(int* arr, int size, SortOrder order) {
    for (int i = 0; i < size - 1; i++) {
        if (order == ASCENDING && arr[i] > arr[i + 1]) return false;
        if (order == DESCENDING && arr[i] < arr[i + 1]) return false;
    }
    return true;
}
