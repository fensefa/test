test: hello.cpp
	mpicxx -o test hello.cpp

run: test
	mpirun -n 4 ./test

clean:
	rm -rf *.o test
