#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int dp[20][1<<20];
int e[20][20];


int main(){
    int n,cost;
    cin >> n;
    bool used[n];
    if(n===2){cout <<"0 0" << endl;}
    rep(i,n) used[i] =true;
    priority_queue<pair<int, pair<int,int> > > q;
    rep(i,n-1){
        rep(j,n-i-1){
            int c;
            cin >> c;
            e[i][j+1]=c;
            e[j+1][i]=c;
        }        
    }
    rep(i,n) dp[i][(1<<n)-1] = 0;
    for(int i=(1<<n)-1;i>=0;i--){
        rep(k,n){
            if(!((1<<k)&i)) continue; 
        rep(j,n){
            if(((~(1<<j))&i)==i) continue;
            dp[j][((~(1<<j))&i)] = dp[j][((~(1<<j))&i)] < dp[]
        }
    }
    }

    cout << n << " ";
    cout << cost << endl;
    return 0;
}