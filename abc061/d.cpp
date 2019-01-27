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
#define DEBUGM(d,n,m,i,j) printf("DEBUGM :\n"); rep(i,n){ rep(j,m) if(inf==d[i][j]) printf("inf "); else printf("%d ", d[i][j]); printf("\n");} printf("DEBUGM END LINE\n")

typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

ll s[1005];

ll dfs(int cur,ll sc,vector<vector<pair<int,int> > > &g,vector<bool> &c){
    if(s[cur-1] >= sc){return -INF;} 
    else if(sc >= INF){s[cur-1]=INF;return INF;}
    else if(sc > s[cur-1]&&s[cur-1]!=-INF){return INF;}
    else{
    s[cur-1] = sc;
    rep(i,g[cur-1].size()){
        if(c[g[cur-1][i].first-1]){
            if(INF==dfs(g[cur-1][i].first, sc+g[cur-1][i].second,g,c)) return INF;
        }
    }
    }
    return 0;
}

void check(int cur, vector<vector<int> > &h,vector<bool> &c){
    if(!c[cur-1]){
        c[cur-1] = true;
        rep(i,h[cur-1].size()){
            check(h[cur-1][i],h,c);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int> > > g(n);
    vector<vector<int>> h(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1].push_back(mp(b,c));
        h[b-1].push_back(a);
    }
    vector<bool> c(n, (bool)false);
    check(n,h,c);
    rep(i,n+1) s[i]=-INF;
    if(INF==dfs(1,0,g,c)){printf("inf\n"); return 0;}
    ll ans = s[n-1];
    cout << ans << endl;
    return 0;
}