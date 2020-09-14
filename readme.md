### `syscall_timer.c`
This program times the 0-byte read from standard input using `gettimeofday`.
In testing, I found that the read occasionally took less than 1 microsecond. Therefore, I took 10 reads back to back.
The reported value is the fastest time recorded after repeating the timer `ITERS` times. As the number of iterations increases, the likelyhood of encountering an abnormally fast run increases. Computing the 95th percentile (the time that 95% of runs are better than) would probably be better, but this update is being pushed at 2:15.

Run on gyoza.reed.edu for 10,000 iterations, I find the fastest time is 0.4 microseconds.
