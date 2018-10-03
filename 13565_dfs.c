#include <iostream>
#include <string>
using namespace std;

string graph[1001];
int N, M;

void DFS(int x,int y) {
	if (x >= 0 && y >= 0&&x<M&&y<N) {
		if (graph[x][y] == '0') {
			graph[x][y] = '2';
			DFS(x + 1, y);
			DFS(x - 1, y);
			DFS(x, y + 1);
			DFS(x, y - 1);
		}
	}
}

int main() {

	cin >> M >> N;
	
	for (int i =0 ; i < M; i++) {
		cin >> graph[i];
	}
	for (int i = 0; i < N; i++) {
		DFS(0,i);
	}
	for (int i = 0; i < N; i++) {
		if (graph[M-1][i] == '2') {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}