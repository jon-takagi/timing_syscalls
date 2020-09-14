#include <sys/time.h>
#include <stdio.h>
int main() {
    struct timeval time1;
    for(int i = 0; i < 100; i++) {
        gettimeofday(&time1, NULL);
        printf("%ld\n", (time1.tv_usec));
    }
    return 0;
}
