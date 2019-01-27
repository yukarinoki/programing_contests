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
  ll N,x;
  cin >> N >> x;
  ll a[N],aa[N];
  rep(i,N){
    cin >> a[i];
    aa[i]=a[i];
  }
  ll ans = 0;
  rep(i,N-1){
    if(a[i]+a[i+1]>x){ans+=a[i+1]-x+a[i]; a[i+1]=x-a[i];}
  }
  ll ans1=0;
  for(int i=N-1;i>0;i--){
    if(aa[i]+aa[i-1]>x){ans1+=aa[i-1]-x+aa[i]; aa[i-1]=x-aa[i];}
  }
  if(ans < ans1) cout << ans << "\n";
  else cout << ans1 << "\n";
  return 0;
}
