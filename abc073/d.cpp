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

#define MAX_VER 205

int d[MAX_VER][MAX_VER];

void init(){
    rep(i,MAX_VER) rep(j,MAX_VER)d[i][j] = i==j ? 0 : inf;
}

void make(graph &adl){
    rep(i, adl.size()) rep(j,adl[i].size()){
        int v = i, u = adl[i][j].first,c = adl[i][j].second;
        u--;
        d[v][u] = c; d[u][v] = c; 
    }
}

void warshall_floyd(int v){
    rep(k,v){ 
        rep(i,v){ 
            rep(j,v){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
   int n,m,R;
   cin >> n >> m >> R;
   vector<int> r(R);
   rep(i,R) cin >> r[i];
   graph g(n);

   rep(i,m){
       int a,b,c;
       cin >> a >> b >> c;
        g[a-1].push_back(mp(b,c));
        g[b-1].push_back(mp(a,c));
   }
   init();
   make(g);
   warshall_floyd(n);
   sort(all(r));
   int ans = inf;
    do{
        int sum=0;
        rep(i,R-1){
            sum += d[r[i]-1][r[i+1]-1];
        }
        ans = min(ans, sum);
    }while(next_permutation(all(r)));
    cout << ans << endl;
    return 0;
}