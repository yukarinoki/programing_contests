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
    int k,q; cin >> k >> q;
    vector<int> d(k),dd(k);
    rep(i,k) cin >> d[i];
    for(int qw = 0; qw < q;qw++){
        int n,x,m; cin >> n >> x >> m;
        vector<int> v(n);
        rep(i,k) dd[i] = d[i] % m;
        v[0]=x%m;
        for(int i=1;i<n;i++) v[i] = (v[i-1] + dd[(i-1+k)%k])%m;
        int c = 0;
        for(int i=0;i<n-1;i++) if(v[i+1] > v[i]) c++;
        for(auto x: v) cout << x << " ";
        cout << endl;
        cout << c << endl;
    }
}