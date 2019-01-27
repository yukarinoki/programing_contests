#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)

double dp[20001][101];
int main(){
    int n; cin >> n;  
    rep(i,20001) rep(j,101) dp[i][j] = -1.0;
    vector<int> v(n), t(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> v[i];
    int sumt=0;
    rep(i,n) sumt+=t[i];
    int pos = 0;
    int pc = 0;
    dp[0][0] = 0.0;
    int bf = 0;
    for(int i=0; i<sumt;i++){
        pc++;
        if(pc==t[pos]){pos++; pc = 0;bf = v[pos-1];}
        else bf = v[pos];
        //cout << i << "," << pos<<endl;
        rep(j,101){
            if(dp[i][j]!=-1.0){
                if(j>0&&j-1 <= v[pos]) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + (double)(j+j-1) / 2.0);
                if(j+1<=bf &&j+1<=v[pos]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (double)(j+j+1) / 2.0);
                if(j<=v[pos]) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (double)j );
            }
        }
    }
    /*
    rep(j,39){ 
        for(int i=59; i<=61;i++) cout << dp[i][38-j] << " ";
        cout << endl;
    }
    */
    cout << dp[sumt-1][1] + 0.5 << endl; 
    return 0;
}
