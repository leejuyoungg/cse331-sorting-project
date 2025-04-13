#include <iostream>
#include <chrono>
#include <cassert>
#include <cmath>
#include "../basic_sort/basic_sort.h"
#include "../advanced_sort/advanced_sort.h"
#include "../data/input_generator.h"
#include "../basic_sort/is_sorted.h"

using namespace std;

#include <iomanip> // for setw and setprecision

void run_time_test() {
    const int sizes[] = {1000, 10000, 100000, 1000000};
    const unsigned int seed = 42;
    const string input_types[] = {"random", "ascending", "descending", "reverse", "partially_sorted"};

    // 헤더 출력
    cout << left << setw(18) << "Input Type"
         << setw(12) << "Size"
         << setw(18) << "Avg Time (ms)" << endl;
    cout << string(70, '-') << endl;

    for (int size : sizes) {
        int repetitions = 10;

        for (const string& type : input_types) {
            long long durations[10] = {};

            for (int i = 0; i < repetitions; i++) {
                int* arr = nullptr;
                
                if (type == "random") {
                    arr = generate_random_array(size, seed);
                } else if (type == "ascending") {
                    arr = generate_ascending_sorted_array(size, seed);
                } else if (type == "descending") {
                    arr = generate_descending_sorted_array(size, seed);
                } else if (type == "reverse") {
                    arr = generate_reverse_sorted_array(size, seed);
                } else if (type == "partially_sorted") {
                    arr = generate_partially_sorted_array(size, seed, 100, 200);
                }

                auto start = chrono::high_resolution_clock::now();
                selection_sort(arr, size);
                auto end = chrono::high_resolution_clock::now();
                
                durations[i] = chrono::duration_cast<chrono::milliseconds>(end - start).count();
                assert(is_sorted(arr, size, ASCENDING));
                delete[] arr;
            }

            long long total_time = 0;
            for (int i = 0; i < repetitions; i++) {
                total_time += durations[i];
            }

            double average_time = total_time / static_cast<double>(repetitions);

            double variance = 0.0;
            for (int i = 0; i < repetitions; i++) {
                variance += (durations[i] - average_time) * (durations[i] - average_time);
            };

            cout << left << setw(18) << type
                 << setw(12) << size
                 << setw(18) << fixed << setprecision(2) << average_time << endl;
        }
    }
}

int main() {
    run_time_test();
    return 0;
}
        
        
