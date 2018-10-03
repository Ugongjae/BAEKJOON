#include <iostream>
using namespace std;

int graph[1001][1001] = { 0 };
int num[1001];
int N=0;

int Com(int i, int j) {
	int min = 20000000;
	int max = -1;
	for (int a = j; a <= i; a++) {
		if (min > num[a])
			min = num[a];
		if (max < num[a])
			max = num[a];
	}
	return max - min;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			graph[i][j] = graph[j - 1][0] + Com(i, j);
		}
		for (int j = 1; j <= i; j++) {
			if (graph[i][0] < graph[i][j])
				graph[i][0] = graph[i][j];
		}
	}
	cout << graph[N][0] << endl;
	cin >> N;

	return 0;
}