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
#define DEBUGM(d,n,m,i,j) printf("DEBUGM :\n"); rep(i,n){ rep(j,m) printf("%d ", d[i][j]); printf("\n");} printf("DEBUGM END LINE\n")

typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

#define MAX_VER 105

int d[MAX_VER][MAX_VER];

void init(){
    rep(i,MAX_VER) rep(j,MAX_VER)d[i][j] = i==j ? 0 : inf;
}
void make(vector<vector<pair<int, int> > > &adl){
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
    int n,m;
    cin >> n >> m;
    vector<tuple< int, int, int> > ed(m);
    vector<vector <pair<int, int> > > adl(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        ed[i] = mt(a,b,c);
        adl[a-1].push_back(mp(b,c));
        adl[b-1].push_back(mp(a,c));
    }
    init();
    make(adl);
    warshall_floyd(n);
    //DEBUGM(d,n,n,i,j);
    int ans=0;
    rep(i,m){
        if(d[get<0>(ed[i])-1][get<1>(ed[i])-1] < get<2>(ed[i])) ans++;
    }
    cout << ans << endl;

    return 0;
}