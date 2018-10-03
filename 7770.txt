#include <iostream>
using namespace std;

int N;

int main() {

	cin >> N;
	int sum = 0;
	int d = 1;

	while (sum < N) {
		d++;
		sum += d*d;
		sum += (d - 1)*(d - 1);
	}
	cout << d-1 << endl;

	return 0;
}