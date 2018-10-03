#include <iostream>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	int* top = new int[N];
	int* mid = new int[K];
	int max = -1;
	int max2 = -1;

	for (int i = 0; i < N; i++) {
		cin >> top[i];
		if (max < top[i]) {
			max = top[i];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> mid[i];
		if (max2 < mid[i]) {
			max2 = mid[i];
		}
	}
	cout << max + max2 << endl;


	return 0;
}