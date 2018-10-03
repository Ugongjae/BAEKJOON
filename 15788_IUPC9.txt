#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;
	int x, y;
	long long sum = 0;
	long long targetsum = 0;
	long long target = 0;
	int res = 1;
	long long arr[500][500];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
	if (x == 0) {
		for (int i = 0; i < N; i++) {
			sum += arr[1][i];
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			sum += arr[0][i];
		}
	}
	for (int i = 0; i < N; i++) {
		targetsum += arr[x][i];
	}
	target = sum - targetsum;
	arr[x][y] = target;
	for (int i = 0; i < N; i++) {
		targetsum = 0;
		for (int j = 0; j < N; j++) {
			targetsum += arr[i][j];
		}
		if (targetsum != sum) {
			res = 0;
			break;
		}
	}
	if (res == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		targetsum = 0;
		for (int j = 0; j < N; j++) {
			targetsum += arr[j][i];
		}
		if (targetsum != sum) {
			res = 0;
			break;
		}
	}
	if (res == 0) {
		cout << -1 << endl;
		return 0;
	}
	int i = 0;
	targetsum = 0;
	while (i < N) {
		targetsum += arr[i][N-i-1];
		i++;
	}
	if (targetsum != sum) {
		cout << -1 << endl;
		return 0;
	}
	i = 0;
	targetsum = 0;
	while (i < N) {
		targetsum += arr[i][i];
		i++;
	}
	if (targetsum != sum) {
		cout << -1 << endl;
		return 0;
	}

	cout << target << endl;
	return 0;
}