//
// Created by 안호성 on 2025. 5. 28..
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> A;
vector<bool> visited;

void dfs() {
    if (A.size() == M) {
        for (auto it = A.begin(); it < A.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i])
            continue;
        A.push_back(i);
        visited[i] = true;
        dfs();
        visited[i] = false;
        A.pop_back();
    }
}

int main() {
    cin >> N >> M;
    visited.resize(N + 1);
    dfs();
}
