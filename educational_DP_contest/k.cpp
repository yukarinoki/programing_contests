#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MOD 1000000007

bool dp[100005];

int main(){
    rep(i,100005)  dp[i] = false;
    int n,k; cin >> n >> k;
    vector<int> a(n); rep(i,n){ 
        cin >> a[i];
    }
    rep(i,k+1){
            if(i < a[0]) dp[i] = false;
            else {
                bool flag = false;
                rep(j,n) {
                    if(i - a[j] >= 0 && dp[i - a[j]] == false) flag = true;
                }
                dp[i] = flag;
            }
           // cout << i <<  ":"  << ":" << dp[i] <<  endl;
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}