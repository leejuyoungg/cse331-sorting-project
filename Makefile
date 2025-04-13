CXX = g++
CXXFLAGS = -std=c++17 -Wall -I basic_sort -I data -I advanced_sort -fsanitize=address

SRC = test/test.cpp data/input_generator.cpp basic_sort/is_sorted.cpp basic_sort/insertion_sort.cpp basic_sort/merge_sort.cpp basic_sort/bubble_sort.cpp basic_sort/selection_sort.cpp basic_sort/heap_sort.cpp basic_sort/quick_sort.cpp advanced_sort/cocktail_shaker_sort.cpp advanced_sort/comb_sort.cpp advanced_sort/tim_sort.cpp advanced_sort/introsort.cpp advanced_sort/library_sort.cpp advanced_sort/tournament_sort.cpp
OUT = selection_sort

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
