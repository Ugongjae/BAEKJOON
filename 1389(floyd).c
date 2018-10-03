#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num1, num2;

int graph[101][101];

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (j == i)
					continue;
				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
					else {
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
		}
	}
}

int main() {

	cin >> N >> M;
	

	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		graph[num1][num2] = 1;
		graph[num2][num1] = 1;
		
	}
	floyd();
	int res = 88888888;
	int outres = -1;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += graph[i][j];
		}
		if (res > sum) {
			res = sum;
			outres = i;
		}
	}

	cout << outres << endl;

	return 0;
}