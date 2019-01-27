#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
char m[105][105];

bool check(int h,int w,int l,int u, int r, int d,int x,int y){
    return (r < x)&&(x < w-l)&&(y < h - y)&&(y > d);
}
int main(){
    int h,w;
    cin >> h >> w;

    rep(i,h) cin >> (m[i+1]+1);
    int ex,ey;
    vector<pair<int, int> > rob;
    rep(i,h+1) rep(j,w+1){
        if(m[i][j]=='E'){ex = i; ey = j;}
    }
    m[1][1];
    int l = ex - 0,u = ey - 0, r = w - 1 - ex, d = h - 1 - ey;
    int dp[l+1][u+1][r+1][d+1];
    dp[0][0][0][0]=0;
    rep(i,l+1)rep(j,u+1)rep(k,w+1)rep(m,d+1){
        dp[i+1][j][k][m] = dp[i][j][k][m];
        dp[i][j+1][k][m] = dp[i][j][k][m];
        dp[i][j][k+1][m] = dp[i][j][k][m];
        dp[i][j][k][m+1] = dp[i][j][k][m];
        rep(a,u+d+1){
            if(check(h,w,i,j,k,m,ex-l,ey - u + a) && (m[ex][ey - u + a] =='o')) dp[i+1][j][k][m]++; 
        }
        rep(a,u+d+1){
            if(check(h,w,i,j,k,m,ex-l,ey - u + a) && m[ex-l][ey - u + a]=='o') dp[i+1][j][k][m]++; 
        }
        rep(a,l+r+1){

        }ls
        
        rep(a,l+r+1){

        }

    }
    return 0;
}