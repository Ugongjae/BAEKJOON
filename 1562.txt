#include <iostream>
#include <cmath>
using namespace std;

const int mod = 1000000000;

int main() {

	int dp[101][10][1 << 10];
	int N = 0;
	int res = 0;
	cin >> N;

	int full = (1 << 10) - 1;

	for (int j = 1; j <= 9; ++j)
		dp[1][j][1 << j] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= full; ++k) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}

	for (int j = 0; j <= 9; ++j)
		res = (res + dp[N][j][full]) % mod;
	cout << res << endl;
	return 0;
}