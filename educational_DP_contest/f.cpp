#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

long long int dp[100005];
int main(){
    int n, we; cin >> n >> we;
    vector<long long int> w(n),v(n); rep(i,n) cin >> w[i] >> v[i];
    rep(i,100005) dp[i] = 2000000000000;
    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int j=100005;j>=v[i];j--){
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    long long  ans = 0;
    rep(i, 100005) if(dp[i] <= we) ans = max((long long int)i, ans);
    cout << ans << endl;
    return 0;
}