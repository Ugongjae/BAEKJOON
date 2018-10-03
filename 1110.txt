#include <iostream>
using namespace std;

int num=-1;
int cycle = 0;
int origin;

int main() {

	cin >> origin;
	num = origin;

	do {
		num = (num / 10 + num % 10)%10  + (num % 10)*10;
		cycle++;
	} while (origin != num);

	cout << cycle << endl;

	return 0;
}