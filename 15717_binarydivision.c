#include <iostream>
#include <math.h>
using namespace std;

int DIV = 1000000007;


unsigned long long N;

int main() {
	
	cin >> N;
	int zero = 0;
	N--;
	if (N == 0) {
		cout << zero << endl;
		return 0;
	}

	long long res=2;
	long long ans = 1;
	while (N > 0) {
		if ((N % 2) == 1)
			ans = (ans*res) % DIV;
		N /= 2;
		res = (res*res) % DIV;
	}
	cout << ans << endl;

	return 0;
}