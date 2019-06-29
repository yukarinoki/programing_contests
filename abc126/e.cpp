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
vector<vector<pair<int,int>>> g(100005);
vector<int> x(100005),y(100005),z(100005);
vector<pair<int,int>> v(100005);
vector<bool> b(100005);

void dfs(int ver){
    b[ver] = true;
    for(auto x: g[ver]){
        if(b[x.first] == false){
            dfs(x.first);
        }
    }
}

int main(){
    int n,m; cin >> n >> m;

    rep(i,n){
        v[i].first = 0;
        v[i].second = i;
    }

    rep(i,m){ 
        cin >> x[i] >> y[i] >> z[i];
        g[x[i]-1].push_back(mp(y[i]-1,z[i]));
        g[y[i]-1].push_back(mp(x[i]-1,z[i]));
    }
    rep(i,n){
        for(auto x: g[i]) v[i].first = g[i].size();
    }
    sort(v.begin(), v.end());
    
    rep(i,n) b[i] = false;
    //rep(i,n) cout << v[i].first << endl;
    int ans = 0;
    for(int i=0; i<n;i++){
        if(b[i] == false){
            ans++;
            dfs(i);
        }
    }
    
    /*
    for(int i=n-1; i>=0;i--){
        int ver = v[i].second;
        if(b[ver] == false){
            ans++;
            b[ver] = true;
            for(auto x: g[ver]){
                b[x.first] = true;
            }
        }
    }
    */
    cout << ans << endl;
    return 0;
}