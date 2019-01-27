#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <climits>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

char c[1010];

char trns(int i){
    if(i==0) return 'A';
    if(i==1) return 'B';
    if(i==2) return 'X';
    if(i==3) return 'Y';
}

int solve(int a,int b,int n){
    int min = 1100;
    rep(i,4){
        rep(j,4){
            int dp[n+5];
            rep(k,n+5) dp[k] = INT_MAX-30000;
            dp[0]=0;
            dp[1]=1;
            rep(k,n){           
                if(k!=n-1&&c[k]==trns(i)&&c[k+1]==trns(j)){
                    if(dp[k]+1 < dp[k+2]) dp[k+2] = dp[k]+1;
                }else if(k!=n-1&&c[k]==trns(a)&&c[k+1]==trns(b)){
                    if(dp[k]+1 < dp[k+2]) dp[k+2] = dp[k]+1;
                }
                else {
                    if(dp[k]+1 < dp[k+1]) dp[k+1] = dp[k]+1;
                }
            }
            if(dp[n] < min) min = dp[n];
        } 
    }
    return min;
}


int main(){
    int n;
    cin >> n;
    scanf("%s", c);
    int min = 1100;
    rep(i,4){
        rep(j,4){
            min = min < solve(i,j,n) ? min : solve(i,j,n); 
            }    
    }
    cout << min << endl;
    return 0;
}