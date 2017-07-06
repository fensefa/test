#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/timeb.h>
#include <sys/time.h>
using namespace std;

int64_t get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main() {

    clock_t start,ends;

    start=clock();
    cout << start << endl;
    cout << get_time() << endl;

    sleep(10);

    ends=clock();
    cout << ends << endl;
    cout << get_time() << endl;

    return 0;
}
