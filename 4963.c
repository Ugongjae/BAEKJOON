#include <iostream>
using namespace std;

int M, N;
int sum = 0;
int graph[51][51];
int visit[51][51] = { 0 };
int xaxis[8] = { -1,0,1,-1,1,-1,0,1 };
int yaxis[8] = { -1,-1,-1,0,0,1,1,1 };

void Find(int x,int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + xaxis[i];
		int ny = y + yaxis[i];
		if (visit[nx][ny] == 0 && graph[nx][ny] == 1) {
			Find(nx, ny);
		}
	}
	
}

int main() {

	cin >> M >> N;
	while (M != 0 || N != 0) {
		sum = 0;
		for (int i = 0; i <= 50; i++) {
			for (int j = 0; j <= 50; j++) {
				if (i == 0 || j == 0) {
					visit[i][j] = 1;
				}
				else {
					visit[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (graph[i][j] == 1 && visit[i][j] == 0) {
					sum++;
					Find(i, j);
				}
			}
		}

		cout << sum << endl;
		cin >> M>>N;
	}

	return 0;
}