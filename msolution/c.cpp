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

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    vector<int> c(n); rep(i,n) cin >> c[i];
    sort(c.begin(),c.end());
    int ans=0;
    rep(i,n-1) ans += c[i];
    int hasi = -1;
    rep(i,n) if(g[i].size()==1){hasi = i; break;}
    queue<int> q;
    vector<int> ap(n);
    vector<bool> cb(n); rep(i,n) cb[i] = false;
    ap[hasi] = c[n-1];
    cb[hasi] = true;
    q.push(hasi);
    int pos = n-2;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto x: g[t]){
            if(x!=t && cb[x]==false){
                ap[x] = c[pos];
                pos--;
                cb[x] = true;
                q.push(x);
            }
        }
    }
    cout << ans << endl;
    rep(i,n) cout << ap[i] << " ";
    cout << endl;
    return 0;
}