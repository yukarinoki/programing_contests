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
#define INF 1e+9
#define MAX_V 300015

// <最短距離, 頂点の番号>
int d[MAX_V];

int main() {
    int n,m; cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<vector<int>> g(3*n);
    rep(i,m){
        int u,v; cin >> u >> v;
        for(int j=0;j<3;j++){
            g[3*(u-1)+j].push_back(3*(v-1) + ((j+1)%3));
        }
    }
    int s,t; cin >> s >> t;
    rep(i,3*n) d[i] = INF;
    s = 3*(s-1);
    t = 3*(t-1);
    d[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        int num = q.top().first;
        int v = q.top().second;
        q.pop();
        for(int i=0; i< g[v].size();i++){
            if(d[g[v][i]] > d[v]+1){
                d[g[v][i]] = d[v]+1;
                q.push({d[v]+1, g[v][i]});
            }
        }
    }
    if(d[t] == INF) cout << -1 << endl;
    else cout << (d[t]/3) << endl;
    return 0;
}