#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int main() {

	int size;
	int input;
	int result=0;

	cin >> size;

	int** arr = new int*[size];
	int** arr2 = new int*[size];

	for (int i = 0; i < size; i++) {
		arr[i] = new int[i+1];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == i) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = max(arr[i][j]+arr[i-1][j-1],arr[i][j]+arr[i-1][j]);
			}
		}
	}
	for (int i = 0; i < size; i++) {
		result = max(result, arr[size - 1][i]);
	}
	cout << result << endl;


	return 0;
}