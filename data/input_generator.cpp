#include <random>
#include <ctime>
#include <algorithm>
#include <functional>

int* generate_random_array(int size, unsigned int seed, int min_value, int max_value);
int* generate_ascending_sorted_array(int size, unsigned int seed, int min_value, int max_value);
int* generate_descending_sorted_array(int size, unsigned int seed, int min_value, int max_value);
int* generate_reverse_sorted_array(int size, unsigned int seed, int min_value, int max_value);

int* generate_random_array(int size, unsigned int seed, int min_value = 0, int max_value = 999) { /* min_value <= max_value*/
    int* arr = new int[size];
    std::mt19937 random_number_generator(seed);
    std::uniform_int_distribution<int> distribution(min_value, max_value);
    for (int i = 0; i < size; i++) {
        arr[i] = distribution(random_number_generator);
    }
    return arr;
}

int* generate_ascending_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999) {
    int* arr = generate_random_array(size, seed, min_value, max_value);
    std::sort(arr, arr + size);
    return arr;
}

int* generate_descending_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999) {
    int* arr = generate_random_array(size, seed, min_value, max_value);
    std::sort(arr, arr + size, std::greater<int>());
    return arr;
}

int* generate_reverse_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999) {
    int* arr = generate_ascending_sorted_array(size, seed, min_value, max_value);
    std::reverse(arr, arr + size);
    return arr;
}

int* generate_partially_sorted_array(int size, unsigned int seed, int sorted_start_index, int sorted_end_index, int min_value = 0, int max_value = 999) {
    int* arr = generate_random_array(size, seed, min_value, max_value);
    // 범위 방어어
    if (sorted_start_index < 0) sorted_start_index = 0;
    if (sorted_end_index >= size) sorted_end_index = size - 1;

    if (sorted_start_index <= sorted_end_index) {
        std::sort(arr + sorted_start_index, arr + sorted_end_index + 1);
    }

    return arr;
}
