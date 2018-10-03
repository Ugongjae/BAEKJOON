#include <iostream>
using namespace std;


long long arr[1001][1001];

long long Com(int n, int r) {
	if (arr[n][r] > 0)
		return arr[n][r];
	if (n == r || r == 0) {
		return arr[n][r] = 1;
	}
	return arr[n][r] = Com(n - 1, r - 1) + Com(n - 1, r);

}

int  main() {

	int N, K;
	long long res;

	cin >> N >> K;
	res = Com(N, K);
	cout << res%10007 << endl;
	cin >> res;

	return 0;
}