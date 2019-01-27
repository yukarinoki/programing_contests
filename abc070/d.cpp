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

typedef vector<vector<pair<int,int> > > graph;
typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

void dfs(vector<vector<pair<int,int> > > &g, vector<bool> &c,vector<ll> &a,int cur,ll dist){
    a[cur-1]=dist;
    c[cur-1]=true;
    rep(i,g[cur-1].size()){
        if(!c[g[cur-1][i].first-1]){
            dfs(g,c,a,g[cur-1][i].first, dist+g[cur-1][i].second);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> c(n);
    vector<ll>  a(n);
    vector<vector<pair<int,int> > > g(n);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1].push_back(mp(b,c));
        g[b-1].push_back(mp(a,c));
    }
    rep(i,n) {a[i] = -1; c[i] = false;}
    int q,k;
    cin >> q >> k;
    a[k-1] = 0; c[k-1] = true;
    dfs(g,c,a,k,0);
    rep(i,q){
        int x,y;
        cin >> x >> y;
        cout << a[x-1]+a[y-1]<<endl;
    }

    return 0;
}