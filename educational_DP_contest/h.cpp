#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

int dp[1005][1005];
int main(){
    int h, w; cin >> h >> w;
    char map[h][w+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i,h) cin >> map[i];
    rep(i,h) rep(j, w){
        if(map[i][j] != '#'){
            if(j+1 < w && map[i][j+1] != '#') dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
            if(i+1 < h && map[i+1][j] != '#') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}