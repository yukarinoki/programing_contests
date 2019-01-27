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

ll bs_root(ll num, ll low, ll up){
  if(low==up) return up;
  else if(up-low==1){
    if((low * low) == num) return low;
    else return 0;
  }
  ll tem = (low + up) /2;
  if((tem * tem) == num) return tem;
  else if((tem * tem) > num) return bs_root(num, low, tem);
  else return bs_root(num, tem, up);
}

int main(){
  ll n;
  scanf("%lld", &n);
  ll ans=0;
  ll tem=1,now=2;
  ll k=0;
  if(2==n){ printf("0\n");return 0;} 
  tem=bs_root(n, 0, 1000000);
  // printf("%lld\n", tem);
  ans++;
  if(!tem){printf("-1\n");return 0;}
    while(tem!=2){
    
    while((tem-k)*(tem-k) >= tem){
      k++;
    }
    // tem-k^2は小さい
    k--;
    ans += n-now;
    ans++;
    n = (tem-k)*(tem-k);
    now = tem;
    tem = tem-k;
    k=0;
   
    //    printf("n:%lldnow:%lldtem:%lld\n", n,now,tem);
    }
  
  printf("%lld\n",ans);
  return 0;
}
