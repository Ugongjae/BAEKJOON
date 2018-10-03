#include <iostream>
using namespace std;

int main() {

	int N, K;
	int res = 0;
	cin >> N>>K;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int a = N - 1;
	while (K != 0) {
		int b = K / arr[a];
		K = K - (b*arr[a]);
		res += b;
		a--;
	}
	cout << res << endl;

	return 0;
}