## Find if number is perfect

Compile: `g++ -o isPerfect isPerfect.cpp -lpthread`

Run: `./isPerfect <N> <P>` where 2 <= N <= 4294967295 and P >= 1

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

The experiments were performed on an Intel Core i7-6700HQ CPU @ 2.60GHz (L2 cache: 1MB)

#### Figure 1:
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/completion%20time.jpg)
##
#### Figure 2:
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/graph%201.png)
##
#### Figure 3:
![alt text](https://github.com/LedioTerolli/isNumberPerfect/blob/master/graph%202.png)
