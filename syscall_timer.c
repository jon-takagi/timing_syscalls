#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

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
int compare(const void * e1, const void * e2) {
    long int a = *((long int*) e1);
    long int b = *((long int*) e2);
    if(a > b) return -1;
    if(a < b) return 1;
    return 0;
}
int main() {
    const int ITERS = 100000;
    struct timeval start;
    struct timeval end;

    char data[128];
    long int results[ITERS];
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
        results[i] = diff;
        if(diff < fastest) {
            fastest = diff;
        }
    }
    qsort(results, ITERS, sizeof(long int), compare);
    int index = 95 * ITERS / 100;
    printf("50th percentile: %lde-7 seconds\n", results[50 * ITERS / 100]);
    printf("95th percentile: %lde-7 seconds\n", results[index]);
    printf("fastest time: %lde-7 seconds\n", fastest);

    return 0;
}
