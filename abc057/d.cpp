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

ll comb(int n, int r){
    ll ans = 1;
    if(n>r){
    rep(i,r){
        ans *= n - i;
        ans /= i + 1;
    }
    }
    return ans;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(all(v),greater<int>());
    int suma = 0;
    rep(i,a) suma += v[i];
    double maxd = ((double)suma) / a;
    int mem = 0,same=0,s=0;
    while(a+same<n && v[a+same-1]==v[a+same]) same++;
    while(a+same-s-2>-1 && v[a+same-s-1]==v[a+same-s-2]) s++;
    s++;
    int t = s-same;
    if(a+same>b) mem = b;
    else mem = a+same;
    ll ans = 0;
    cout << s <<t <<mem - a -same + s + 1<< endl;
    for(int i=t;i<=mem-(a+same-s-1); i++) ans += comb(s,i);
    printf("%.7lf\n", maxd);
    cout << ans << endl;
    return 0;
}