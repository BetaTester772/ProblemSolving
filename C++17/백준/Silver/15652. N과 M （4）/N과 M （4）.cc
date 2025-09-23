//
// Created by 안호성 on 2025. 5. 28..
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> A;

void dfs(int x) {
    if (A.size() == M) {
        for (auto it = A.begin(); it < A.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = x; i <= N; i++) {
        A.push_back(i);
        dfs(i);
        A.pop_back();
    }
}

int main() {
    cin >> N >> M;
    A.reserve(M);
    dfs(1);
}
