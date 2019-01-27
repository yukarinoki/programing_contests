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
    int a,b;
    cin >> a >> b;
    char t[100][101];
    rep(i,100){
        rep(j,100+1){
            if(j==100) t[i][j] = '\0';
            else if(j==0) t[i][j] = '#';
            else if(i%2==0){
                if(i==0||i==99) t[i][j] = '#';
                else if(j!=99) t[i][j] = '#';
                else t[i][j] = '.';
            }else t[i][j] = '.';
        }
    }
    int aa=1,bb=1;
    rep(i,40){
        if(aa==b) break;
        FOR(j,1,99){
            if(t[i][j-1]=='#'&&t[i][j]=='#'&&t[i][j+1]=='#'){
                aa++;
                t[i][j] = '.';
            }
             if(aa==b) break;
        }
    }
    FOR(i,50,90){
        if(bb==a) break;
        FOR(j,1,99){
            if(t[i][j-1]=='.'&&t[i][j]=='.'&&t[i][j+1]=='.'){
                bb++;
                t[i][j] = '#';
            }
             if(bb==a) break;
        }
    }
    cout << "100 100" << endl;
    rep(i,100) cout << t[i] << endl;
    return 0;
}