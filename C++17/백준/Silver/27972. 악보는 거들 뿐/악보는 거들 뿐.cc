#include <bits/stdc++.h>

#define PB push_back
using namespace std;

int N;
vector<int> v;

int detect(){
    int upCnt = 0, downCnt = 0, res = 0;
    for(int i = 1; i<N; i++){
        if(v[i] > v[i-1]){
            upCnt++;
            downCnt = 0;
            res = max(res, upCnt);
        } else if(v[i] < v[i-1]){
            downCnt++;
            upCnt = 0;
            res = max(res, downCnt);
        }
    }
    return res+1;
}

int main(){
    int tmp;
    cin >> N;
    if(N==1){
        cout << 1;
        return 0;
    }
    for(int i = 0; i<N; i++){
        cin >> tmp;
        v.PB(tmp);
    }
    cout << detect();
    return 0;
}