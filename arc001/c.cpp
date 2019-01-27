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

char b[9][9];
bool c[9][8][8],q[8];

void fill(int i,int j,int n){
    rep(k,8) rep(l,8){
        if(l==j || k==i || k+l == i+j || k-l == i-j) c[n][k][l] = true;
        else c[n][k][l] = c[n-1][k][l];
    }
}
bool dfs(int n){
    int num=0;
    if(n==8) return true;
    rep(i,8) if(q[i]==false){
        num = i; break;
    }
    rep(i,8){
        if(c[n][num][i]==false){
            q[num]=true;
            fill(num,i,n+1);
            if(dfs(n+1)){b[num][i]='Q'; return true;}
            else q[num] = false;
        }
    }
    return false;
}

int main(){

    rep(i,8) cin >> b[i];
    rep(i,8) rep(j,8) c[0][i][j]=false;
    rep(i,8) q[i] = false;
    
    int numb=1;
    rep(i,8) rep(j,8){
        if(b[i][j]=='Q'){
            if(c[numb-1][i][j]==true){
                cout << "No Answer" << endl;
                return 0;
            }
            q[i] = true;
            fill(i,j,numb++);
        }
    }
    if(dfs(3)) rep(i,8) cout << b[i] << endl;
    else cout << "No Answer" << endl;
    return 0;
}