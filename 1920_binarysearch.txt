#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int in;
int M;

int Search(int in,int first,int last) {
	while (first <= last) {
		int mid = (first + last) / 2;
		if (arr[mid] == in) {
			return 1;
		}
		else if (arr[mid] > in) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr, arr + N);
	scanf("%d",&M);
	for (int i = 0; i < M; i++) {
		scanf("%d",&in);
		printf("%d\n",Search(in, 0, N - 1));
	}
	return 0;
}