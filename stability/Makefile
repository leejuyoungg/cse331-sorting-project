# 컴파일러와 플래그
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# 소스 파일들
SRCS = \
    stability_test.cpp \
    bubble_sort.cpp \
    cocktail_shaker_sort.cpp \
    insertion_sort.cpp \
    merge_sort.cpp \
    tim_sort.cpp

# 오브젝트 파일들
OBJS = $(SRCS:.cpp=.o)

# 헤더 포함 경로 (현재 디렉터리)
INCLUDES = -I.

# 최종 실행 파일
TARGET = stability_test

# 기본 빌드 타겟
all: $(TARGET)

# 링크
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# 개별 파일 컴파일
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# 정리
clean:
	rm -f $(OBJS) $(TARGET)
