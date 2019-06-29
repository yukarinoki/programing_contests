#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

double dp[305][305][305];
double prob[305][305][305];

int main(){
    int n; cin >> n;
    rep(j,305) rep(i,305) rep(k,305) dp[i][j][k] = 0.0;
    rep(j,305) rep(i,305) rep(k,305) prob[i][j][k] = 0.0;
    int s[]= {0,0,0}; rep(i,n){
        int t; cin >> t;
        s[t-1]++;
    }
    prob[s[2]][s[1]][s[0]] = 1.0;
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