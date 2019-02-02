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
    int n,k; cin >> n >> k;
    rep(i,100005) dp[i] = 2000000000;
    dp[0] = 0;
    vector<int> h(n); rep(i,n) cin >> h[i];
    for(int i=0;i<n;i++){
        for(int j=1; j<=k; j++){
        if(i+j < n) dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}