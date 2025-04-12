#include <iostream>
#include <cassert>
#include <cmath> /*이거 뭘 위한 거지*/
#include "../basic_sort/basic_sort.h"
#include "../advanced_sort/advanced_sort.h"
#include "../data/input_generator.h"
#include "../basic_sort/is_sorted.h"

using namespace std;

int main() {
    int size = 1000;
    int seed = 42;
    int* arr1 = generate_random_array(size, seed);
    int* arr2 = generate_random_array(size, seed);
    int* arr3 = generate_random_array(size, seed);
    int* arr4 = generate_random_array(size, seed);
    int* arr5 = generate_random_array(size, seed);
    int* arr6 = generate_random_array(size, seed);
    int* arr7 = generate_random_array(size, seed);
    int* arr8 = generate_random_array(size, seed);
    int* arr9 = generate_random_array(size, seed);
    int* arr10 = generate_random_array(size, seed);

    merge_sort(arr1, 0, size - 1);
    heap_sort(arr2, 0, size);
    bubble_sort(arr3, size);
    insertion_sort(arr4, size);
    selection_sort(arr5, size);
    quick_sort(arr6, 0, size - 1);
    cocktail_shaker_sort(arr7, size);
    comb_sort(arr8, size);
    tim_sort(arr9, size);
    introsort(arr10, 0, size);
 
    assert(is_sorted(arr1, size, ASCENDING));
    assert(is_sorted(arr2, size, ASCENDING));
    assert(is_sorted(arr3, size, ASCENDING));
    assert(is_sorted(arr4, size, ASCENDING));
    assert(is_sorted(arr5, size, ASCENDING));
    assert(is_sorted(arr6, size, ASCENDING));
    assert(is_sorted(arr7, size, ASCENDING));
    assert(is_sorted(arr8, size, ASCENDING));
    assert(is_sorted(arr9, size, ASCENDING));
    assert(is_sorted(arr10, size, ASCENDING));

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;
    delete [] arr8;
    delete [] arr9;
    delete [] arr10;
}