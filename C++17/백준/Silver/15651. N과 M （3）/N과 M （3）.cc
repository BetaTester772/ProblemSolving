//
// Created by 안호성 on 2025. 5. 28..
//
#include <iostream>
#include <vector>

using namespace std;

long unsigned int N, M;

vector<int> A;

void dfs() {
    if (A.size() == M) {
        for (auto it = A.begin(); it < A.end(); it++) {
            //cout << *it << " ";
            printf("%d ", *it);
        }
        //cout << "\n";
        printf("\n");

        return;
    }

    for (int i = 1; i <= N; i++) {
        A.push_back(i);
        dfs();
        A.pop_back();
    }
}

int main() {
    //cin >> N >> M;
    scanf("%u %u", &N, &M);
    A.reserve(M);
    dfs();
}
