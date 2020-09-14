### `syscall_timer.c`
This program times the 0-byte read from standard input using `gettimeofday`.
In testing, I found that the read occasionally took less than 1 microsecond. Therefore, I took 10 reads back to back.
The reported value is the fastest time recorded after repeating the timer `ITERS` times. As the number of iterations increases, the likelyhood of encountering an abnormally fast run increases. Therefore, I also compute the median and 95th percentile by storing each result in an array, then sorting it using the builtin `qsort`. However, it does require implementing your own comparator. To make getting the 95th percentile easy, I sort the array from high to low.

Run on gyoza.reed.edu for 100,000 iterations, my results are:

50th percentile: 3e-7 seconds
95th percentile: 2e-7 seconds
fastest time: 2e-7 seconds

Also, I compared results with Robert McCaul, who is also using gyoza, and our results seem to line up.
