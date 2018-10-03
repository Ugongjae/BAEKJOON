#include <iostream>
using namespace std;

int getX(int a) {
	if (a == 0)
		return 0;
	else if (a == 1) {
		return 5000000;
	}
	else if (a > 1 && a <= 3) {
		return 3000000;
	}
	else if (a > 3 && a <= 6) {
		return 2000000;
	}
	else if (a > 7 && a <= 10) {
		return 500000;
	}
	else if (a > 10 && a <= 15) {
		return 300000;
	}
	else if (a > 15 && a <= 21) {
		return 100000;
	}
	else
		return 0;
}
int getY(int b) {
	if (b == 0) {
		return 0;
	}
	else if (b == 1) {
		return 5120000;
	}
	else if (b > 1 && b <= 3) {
		return 2560000;
	}
	else if (b > 3 && b <= 7) {
		return 1280000;
	}
	else if (b > 7 && b <= 15) {
		return 640000;
	}
	else if (b > 15 && b <= 31) {
		return 320000;
	}
	else
		return 0;
}

int main() {

	int N;
	int a, b;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << getX(a) + getY(b) << endl;
	}

	return 0;
}