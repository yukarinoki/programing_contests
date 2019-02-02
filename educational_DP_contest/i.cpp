#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

double dp[3005][3005];

int main(){
    int n; cin >> n;
    rep(j,3005) rep(i,1600) dp[j][i] = 0.0;
    vector<double> p(n); rep(i,n) cin >> p[i];
    dp[0][0] = 1.0;
    double ans = 0.0;
    rep(i,n){
        rep(j, i+1){
            dp[i+1][j] += (1 - p[i]) * dp[i][j];
           // if(j+1 > n / 2) ans += p[i] * dp[i][j];
            dp[i+1][j+1] +=  p[i] * dp[i][j];
        }
    }
    rep(i,n+1) if(i > n / 2) ans += dp[n][i];
    printf("%.16lf\n", ans);
    return 0;
}