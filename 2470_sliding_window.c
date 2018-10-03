#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	int minarr[2] = { 0,0 };
	int min = 999999;

	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + N);

	int i = 0;
	int j = N - 1;
	while (i < j) {
		if (min > abs(arr[i] + arr[j])) {
			minarr[0] = i;
			minarr[1] = j;
			min = abs(arr[i] + arr[j]);
		}
		if (arr[i] + arr[j] < 0)
			i++;
		else
			j--;
	}


	if (arr[minarr[0]] < arr[minarr[1]])
		cout << arr[minarr[0]] << " " << arr[minarr[1]] << endl;
	else
		cout << arr[minarr[1]] << " " << arr[minarr[0]] << endl;

	return 0;
}