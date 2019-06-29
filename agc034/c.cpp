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
    long long int n,x; cin >> n >> x;
    vector<long long> b(n), l(n), u(n);
    rep(i,n) cin >> b[i] >> l[i] >> u[i];
    vector<pair<long long, int>> vp;
    rep(i,n){
        vp.push_back({(b[i]-x)*u[i], i});
    }
    sort(all(vp));
    vector<long long> sl(n+1),su(n+1);
    sl[0] = 0;
    su[0] = 0;
    for(int i=0;i<n;i++){
        sl[i+1] = sl[i] + (l[vp[i].second] * b[vp[i].second]);
        su[i+1] = su[i] + (u[vp[i].second] * b[vp[i].second]);
    }
    
    vector<long long> sumx(n);
    sumx[0] = 0;
    for(int i=0;i<n;i++){
        sumx[i+1] = x * u[vp[i].second] + sumx[i];
    }
    vector<long long int> mv(n);
    long long int temma = 1000000000000;
    int temidx = -1;
    rep(i,n){
        int idx = vp[i].second;
        if(temma > u[idx]){
            temidx = idx;
            temma = u[idx];
        }
        mv[i] = temma;
    }
    long long int ans = 1000000000000;
    for(int i=1;i<=n;i++){
        long long int t = 0;
        long long int bsc = su[i] + sl[n] - sl[i];
        cout << i << " " << bsc << endl;
        bsc -= sumx[i-1];
        t += x * (i-1);
        long long int add = 0;
        cout << "mv[i-1] : " << mv[i-1] << endl;
        if((bsc % mv[i-1]) == 0){
            add = max(bsc / mv[i-1], (long long)0);
        }
        else {
           add = max((long long)0, (bsc / mv[i-1]) + 1);
        }
        if(add <= x){
           cout << add << endl;
            t += add;
            ans = min(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}