#include <iostream>
using namespace std;

int N;

int main() {

	cin >> N;

	while (N != 0) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += i*i;
		}
		cout << sum << endl;
		cin >> N;
	}

	return 0;
}