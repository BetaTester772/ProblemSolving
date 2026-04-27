#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, R, Q;

vector<ll> size;
vector<ll> parent;
vector<vector<ll> > children;
vector<vector<int> > tree;

void makeTree(ll cur, ll par) {
    for (auto node: tree[cur]) {
        if (node != par) {
            parent[node] = cur;
            children[cur].push_back(node);
            makeTree(node, cur);
        }
    }
}

//dp
void countSubTreeNodes(ll cur) {
    ::size[cur] = 1; // 자기 자신을 포함
    for (auto child: children[cur]) {
        countSubTreeNodes(child);
        ::size[cur] += ::size[child]; // 자식 노드의 크기를 더함
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R >> Q; //노드 개수, 루트, 쿼리

    ::size.resize(N + 1, 0);
    parent.resize(N + 1, -1);
    children.resize(N + 1);
    tree.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    makeTree(R, -1);

    countSubTreeNodes(R);

    while (Q--) {
        int q;
        cin >> q;
        cout << ::size[q] << '\n';
    }
}
