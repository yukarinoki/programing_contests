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
  ll a,b,k,l;
  ll kk, kkk;
  ll ans=0;
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &k);
  scanf("%lld", &l);
  kk = (k/l+1) * b;
  kkk = (k/l) * b + a * (k%l);
  ans = kk<kkk ? kk : kkk;

  printf("%lld\n", ans);

  return 0;
}
