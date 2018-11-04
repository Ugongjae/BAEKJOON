#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, X;
vector<vector<int>> arr;
vector<vector<int>> arr2;
int INF = 98765432;
int in1, in2, in3;

int dijkstra() {
	vector<int> visit;
	vector<int> dist2;
	vector<int> dist;
	int min;
	int v;

	visit.assign(N + 1, 0);
	dist.assign(N + 1, INF);
	dist2.assign(N + 1, INF);
	dist[X] = 0;
	dist2[X] = 0;

	for (int i = 1; i <= N; i++) {
		min = INF;
		for (int j = 1; j <= N; j++) {
			if (min > dist[j] && visit[j] == 0) {
				min = dist[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (int j = 1; j <= N; j++) {
			if (dist[j] > dist[v] + arr[v][j]) {
				dist[j] = dist[v] + arr[v][j];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		min = INF;
		for (int j = 1; j <= N; j++) {
			if (min > dist2[j] && visit[j] == 0) {
				min = dist2[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (int j = 1; j <= N; j++) {
			if (dist2[j] > dist2[v] + arr2[v][j]) {
				dist2[j] = dist2[v] + arr2[v][j];
			}
		}
	}
	int maxnum = -1;
	for (int i = 1; i <= N; i++) {
		if (maxnum < dist[i] + dist2[i])
			maxnum = dist[i] + dist2[i];
	}
	return maxnum;
}

int main() {

	cin >> N >> M >> X;
	arr.assign(N+1, vector<int> (N+1, INF));
	arr2.assign(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i < M; i++) {
		cin >> in1 >> in2 >> in3;
		arr[in1][in2] = in3;
		arr2[in2][in1] = in3;
	}
	cout << dijkstra() << endl;

	return 0;
}
