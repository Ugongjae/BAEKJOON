#include <iostream>
using namespace std;

int price;
int sum = 0;
int coins[6] = { 500,100,50,10,5,1 };

int main() {

	cin >> price;

	price = 1000 - price;
	for (int i = 0; i < 6; i++) {
		sum += price / coins[i];
		price -= price / coins[i] * coins[i];
	}
	cout << sum << endl;

	return 0;
}