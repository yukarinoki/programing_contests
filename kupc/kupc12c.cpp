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
  int n, k;
  scanf("%d%d", &n,&k);
  int m[k],bu[k][n];
  rep(i, k){
    scanf("%d", &m[i]);
    rep(j, m[i]){
      scanf("%d", &bu[i][j]);
    }
  }
  int r;
  scanf("%d", &r);
  vector<vector <int, int> > q(n);
  rep(i,r){
    int f,s;
    scanf("%d%d",&f,&s);
    if(f>s) swap(f,s);
    q[f].push_back(s);
    }
  rep(i, k){
    rep(j, m[i]){
      rep(l, q[]
      bu[i][j]
    }
  }
  
  return 0;
}
