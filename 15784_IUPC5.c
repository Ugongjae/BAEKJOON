#include <iostream>
using namespace std;

#define HAPPY 0
#define ANGRY 1

int main() {

	int N, x, y;
	cin >> N >> x >> y;
	x--;
	y--;
	int res = 0;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (arr[i][y] > arr[x][y])
			res = ANGRY;
	}
	for (int i = 0; i < N; i++) {
		if (arr[x][i] > arr[x][y])
			res = ANGRY;
	}
	if (res == ANGRY)
		cout << "ANGRY" << endl;
	else
		cout << "HAPPY" << endl;

	return 0;
}