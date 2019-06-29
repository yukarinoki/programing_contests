#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

long long int dp[400][400];
int main(){

    int n; cin >> n;
    rep(i,n) cin >> dp[0][i];
    long long int ans = 0;
    for(int i=1;i<n;i++){
        int idx = 0;
        long long int sum = (long long int)dp[i-1][0] + dp[i-1][1]; 
        rep(j,n-i){
            if(dp[i-1][j] + dp[i-1][j+1] < dp[i-1][idx] + dp[i-1][idx+1]){
                sum = (long long int)dp[i-1][j] + dp[i-1][j+1];
                idx = j;
            }
        }
        ans = ans + sum;
        for(int j=0;j < idx; j++) dp[i][j] = dp[i-1][j];
        dp[i][idx] = sum;
        for(int j=idx+2; j <= n-i; j++) dp[i][j-1] = dp[i-1][j];
        //for(int j=0;j<n-i+1;j++) cout << dp[i-1][j] << " ";
        //cout << endl;
    }
    
    cout << ans << endl;
    return 0;
}