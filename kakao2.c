#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(double a[2], double b[2]) {
	if (a[1] == b[1]) {   //이름이 같으면, 나이가 적은순
		return a[0] < b[0];
	}
	else {                  //이름 다르면, 이름 사전순
		return a[1] > b[1];
	}

}


vector<int> solution(int N, vector<int> stages) {
	int maxnum;
	vector<vector<double>> st;
	double tmp=0;
	for (int i = 0; i < N + 1; i++) {
		vector<double> ci;
		ci.assign(1, i);
		ci.push_back(0);
		st.push_back(ci);
	}


	for (int i = 0; i < stages.size(); i++) {
		
			for (int j = 1; j <= stages[i]; j++) {
				st[j][1]++;
			}
		
	}
	tmp = st[N + 1][1];
	for (int i = N; i > 0; i++) {
		tmp += st[i][1];
		st[i][1] = st[i][1] / tmp;
	}
	sort(st.begin(), st.end(),compare);


	vector<int> answer;
	for (int i = 0; i <= N+1; i++) {
		if (st[i][0] == 0 || st[i][0] == N + 1)
			continue;
		answer.push_back(st[i][0]);
	}
	return answer;
}

int  main() {
	vector<int> test;
	vector<int> res;
	int N = 5;

	test.push_back(2);
	test.push_back(1);
	test.push_back(2);
	test.push_back(6);
	test.push_back(2);
	test.push_back(4);
	test.push_back(3);
	test.push_back(3);


	res = solution(N, test);

	return 0;
}