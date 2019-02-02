#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int dp[100005][3];
int main(){
    int n; cin >> n;
    rep(i,100005) rep(j,3) dp[i][j] = 0;
    vector<int> a(n),b(n),c(n); rep(i,n) cin >> a[i] >> b[i] >> c[i];
    for(int i=0;i<n;i++){
        dp[i+1][0] = max(dp[i][1] + a[i], dp[i][2] + a[i]);
        dp[i+1][1] = max(dp[i][2] + b[i], dp[i][0] + b[i]);
        dp[i+1][2] = max(dp[i][1] + c[i], dp[i][0] + c[i]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}