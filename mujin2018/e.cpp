/**
 * このコードはTLEですが、あるtに対して、そこから次のU,R,D,Lが何秒後かをはじめに計算しておいてそれを使えばACです。
 * 
 * 
 * 
 * 
 * 
 * 

*/
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

char ma[1005][1005];
int dp[1005][1005];
int n,m,k;
char s[1000];
bool c[1005][1005];

int main(){
    cin >> n >> m >> k;
    cin >> s;
    rep(i,n) cin >> ma[i];
    int gx,gy,sx,sy;
    rep(i,n) rep(j,m){ dp[i][j] = INF; if(ma[i][j] == 'G'){gx = i;gy = j;}}
    rep(i,n) rep(j,m) if(ma[i][j] == 'S'){sx = i;sy = j; break;}

    priority_queue<pair<int , pair<int,int>>, vector<pair<int , pair<int,int>>>, greater<pair<int , pair<int,int>>>> q;
    q.push(make_pair(0, make_pair(sx,sy)));

    while(!q.empty() && !c[gx][gy]){
        int t = q.top().first, x = q.top().second.first, y = q.top().second.second;
        q.pop();
        if(ma[x][y] == '#') continue;
        //printf("(t, (x,y)) = (%d, (%d, %d))\n", t,x,y);
        c[x][y] = true;
        if(x>0 && !c[x-1][y]) rep(i,k){
            if(s[(t+i) % k] == 'U'){
                if(dp[x-1][y] > t+i+1){
                    dp[x-1][y] = t+i+1;
                    q.push(make_pair(t+i+1, make_pair(x-1,y)));
                }
            }
        }
        if(x<n-1 && !c[x+1][y]) rep(i,k){
            if(s[(t+i) % k] == 'D'){
                if(dp[x+1][y] > t+i+1){
                    dp[x+1][y] = t+i+1;
                    q.push(make_pair(t+i+1, make_pair(x+1,y)));
                }
            }
        }
        if(y>0 && !c[x][y-1]) rep(i,k){
            if(s[(t+i) % k] == 'L'){
                if(dp[x][y-1] > t+i+1){
                    dp[x][y-1] = t+i+1;
                    q.push(make_pair(t+i+1, make_pair(x,y-1)));
                }
            }
        }
        if(y<m-1 && !c[x][y+1]) rep(i,k){
            if(s[(t+i) % k] == 'R'){
                if(dp[x][y+1] > t+i+1){
                    dp[x][y+1] = t+i+1;
                    q.push(make_pair(t+i+1, make_pair(x,y+1)));
                }
            }
        }
    }
    cout << (dp[gx][gy] == INF ? -1 : dp[gx][gy]) << endl;
    return 0;
}