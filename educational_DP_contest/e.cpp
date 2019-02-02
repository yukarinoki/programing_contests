#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

long long int dp[1005];
int main(){
    int n,we; cin >> n >> we;
    rep(i,100005) dp[i] = 0;
    vector<int> w(n),v(n); rep(i,n) cin >> w[i] >> v[i];
    for(int i=0;i<n;i++){
        for(int j=we;j>=w[i];j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    long long  ans = 0;
    rep(i, we+1) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}