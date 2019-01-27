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
#include <cassert>
#include <bitset>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;


int main(){
  ll dp[65536]; //残り(0)がこれのときの答え
  int n, m;
  int po[n+1][n+1];
  memset(po,0,sizeof(po));
  scanf("%d %d", &n,&m);
  rep(i,m){
    int x,y;
    scanf("%d %d",&x,&y);
    //xはｙより早い
    po[x][y]=1;
    }
  dp[0]=1;
  for(int i=1;i<65536;i++){
    bitset<16> bs(i);
    ll na=0;
    if(bs[n]) break;
    rep(j,n){
      if(bs[j+1]){
	int c = 0;
	for(int s=1;s<n+1;s++){
	  if(po[j+1][s]==1&&bs[s]) c=1;
	}
	if(c){na=0; break;}
	bs.reset(j+1);
	na+=dp[bs.to_ulong()];
	bs.reset(j+1);
      }
    }
      dp[i]=na;
      printf("%d:%lld\n",i,na);
    
    
  }
  bitset<16> bss;
  bss = ~bss;
  printf("%lld\n", dp[bss.to_ulong()>>(16-n)]);
  return 0;
}
