#include <iostream>
using namespace std;

int graph[10001][21] = { 0 };
int T_case;
int coinnum;
int num[21];
int price;

int main() {

	cin >> T_case;
	for (int t = 0; t < T_case; t++) {
		cin >> coinnum;
		int sum = 0;

		for (int i = 1; i <= coinnum; i++)
			cin >> num[i];
		cin >> price;
		for (int i = 0; i <= price; i++) {
			for (int j = 0; j <= coinnum; j++)
				graph[i][j] = 0;
		}
		for (int i = 1; i <= price; i++) {
			for (int j = 1; j <= coinnum; j++) {
				if (i == num[j])
					graph[i][j] = 1;
				else if (i > num[j]) {
					for (int k = 1; k <= j; k++) {
						graph[i][j] += graph[i - num[j]][k];
					}
				}
				else
					graph[i][j] = 0;
			}
		}
		for (int i = 1; i <= coinnum; i++) {
			sum += graph[price][i];
		}
		cout << sum << endl;
	}
	return 0;
}