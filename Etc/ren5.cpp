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
  int n=15;
  double x,pn, pnm1,pnp1;
  cin >> x;
  pn = x;
  pnm1 = 1;
  printf("0: %.12lf\n", pnm1);
  printf("1: %.12lf\n",pn);
  rep(i,n){
    int tn = i+1;
    pnp1 = ((2*tn+1)*x*pn-tn*pnm1)/(tn+1);
    printf("%d: %.12lf\n", tn,pnp1);
    pnm1 = pn;
    pn = pnp1;
  }
  

  return 0;
}
