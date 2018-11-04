#include <iostream>
#include <string>
using namespace std;

int N;
int M;
string inst;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		cin >> inst;
		for (int j = 0; j < inst.length(); j++) {
			if (inst[j] == 'b')
				M--;
			else
				M++;
			if (M == 0)
				break;
		}
		cout << "Data Set " << i + 1 << ":" << endl;
		cout << M << endl << endl;
	}

	return 0;
}