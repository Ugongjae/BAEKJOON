#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Rootstruct
{
	int index;
	int sum;
};

int findRoot(int* arr, int x) {
	if (arr[x] == x)
		return x;
	else
		findRoot(arr, arr[x]);

}
void setRoot(int* arr, int x, int y) {
	if (x == y)
		return;
	else {
		if (x > y) {
			arr[x] = y;
			return;
		}
		else {
			arr[y] = x;
			return;
		}
	}
}
bool stComp(Rootstruct& a,Rootstruct& b) {
	return a.sum > b.sum;
}

int main() {

	int N, K;
	cin >> N >> K;
	int *root = new int[N+1];
	vector<Rootstruct> rootsum;
	Rootstruct b = {0,0};
	rootsum.push_back(b);
	for (int i = 1; i <= N; i++) {
		root[i] = i;
		Rootstruct a = { i,0 };
		rootsum.push_back(a);
	}


	int x, y,z;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		int x_root;
		int y_root;
		x_root = findRoot(root, x);
		y_root = findRoot(root, y);
		setRoot(root, x_root, y_root);
	}
	cin >> x >> y >> z;
	
	for (int i = 1; i <= N; i++) {
		rootsum[findRoot(root,i)].sum++;
	}
	sum=rootsum[findRoot(root,x)].sum;
	sort(rootsum.begin(), rootsum.end(), stComp);
	int j = 0;
	while (z != 0) {
		if (findRoot(root,x) != rootsum[j].index && findRoot(root,y) != rootsum[j].index) {
			sum += rootsum[j].sum;
			z--;
			j++;
		}
		else {
			j++;
		}
	}
	cout << sum << endl;
	cin >> N;


	return 0;
}