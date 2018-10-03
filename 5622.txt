#include <iostream>
#include <string>
using namespace std;

int main() {

	string inputnum;
	int sum = 0;

	cin >> inputnum;

	for (int i = 0; i < inputnum.length(); i++) {
		switch (inputnum[i])
		{
		case 'A':
			sum = sum + 3;
			break;
		case 'B':
			sum = sum + 3;
			break;
		case 'C':
			sum = sum + 3;
			break;
		case 'D':
			sum = sum + 4;
			break;
		case 'E':
			sum = sum + 4;
			break;
		case 'F':
			sum = sum + 4;
			break;
		case 'G':
			sum = sum + 5;
			break;
		case 'H':
			sum = sum + 5;
			break;
		case 'I':
			sum = sum + 5;
			break;
		case 'J':
			sum = sum + 6;
			break;
		case 'K':
			sum = sum + 6;
			break;
		case 'L':
			sum = sum + 6;
			break;
		case 'M':
			sum = sum + 7;
			break;
		case 'N':
			sum = sum + 7;
			break;
		case 'O':
			sum = sum + 7;
			break;
		case 'P':
			sum = sum + 8;
			break;
		case 'Q':
			sum = sum + 8;
			break;
		case 'R':
			sum = sum + 8;
			break;
		case 'S':
			sum = sum + 8;
			break;
		case 'T':
			sum = sum + 9;
			break;
		case 'U':
			sum = sum + 9;
			break;
		case 'V':
			sum = sum + 9;
			break;
		case 'W':
			sum = sum + 10;
			break;
		case 'X':
			sum = sum + 10;
			break;
		case 'Y':
			sum = sum + 10;
			break;
		case 'Z':
			sum = sum + 10;
			break;
		default:
			break;
		}
	}

	cout << sum<<endl;

	return 0;
}