#pragma warning(disable:4996)

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int input_num;
	int min;
	int res = 0;

	cin >> input_num;
	if (input_num <= 18)
		min = 9;
	else if (input_num <= 117 && input_num > 18)
		min = 18;
	else if (input_num <= 1026 && input_num > 117)
		min = 27;
	else if (input_num <= 10035 && input_num > 1026)
		min = 36;
	else if (input_num <= 100044 && input_num > 10035)
		min = 45;
	else if (input_num <= 1000053 && input_num > 100044)
		min = 54;
	else if (input_num <= 10000062 && input_num > 1000053)
		min = 63;
	else if (input_num <= 100000071 && input_num > 1000062)
		min = 72;

	for (int i = input_num; (i >= input_num - min&&i > 0); i--) {
		int arr[8] = { 0,0,0,0,0,0,0,0 };
		int tmp = i;
		tmp += i % 10;
		for (int j = 1; j <= 8; j++) {
			int a = pow(10, j);
			arr[j-1] = (i / a)%10;
		}
		for (int k = 0; k < 8; k++) {
			tmp += arr[k];
		}
		if (tmp == input_num)
			res = i;
	}

	cout << res << endl;
	return 0;
}