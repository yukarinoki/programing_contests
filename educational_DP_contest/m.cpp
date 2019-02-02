#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

int dp[105][100005];

int main(){
    rep(i,100005) rep(j,105)  dp[j][i] = 0;
    int n,k; cin >> n >> k;
    vector<int> a(n); rep(i,n) cin >> a[i];
    rep(j,k+1){
        if(j <= a[0]) dp[0][j] = 1;
        else  dp[0][j] = 0;
    }
    for(int i=1;i<n;i++){
        int sum = 0;
        for(int j=0;j<=a[i];j++){
            sum = (sum + dp[i-1][j]) % MOD;
            dp[i][j] = sum;
        }
        for(int j=a[i]+1; j <= k; j++){
            sum = (sum - dp[i-1][j - a[i] - 1] + MOD) % MOD;
            sum = (sum + dp[i-1][j]) % MOD; 
            dp[i][j] = sum;
        }
        //cout << i <<  ":" << dp[i][0] <<  endl;
    }
    
    
    cout << dp[n-1][k] << endl;
    return 0;
}