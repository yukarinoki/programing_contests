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
    vector<long long int> x(n), l(n);
    rep(i,n) cin >> x[i] >> l[i];
    vector<pair<long long int, int>> v(n);
    rep(i,n){
        v[i] = mp(x[i]+l[i], i);
    }
    sort(all(v));
    int ans = 0;
    long long int ls = -2000000000;
    rep(i,n){
        int id = v[i].second;
        if(x[id]-l[id] >= ls){
            ans++;
            ls = v[i].first;
        } 
    }
    cout << ans << endl;
    return 0;
}