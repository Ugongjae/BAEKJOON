
#include <iostream>
using namespace std;

int arr[5000001];
int K;

int partition(int left, int right) {
	int pivot = (left + right) / 2;
	int pival = arr[pivot];

	swap(arr[pivot], arr[right]);

	int index = left;

	for (int i = left; i < right; i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[index], arr[right]);
	return index;
}

void Quick(int left, int right) {
	if (left < right) {
		int pivot = partition(left, right);
		if (K <= pivot)
			Quick(left, pivot - 1);
		else
			Quick(pivot + 1, right);
	}


}
int main() {

	int N;
	int input_num;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input_num);
		//cin >> input_num;
		arr[i] = input_num;
	}
	Quick(0,N-1);
	cout << arr[K - 1] << endl;

	return 0;
}