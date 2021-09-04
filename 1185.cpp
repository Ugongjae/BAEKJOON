#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int dst;
    int src;
    int val;
};

struct compare {
    bool operator()(Edge& a, Edge& b) {
        return a.val > b.val;
    }
};

priority_queue<Edge,vector<Edge>,compare> pq;

int N, P;
int country[10001];
int parent[10001];

void Init() {
    for (int i = 0; i <= 10000; i++) {
        parent[i] = i;
    }
}

int getParent(int idx) {
    while (parent[idx] != idx) {
        idx = parent[idx];
    }
    return idx;
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

void Input() {
    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        cin >> country[i];
    }
    for (int i = 0; i < P; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        pq.push({ tmp1,tmp2,tmp3 * 2 + country[tmp1] + country[tmp2] });
    }
}

int Solve() {
    int res = 0;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        if (getParent(edge.dst) == getParent(edge.src)) {
            continue;
        }

        res += edge.val;
        unionParent(edge.src, edge.dst);
    }
    int t = INT32_MAX;
    for (int i = 1; i <= N; i++) {
        t = min(t, country[i]);
    }

    return res+t;
}

int main() {
    Init();
    Input();
    cout << Solve() << endl;

    return 0;
}