#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

long int ms_diff(struct timeval a, struct timeval b) {
    if(a.tv_sec > b.tv_sec) {
        return a.tv_usec - b.tv_usec;
    }
    return b.tv_usec - a.tv_usec;
}

int main() {
    const int ITERS = 10000;
    struct timeval start;
    struct timeval end;

    char data[128];
    long int fastest = LONG_MAX;
    printf("fastest: %ld\n", fastest);
    for(int i = 0; i < ITERS; i++) {
        gettimeofday(&start, NULL);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        read(0, data, 0);
        gettimeofday(&end, NULL);
        long int diff = ms_diff(start, end);
        if(diff < fastest) {
            fastest = diff;
        }
    }
    printf("fastest time: 0.%ld microseconds\n", fastest);
    return 0;
}
