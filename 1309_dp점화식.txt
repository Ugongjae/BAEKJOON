#include <iostream>
using namespace std;

int graph[100001] = { 1,3 };
int MOD = 9901;
int N;
long long sum = 0;

int main() {

	cin >> N;

	for (int i = 2; i <= N; i++)
		graph[i] = (graph[i - 1] * 2 + graph[i - 2])%9901;
	cout << graph[N] << endl;

}