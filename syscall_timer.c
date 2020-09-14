#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

long int ms_diff(struct timeval a, struct timeval b) {
    const int MILLION = 1000000;
    if(a.tv_sec == b.tv_sec) {
        if(b.tv_usec - a.tv_usec > 0) {
            return b.tv_usec - a.tv_usec;
        }
        return a.tv_usec - b.tv_usec;
    }
    if(b.tv_sec > a.tv_sec) {
        return b.tv_usec + MILLION - a.tv_usec;
    } else {
        return ms_diff(b, a);
    }

}

int main() {
    const int ITERS = 100000;
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
    printf("fastest time: %lde-7\n", fastest);
    return 0;
}
