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
    vector<ll> a(n), b(n);
    vector<ll> g(n);
    for(int i=0;i<n;i++){cin >> a[i] >> b[i]; g[i] = b[i] - a[i];}
    sort(all(g));
    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans + a[i] * (n-1);
        ans = ans + g[i] * (n-i-1);
    }
    cout << ans << endl;

    return 0;
}