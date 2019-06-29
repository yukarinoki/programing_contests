#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;
char m[1005][1005];
int c[1005][1005];
int main(){
    int h,w; cin >> h >> w;
    rep(i,h) cin >> m[i];
    rep(i,1005) rep(j,1005) c[i][j] = 1000000000;
    queue<pair<int,int>> q;
    rep(i,h) rep(j,w){
        if(m[i][j] == '#'){
            c[i][j] = 0;
            q.push(mp(i,j));
        }
    }
    int ans = 0;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        int p = c[i][j];
        q.pop();
        if(i!=0 && c[i-1][j] > p+1){c[i-1][j] = p+1; q.push(mp(i-1,j));}
        if(i!=h-1 && c[i+1][j] > p+1){c[i+1][j] = p+1; q.push(mp(i+1,j));}
        if(j!=0 && c[i][j-1] > p+1){c[i][j-1] = p+1; q.push(mp(i,j-1));}
        if(i!=0 && c[i][j+1] > p+1){c[i][j+1] = p+1; q.push(mp(i,j+1));}
    }
    //rep(i,h){ rep(j,w) cout << c[i][j] <<" "; cout << endl;}
    rep(i,h) rep(j,w) ans = max(ans, c[i][j]);
    
    cout << ans << endl;
    return 0;
}