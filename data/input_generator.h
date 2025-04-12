#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H

int* generate_random_array(int size, unsigned int seed, int min_value = 0, int max_value = 999);
int* generate_ascending_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999);
int* generate_descending_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999);
int* generate_reverse_sorted_array(int size, unsigned int seed, int min_value = 0, int max_value = 999);
int* generate_partially_sorted_array(int size, unsigned int seed, int sorted_start_index, int sorted_end_index, int min_value = 0, int max_value = 999);

#endif // INPUT_GENERATOR_H