#include <bits/stdc++.h>

using namespace std;
vector<int> inorder;
vector<int> postorder;
vector<int> inorder_index;
int N, root;

void preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end)
        return;

    int root = postorder[post_end];
    int root_index = inorder_index[root];
    int leftSize = root_index - in_start;
    int rightSize = in_end - root_index;

    cout << root << " ";

    preorder(in_start, root_index - 1, post_start, post_start + leftSize - 1);
    preorder(root_index + 1, in_end, post_start + leftSize, post_end - 1);
}

int main() {
    cin >> N;
    inorder_index.resize(N + 1);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        inorder.push_back(num);
        inorder_index[num] = i;
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        postorder.push_back(num);
    }
    preorder(0, N - 1, 0, N - 1);
}
