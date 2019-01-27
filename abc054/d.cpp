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

int cost[45][405][405];

int main(){
    int n,ma,mb;
    cin >> n >> ma >> mb;
    vector<tuple<int,int,int> > v(n);
    rep(i,n){
        int a,b,c;
        cin >> a >> b >> c;
        v[i] = mt(a,b,c);
    }

    rep(k,45) rep(i,405) rep(j,405) cost[k][i][j] = inf;
    cost[0][0][0] = 0;
    rep(i,n+1){
        if(i!=0){
            int a = get<0>(v[i-1]),b = get<1>(v[i-1]),c = get<2>(v[i-1]);
            rep(k,405) rep(j,405){
                if(cost[i-1][k][j]!=inf){
                    cost[i][k][j] = min(cost[i][k][j], cost[i-1][k][j]);
                    cost[i][k+a][j+b] = min(cost[i-1][k+a][j+b], cost[i-1][k][j] + c);
                }  
            }
        }
    }
    //DEBUGM(cost[n],7,7,i,j);
    int aa = ma, bb = mb, ans=inf;
    while(aa<401&& bb < 401){
        ans = cost[n][aa][bb] < ans ? cost[n][aa][bb] : ans;
        aa += ma; bb += mb; 
    }
    if(536870912==ans) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}