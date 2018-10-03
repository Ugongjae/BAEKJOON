#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	string in;
	vector<int> arr;
	int num;
	long long sum = 0;

	cin >> num;
	cin >> in;
	for (int i = 0; i < num+1; i++) {
		arr.push_back(-1);
	}

	for (int i = 0; i < in.length(); i++) {
		if ((int)in[i] < 58 && (int)in[i]>47)
			arr[i] = (int)in[i] - 48;
	}
	for (int i = 0; i < in.length(); i++) {
		if (arr[i] != -1) {
			int j = i;
			while (arr[j] != -1)
				j++;
			sum += arr[i] * pow(10, j - i-1);
		}
	}
	cout << sum<<endl;
	return 0;
}