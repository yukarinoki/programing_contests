#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
/*
https://atcoder.jp/contests/dp/tasks/dp_k

N個の正整数からなる集合Aがあります。 太郎君と次郎君が次のゲームで勝負します。
最初に、K個の石からなる山を用意します。 二人は次の操作を交互に行います。 先手は太郎君です。

Aの元 x をひとつ選び、山からちょうど x個の石を取り去る。"その後、選んだAの元xをAから取り除く"

先に操作を行えなくなった人が負けです。 二人が最適に行動すると仮定したとき、どちらが勝つかを判定してください。

こういう問題だった時の解法
*/


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

bool dp[105][105];

int main(){
    rep(i,105) rep(j,105) dp[i][j] = false;
    int n,k; cin >> n >> k;
    vector<int> a(n), as(n); rep(i,n){ 
        cin >> a[i];
        if(i==0) as[i] = a[i];
        else as[i] = a[i] + as[i-1];
    }
    rep(i,n){
        for(int j = 0; j + i < n; j++){
            int ls = (j == 0 ? 0 : as[j-1]);
            int rs = as[n-1] - as[j+i];
            int sum = k - ls - rs;
            if(a[j] > sum) dp[j][j+i] = false;
            else if(a[j] == sum) dp[j][j+i] = true;
            else dp[j][j+i] = !(dp[j+1][j+i] && dp[j][j+i-1]);

            cout << j << ":" << (j+i) << ":" << ls << ":" << rs << ":"<< sum << ":" << dp[j][j+i] << ":" << as[j] <<  endl;
        }
    }
    if(dp[0][n-1]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}