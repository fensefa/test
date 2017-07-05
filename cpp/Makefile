CXXFLAGS = -std=c++11 -g -Wall -O0
BOOST = -lboost_thread -lboost_system -lpthread

all: test

run: test
	./test

boost:
	$(CXX) $(CXXFLAGS) $(BOOST) test.cpp -o test

clean:
	rm -rf *.o test
