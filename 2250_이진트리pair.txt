#include <iostream>
#include <utility>
using namespace std;

pair<int, int> node[10001];
int ma_x[10001];
int mi_n[10001];
int isrootarr[10001];
int depth=1;
int num = 1;
int root;
int N;
int par,in1, in2;
int resd, resw=-1;

void Inorder(int rt,int d) {
	if (node[rt].first != -1)
		Inorder(node[rt].first,d+1);

	if (ma_x[d] < num) 
		ma_x[d] = num;
	if (mi_n[d] > num)
		mi_n[d] = num;
	num++;


	if (node[rt].second != -1)
		Inorder(node[rt].second,d+1);
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		ma_x[i] = -1;
		mi_n[i] = 20000;
	}
	for (int i = 1; i <= N; i++) {
		cin >> par>>in1 >> in2;
		node[par].first = in1;
		node[par].second = in2;
		isrootarr[par]++;
		if (node[par].first != -1)
			isrootarr[in1]++;
		if (node[par].second != -1)
			isrootarr[in2]++;
	}

	for (int i = 1; i <= N; i++) {
		if (isrootarr[i] == 1)
			root = i;
	}
	Inorder(root, depth);
	for (int i = 1; i <= N; i++) {
		if (resw < (ma_x[i] - mi_n[i])) {
			resw = ma_x[i] - mi_n[i];
			resd = i;
		}
	}
	cout << resd <<" "<< ++resw << endl;
	cin >> N;

	return 0;
}