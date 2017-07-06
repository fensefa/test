AXXFLAGS = -std=c++0x -g -Wall
AXXFLAGS += -pthread

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARGET=test_static

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

test: $(OBJS)
	$(CXX) $(CXXFLAGS) main.o 1.o -o test
	./test

clean:
	rm -rf *.o $(TARGET) test
