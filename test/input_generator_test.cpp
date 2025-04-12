#include <cassert>
#include <iostream>
#include "../data/input_generator.h"
#include "../basic_sort/is_sorted.h"

void test_input_generators() {
    const int size = 1000;
    const unsigned int seed = 123;

    // random array: same seed should generate same output
    int* rand1 = generate_random_array(size, seed);
    int* rand2 = generate_random_array(size, seed);
    for (int i = 0; i < size; i++) assert(rand1[i] == rand2[i]);
    delete[] rand1; delete[] rand2;

    // ascending
    int* asc = generate_ascending_sorted_array(size, seed);
    assert(is_sorted(asc, size, ASCENDING));
    delete[] asc;

    // descending
    int* desc = generate_descending_sorted_array(size, seed);
    assert(is_sorted(desc, size, DESCENDING));
    delete[] desc;

    // reverse sorted
    int* rev = generate_reverse_sorted_array(size, seed);
    assert(is_sorted(rev, size, DESCENDING));  // reverse는 내림차순
    delete[] rev;

    // partially sorted
    int* part = generate_partially_sorted_array(size, seed, 100, 200);
    assert(is_sorted(part + 100, 101, ASCENDING)); // 100~200 구간만 확인
    delete[] part;

    std::cout << "[PASS] 모든 입력 생성기 테스트 성공\n";
}

int main() {
    test_input_generators();
    return 0;
}