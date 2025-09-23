#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    vector<int> result;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;



    while (T--) {
        int N, a;
        cin >> N;

        result.clear();
        minHeap = priority_queue<int, vector<int>, greater<int> >();
        maxHeap = priority_queue<int>();

        cin >> a;
        maxHeap.push(a);
        result.push_back(a);

        // cin >> a >> b;
        // maxHeap.push(min(a, b));
        // result.push_back(a);
        // // cout << a << '\n';
        //
        // minHeap.push(max(a, b));
        // // cout << maxHeap.top() << '\n';


        for (int i = 1; i < N; ++i) {
            cin >> a;
            if (minHeap.size() && a >= minHeap.top()) {
                minHeap.push(a);
            } else {
                maxHeap.push(a);
            }

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if (i % 2 == 0) {
                result.push_back(maxHeap.top());
                // cout << maxHeap.top() << '\n';
            }
        }
        cout << result.size() << '\n';
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? '\n' : ' ');
            if (i % 10 == 9) {
                cout << '\n';
            }
        }
    }
}
