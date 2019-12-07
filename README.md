## Find if number is perfect

Compile:
* `g++ -o isPerfect isPerfect.cpp -lpthread`

Run:
* `./isPerfect <N> <P>`

Return:
* 0 if number is perfect
* 1 if number is not perfect
* 2 if error occurred

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

The experiments were performed on an Intel Core i7-6700HQ CPU @ 2.60GHz (L2 cache: 1MB).

#### Figure 1 table:
(stride = 8B)

![alt text](https://github.com/cunychenhclass/cisc3320proj2-shell8/blob/master/Ledio%20Terolli/figure%201.jpg "Figure 1")

#### Figure 2 table:

![alt text](https://github.com/cunychenhclass/cisc3320proj2-shell8/blob/master/Ledio%20Terolli/figure%202.jpg "Figure 2")

##### REFERENCES
###### [1]	Chuanpeng Li, Chen Ding, and Kai Shen. Quantifying the cost of context switch. In Proceedings of the 2007 Workshop on Experimental Computer Science, ExpCS ’07, New York, NY, USA, 2007. ACM
