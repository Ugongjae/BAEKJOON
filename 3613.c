#include <iostream>
#include <string>
using namespace std;

string inp;
int type = -1;//0=c, 1=java

int main() {

	cin >> inp;
	for (int i = 0; i < inp.length(); i++) {
		int a = inp[i];
		if (a < 65 || (a < 95 && a>90) || a == 96 || a>122) {
			type = -1;
			break;
		}
		if (a == 95) {
			if ((int)inp[i + 1] == 95) {
				type = -1;
				break;
			}
			if (type == 1) {
				type = -1;
				break;
			}
			else {
				type = 0;
			}
		}
		else if (a >= 65 && a <= 90) {
			if (type == 0) {
				type = -1;
				break;
			}
			else {
				type = 1;
			}
		}
	}
	if ((int)inp[0] < 97)
		type = -1;
	
	if (inp[inp.length()-1] == '_')
		type = -1;
		
	if (type == -1) {
		cout << "Error!" << endl;
		return 0;
	}
	else if (type == 0) {
		for (int i = 0; i < inp.length(); i++) {
			if (inp[i] == '_') {
				inp[i + 1] -= 32;
				inp.erase(i,1);
			}
		}
	}
	else if (type == 1) {
		for (int i = 0; i < inp.length(); i++) {
			int a = inp[i];
			if (a >= 65 && a <= 90) {
				inp.insert(i, "_");
				inp[i + 1] += 32;
			}
		}
	}
	cout << inp << endl;
	return 0;
}