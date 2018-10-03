#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.precision(11);
	int N, K;
	cin >> N >> K;
	double min = 999999;
	double* arr = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = K; i <= N; i++) {
		for (int j = 0; j < N - i+1; j++) {
			double avg = 0;
			double bun = 0;
			for (int k = 0; k < i; k++) {
				avg += arr[j + k];
			}
			avg = avg / i;
			for (int k = 0; k < i; k++) {
				bun += pow(arr[j + k] - avg, 2);
			}
			bun = bun / i;
			
			if (min > sqrt(bun))
				min = sqrt(bun);
		}
	}
	cout << min << endl;

	return 0;
}