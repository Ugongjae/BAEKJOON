#include <iostream>
#include <vector>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	
	vector<vector<int>> arr;
	for (int i = 0; i < m; i++) {
		vector<int> ci;
		ci.assign(n, 0);
		arr.push_back(ci);
	}
	arr[0][0] = 1;

	for (int i = 1; i < m; i++) {
		if (city_map[i][0] == 1)
			arr[i][0] = 0;
		else
			arr[i][0] = arr[i - 1][0];
	}
	for (int j = 1; j < n; j++) {
		if (city_map[0][j] == 1)
			arr[0][j] = 0;
		else {
			arr[0][j] = arr[0][j - 1];
		}
	}
	for (int i = 1; i < m; i++) {
		for(int j=1;j<n;j++){
			if (i == 1 && j == 1) {
				if (city_map[i][j] == 1) {
					arr[i][j] = 0;
				}
				if (city_map[i][0] == 0)
					arr[i][j] += arr[i][0];
				if (city_map[0][j] == 0)
					arr[i][j] += arr[0][j];
			}
			else if (j == 1) {
				if (city_map[i][j] == 1) {
					arr[i][j] = 0;
				}
				else {
					if (city_map[i][0] == 0)
						arr[i][j] += arr[i][0];
					if (city_map[i - 1][j] == 2)
						arr[i][j]+=arr[i-2][j];
					else
						arr[i][j] += arr[i - 1][j];
				}
			}
			else if (i == 1) {
				if (city_map[i][j] == 1) {
					arr[i][j] = 0;
				}
				else {
					if (city_map[0][j] == 0)
						arr[i][j] += arr[0][j];
					if (city_map[i][j-1] == 2)
						arr[i][j]+=arr[i][j-2];
					else
						arr[i][j] += arr[i][j-1];
				}
			}
			else {
				if (city_map[i][j] == 1) {
					arr[i][j] = 0;
				}
				else {
					if (city_map[i - 1][j] == 2)
						arr[i][j] += arr[i - 2][j];
					else
						arr[i][j] += arr[i - 1][j];
					if (city_map[i][j - 1] == 2)
						arr[i][j] += arr[i][j - 2];
					else
						arr[i][j] += arr[i][j-1];
				}
			}
		}
	}

	answer = arr[m-1][n-1] % MOD;
	return answer;
}

int main() {

	int m, n;
	cin >> m>>n;

	vector<vector<int>> city_map;
	for (int i = 0; i < m; i++) {
		vector<int> ci;
		ci.assign(n,0);
		city_map.push_back(ci);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin>>city_map[i][j];
		}
	}

	cout << solution(m, n, city_map)<<endl;
	cin >> m;

	return 0;
}