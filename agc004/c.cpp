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

int main(){
    int h,w;
    cin >> h >> w;
    char p[h][w+1], r[h][w+1], b[h][w+1];
    rep(i,h) cin >> p[i];
    //make red table
    rep(i,h){
        rep(j,w+1){
            if(j==w) r[i][j] = '\0';
            else if(j==0) r[i][j] = '#';
            else if(i%2==0){
                if(i==0||i==h-1) r[i][j] = '#';
                else if(j!=w-1) r[i][j] = '#';
                else r[i][j] = '.';
            }else r[i][j] = '.';
        }
    }
    //make blue table
    rep(i,h){
        rep(j,w+1){
            if(j==w) b[i][j] = '\0';
            else if(r[i][j]=='#') b[i][j] = '.';
            else b[i][j] = '#';
        }
    }
    rep(i,h){
     rep(j,w){
         if(p[i][j]=='#'){
             if(r[i][j]=='#') b[i][j] = '#';
             else r[i][j] = '#';
         }
     }
    }
    rep(i,h) cout << r[i] << endl;
    cout << endl;
    rep(i,h) cout << b[i] << endl;
    return 0;
}