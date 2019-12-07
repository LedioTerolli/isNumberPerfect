#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <unsigned int> factors_v;
unsigned long long sum = 0;

void find_n_update(unsigned int begin, unsigned int endv, unsigned int number) {
	while (endv >= begin) {
		if (number % endv == 0) {
			sum += endv;
			factors_v.push_back(endv);
			if (sum > number) {
				break;
			}
		}
		endv--;
	}
}

int main(int argc, char* argv[]) {
	unsigned int begin = 1, endv, number;
	if (argc == 2) {
		sscanf(argv[1], "%u", &number);
	}
	else {
		cout << "Usage: ./serial <N>" << endl;
		return 2;
	}

	endv = number - 1;
	find_n_update(begin, endv, number);

	sort(factors_v.begin(), factors_v.end(), greater<unsigned int>());
	for (auto i = factors_v.begin(); i != factors_v.end(); ++i) {
		cout << *i << endl;
	}

	cout << "sum = " << sum << endl;
	cout << "N   = " << number << endl;

	if (sum == number) return 0;
	else return 1;
}
