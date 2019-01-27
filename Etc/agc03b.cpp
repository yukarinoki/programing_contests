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
  int n;
  scanf("%d", &n);
  int ans=0;
  vector<pair <int, int> > v;
  rep(i,n){
    int t;
    scanf("%d", &t);
    v.push_back(make_pair(t,i));
  }
  sort(v.begin(),v.end());
  rep(i,n){
    if(i%2&&!(v[i].second%2)) ans++;
  }
  printf("%d\n", ans);

  return 0;
}
