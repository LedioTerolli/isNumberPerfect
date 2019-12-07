/*
================================================================================

purpose: find if perfect
how to compile: g++ -o isPerfect isPerfect.cpp -lpthread
how to run: ./isPerfect <N> <P>
return: 0 if number is perfect, 1 if number is not perfect, 2 if error occurred
how to check return code: echo $?

@author Ledio Terolli
================================================================================
*/

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>

using namespace std;

// shared variables
unsigned long long sum = 0;
vector<unsigned int> factors_v;
bool flag = false;

//synchronization using mutex
mutex mtx;

void find_n_update(unsigned int begin, unsigned int endv, unsigned int number) {
	while (endv >= begin) {
		if (flag) break; // break if sum is already larger than number
		if (number % endv == 0) {
			// critical section (exclusive access to shared variables signaled by locking mtx)
			lock_guard<mutex> lck (mtx);
			sum += endv;// add factor to sum
			factors_v.push_back(endv); // push factor to factors list
			if (sum > number) {
				flag = true; // flag signals main process to return 1
			}
		}
		endv--;
	}
}

int main(int argc, char* argv[]) {
	factors_v.clear();
	unsigned int begin, endv, number;
	short n_threads;

	// read command line arguments
	if (argc == 3) {
		sscanf(argv[1], "%u", &number);
		sscanf(argv[2], "%hu", &n_threads);
	}
	else {
		cout << "Usage: ./isPerfect <N> <P>" << endl;
		return 2;
	}

	if (number < 2 || n_threads < 1) {
		cout << "Usage: ./isPerfect <N> <P>" << endl;
		cout << "where 2 <= N <= 4294967295 and P >= 1" << endl;
		return 2;
	}

	if (number < n_threads) {
		cout << "Usage: ./isPerfect <N> <P>" << endl;
		cout << "where N >= P" << endl;
		return 2;
	}

	thread threads[n_threads];
	unsigned int interval = number / n_threads;

	for (unsigned int i = 0; i < n_threads; ++i) {
		// determine intervals
		begin = interval * i + 1;
		if (i == n_threads - 1) endv = number - 1;
		else endv = interval * (i + 1);

		// create thread
		threads[i] = thread(find_n_update, begin, endv, number);
	}

	// join all threads
	for (auto& th : threads) {
		// safe join
		if (th.joinable()) th.join();
	}

	// sort factors list before print
	sort(factors_v.begin(), factors_v.end(), greater<unsigned int>());

	// print factors list, sum and N
	for (auto i = factors_v.begin(); i != factors_v.end(); ++i) {
		cout << *i << endl;
	}
	cout << "sum = " << sum << endl;
	cout << "N   = " << number << endl;

	// check if sum is already larger than number
	if (flag) {
		return 1;
	}

	// check if number is perfect
	if (sum == number) return 0;
	else return 1;
}
