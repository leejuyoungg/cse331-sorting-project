#ifndef BASIC_SORT_ALGORITHMS_H
#define BASIC_SORT_ALGORITHMS_H


/*insertion->selection->merge->heap->quick->bubble*/
void merge_sort(int* arr, int p, int r);
void heap_sort(int* arr, int front, int back);
void bubble_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void selection_sort(int* arr, int size);
void quick_sort(int* arr, int p, int r);



#endif 