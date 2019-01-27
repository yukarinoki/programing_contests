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

bool c[1001][1001];

int rev(int x){
    if(x>=100){
        int a = x/100;
        int b = (x - (a*100)) / 10;
        int c = x - (a*100) - (b*10);
        return 100*c + 10*b + a;
    }else if(x>=10){
        int a = x/10;
        int b = x - (a*10);
        return 10*b + a;
    }else return x;
}
void proc(int &x, int &y){
    if(x < y) x = rev(x);
    else y = rev(y);

    if(x < y) y = y-x;
    else x = x - y;
}
int main(){
    int n,m; cin >> n >> m;
    long long int ans = 0;
    rep(i,n) rep(j,m){
        int x = i+1, y = j+1;
        bool flag = true;
        rep(k,1000){
            proc(x,y);
            if(x==0||y==0){flag=false; break;}
            else if(x < i+1 && y < j+1){flag = c[x][y]; break;}
        }
        if(flag) ans++;
        c[i+1][j+1] = flag;
    }
    cout << ans << endl;
    return 0;
}