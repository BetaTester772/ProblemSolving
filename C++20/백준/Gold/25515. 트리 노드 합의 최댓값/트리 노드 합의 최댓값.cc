#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, R, Q;

vector<ll> dp;
vector<ll> parent;
vector<ll> node_val;
vector<vector<ll> > children;


//dp
void countSubTreeNodes(ll cur) {
    ::dp[cur] = node_val[cur]; // 자기 자신을 포함
    for (auto child: children[cur]) {
        countSubTreeNodes(child);
        ::dp[cur] = max(::dp[cur], ::dp[child] + dp[cur]); // 자식 노드의 dp 값과 자기 자신을 비교하여 최대값 갱신
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N; //노드 개수

    ::dp.resize(N, 0);
    parent.resize(N, -1);
    children.resize(N);
    node_val.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int p, c;
        cin >> p >> c;
        parent[c] = p;
        children[p].push_back(c);
    }

    for (int i = 0; i < N; i++) {
        cin >> node_val[i];
    }

    // 0번 노드가 루트 노드이다.
    countSubTreeNodes(0);
    cout << dp[0];
}
