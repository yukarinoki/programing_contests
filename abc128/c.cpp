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
    int n,m; cin >> n >>m;
    vector<vector<int>> v(m);
    vector<int> p(m);
    rep(i,m){
        int k; cin >> k;
        rep(j,k){ 
            int t; cin >> t;
            v[i].push_back(t);
        }
    }
    rep(i,m) cin >> p[i];
    int ans = 0;
    rep(i, 1<<n){
        bool flag = true;
        rep(j,m){
            int t=0;
            for(auto x: v[j]) if( ((1<<(x-1))&i) == (1<<(x-1))) t++;
            flag = flag && (p[j] == (t%2));
        }
        if(flag) ans++;
    } 
    cout << ans << endl;
    return 0;
}