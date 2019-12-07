## Perfect Number on Multicore Systems

In number theory, a perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number. This program determines whether a positive integer has this property.

Compile: `g++ -o isPerfect isPerfect.cpp -lpthread`

Run: `./isPerfect <N> <P>` where 2 <= N(number) <= 4294967295 and P(threads) >= 1

Returns:
* `0` if number is perfect
* `1` if number is not perfect
* `2` if error occurred

#### e.g.:
````
terolli@debian:~/Desktop$ ./isPerfect 33550336 10
16775168
8387584
4193792
2096896
1048448
524224
262112
131056
65528
32764
16382
8191
4096
2048
1024
512
256
128
64
32
16
8
4
2
1
sum = 33550336
N   = 33550336
terolli@debian:~/Desktop$ echo $?
0
````

##

##### The experiments were performed on an Intel Core i7-6700HQ CPU @ 2.60GHz (L2 cache: 1MB). In the table below I compare the completion times of serial and multithreaded programs. For N > 1000000, 8 threads produce the greatest speed-up gain.
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/misc/completion%20time.jpg)
##
##### Completion time in microseconds (serial vs 8 threads)
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/misc/graph%201.png)
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/misc/graph%202.png)
