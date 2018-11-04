#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int N;
int numB, numW;
string load;
int res=0;
int sumB, sumW;
deque<char> dq;

int main() {

	cin >> N >> numB >> numW;
	cin >> load;

	sumW = sumB = 0;
	for (int i = 0; i < N; i++) {
		dq.push_back(load[i]);
		if (load[i] == 'B')
			sumB++;
		else
			sumW++;

		if (sumB <= numB && sumW >= numW)
			res = max(res, (int)dq.size());
		else if (sumB > numB) {
			while (sumB > numB) {
				if (dq.front() == 'W')
					sumW--;
				else
					sumB--;
				dq.pop_front();
			}
		}
	}
	cout << res << endl;

	return 0;
}