#include <iostream>
using namespace std;

int N;
long long sum=0;
int first = 0;
int second = 1;
int MOD = 1000000000;

int main() {

	cin >> N;
	if (N == 1) {
		cout << first << endl;
		return 0;
	}
	else if (N == 2) {
		cout << second << endl;
		return 0;
	}
	else {

		for (int i = 3; i <= N; i++) {
			sum = (long long)(i - 1)*(first + second) % MOD;
			first = second;
			second = sum;
		}
		cout << sum << endl;
		return 0;
	}
}