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
  int n, d;
  scanf("%d%d", &n,&d);
  int ans=0,tem=0;
  char c[d][n+1];
  rep(i, d){
    int flag=0;
    scanf("%s", c[i]);
    rep(j,n){
      if(c[i][j]=='0'){flag=1; break;}
    }
    if(flag){tem++; if(tem>ans) ans=tem;}
    else tem=0;
  }
  printf("%d\n", ans);
  return 0;
}
