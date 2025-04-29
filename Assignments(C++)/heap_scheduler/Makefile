CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:. cpp=.o)
TARGET = heap_scheduler

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
