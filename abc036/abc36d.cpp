#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define mod 1000000007;
#define DEB(n) printf("-%d-\n", n);

vector<int> adjlist[100000];
map <int,int> dist;

pll dfs(int from, int now){
  if(adjlist[now].size()==1&&adjlist[now][0]==from){return pll(2,1);}
  ll le=1, ri=1;
  for(int i=0;i<adjlist[now].size();i++){
   int x=adjlist[now][i];
    if(x!=from){
      
      pll tem;
      tem = dfs(now, x);
      le = le*(tem.second) % mod;
      ri = ri*(tem.first) % mod;
    }}
    le= (ri+le)%mod;
    pll ret(le,ri);
    return ret;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i=1;i<n;i++){
    int a, b;
      scanf("%d%d",&a,&b);
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
}
  pll ans = dfs(0, 1);
  printf("%lld\n", ans.first);
  return 0;
}


