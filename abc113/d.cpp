#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);i++)
#define MOD 1000000007
  

long long int side_pat(int w){
    if(w<=0) return 1;
    else if(w==1) return 2;
    else if(w==2) return 3;
    else return side_pat(w-1) + side_pat(w-2);
}
long long int pat(int x, int w){
    return (x > 2 ? side_pat(x - 2) : 1) * (x < w - 2 ? side_pat(w - x -1) : 1);
}

long long int dp[101][9];
int main(){
    rep(j,101) rep(i,9) dp[j][i] = 0;
    dp[0][1] = 1;
    int h,w,k; cin >> h >> w >> k;
    rep(i,h+1){
        for(int j=1;j<w+1;j++){
            if(j!=1) dp[i+1][j-1] += (dp[i][j] * pat(j-1, w-1)) % MOD;
            if(j!=w) dp[i+1][j+1] += (dp[i][j] * pat(j, w-1)) % MOD;
            dp[i+1][j] += (dp[i][j] * side_pat(j-2) * side_pat(w-j-1)) % MOD;
            dp[i+1][j-1] %= MOD;
            dp[i+1][j+1] %= MOD;
            dp[i+1][j] %= MOD;
        }
    }
    rep(i,h+1) {
        for(int j=1;j<w+1;j++) cout << dp[i][j] <<" ";
        cout << endl;
    }
    cout << dp[h][k] << endl;
    return 0;
}