#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int dp[100005];
int main(){
    int n; cin >> n;
    rep(i,100005) dp[i] = 2000000000;
    dp[0] = 0;
    vector<int> h(n); rep(i,n) cin >> h[i];
    for(int i=0;i<n;i++){
        if(i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        if(i+1 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]));

    }
    cout << dp[n-1] << endl;
    return 0;
}