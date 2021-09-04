#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string s;

int pi[1000001];

void getPi() {
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (s[i] != s[j] && j > 0) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    cin >> N >> s;
    getPi();
    cout << N - pi[N - 1] << endl;

    return 0;
}