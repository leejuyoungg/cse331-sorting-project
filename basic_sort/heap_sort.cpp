#include "basic_sort.h"
#include <algorithm>

void max_heapify(int* arr, int i, int heap_size);
void build_max_heap(int* arr, int front, int back);

void max_heapify(int* arr, int i, int heap_size) {
    int left_child_index = 2 * i + 1;
    int right_child_index = 2 * i + 2;
    int largest = i;

    if (left_child_index < heap_size && arr[left_child_index] > arr[largest]) {
        largest = left_child_index;
    }
    if (right_child_index < heap_size && arr[right_child_index] > arr[largest]) {
        largest = right_child_index;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, heap_size); 
    }
}

void build_max_heap(int* arr, int front, int back) {
    for (int i = back / 2 - 1; i >= front; i--) {
        max_heapify(arr, i, back - front);
    } 

}
void heap_sort(int* arr, int front, int back) {
    build_max_heap(arr, front, back);
    for (int i = back - 1; i >= front + 1; i--) {
        std::swap(arr[front], arr[i]);
        back = back - 1;
        max_heapify(arr, front, back - front);
    }
}