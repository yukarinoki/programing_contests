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

int main(){
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    if(a>b) swap(a,b);
    int dif = b - a;
    int cel = n - 1;
    if(dif > d * cel){
        cout << "NO" << endl;
        return 0;
    }
    cel -= dif / d;
    dif = dif % d;
    if(dif >= c){
        dif = 0;
        cel--;
    }
    if( dif < (cel / 2) * (d - c)){
        cel -= (dif / (d - c)) * 2;
        dif = dif % (d - c);
    }
    if(cel % 2 == 0) cout << "YES" << endl;
    else if(cel % 2 == 1) cout << "NO" << endl;


    return 0;
}