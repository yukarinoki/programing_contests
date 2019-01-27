#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)
char ma[2005][2005];
int ta[2005][2005];
int taa[2005][2005];
int main(){
    int n,m; 
    cin >> n >> m;
    rep(i,n) cin >> ma[i];
    rep(i,n) ma[i][m] = '#';
    rep(j,m) ma[n][j] = '#';
    rep(i,n){
        rep(j,m+1){
            if(ma[i][j] == '.'){
                int count=0,now=j;
                while(ma[i][j] == '.'){count++; j++;}
                for(int k=now ;k<j;k++) ta[i][k] = count;
            }
        }
    }
    rep(i,m){
        int now = 0;
        rep(j,n+1){
            if(ma[j][i] == '.'){
                int count=0,now=j;
                while(ma[j][i] == '.') {count++; j++;}
                for(int k=now; k<j;k++) taa[k][i] = count;
            }
        }
    }
    /*
    rep(i,n){
        rep(j,m) cout << ta[i][j] << " ";
        cout << endl;
    }
    rep(i,n){
        rep(j,m) cout << taa[i][j] << " ";
        cout << endl;
    }
    */
    long long int ans = 0;
    rep(i,n) rep(j,m) if(ta[i][j] > 1 && taa[i][j] > 1) ans += (ta[i][j]-1)*(taa[i][j]-1);
    cout << ans << endl;
    return 0;
}