#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    const int ITERS = 100000;
    struct timeval start;
    struct timeval end;

    char data[128];
    gettimeofday(&start, NULL);
    for(int i = 0; i < ITERS; i++) {
        read(0, data, 0);
    }
    gettimeofday(&end, NULL);
    printf("%ld\n", (end.tv_usec - start.tv_usec) / ITERS);

    return 0;
}
