#include <iostream>
#include <string>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	string input;
	string target;
	cin >> input;

	for (int i = 0; i < K; i++) {
		cin >> target;
		int j = 0;
			for (int k = 0; k < target.length(); k++) {
				if (input[j] == target[k]) {
					j++;
				}
			}
			if (j == N)
				cout << "true" << endl;
			else
				cout << "false" << endl;
	}


	return 0;
}