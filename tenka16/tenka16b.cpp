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
static int p[1001];
static int b[1001];
static int c[1001];

int solve(int oya,int off, int n, int m){
  int min=0;
  int ans=0;
  for(int i=0;i<m;i++){
    if(b[i]==oya) return c[i]-off;
  }
  for(int i=1;i<n;i++){
    if(p[i]==oya){
      ans+= c[i]-off+solve(c[i],c[i],n,m);
    }
  }
  return ans;
}
  int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
      scanf("%d", &p[i]);
    }
     for(int i=0;i<m;i++){
       scanf("%d%d", &b[i],&c[i]);
    }
     int ans=solve(0,0,n,m);
     printf("%d\n", ans);
  return 0;
}
