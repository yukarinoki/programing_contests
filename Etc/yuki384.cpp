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

bool dfs(ll h,ll w,ll n,ll k);

int main(){
  ll h=0,w=0,n=0,k=0;
  scanf("%lld %lld　%lld %lld", &h,&w,&n,&k);

  
  
  
  if(dfs(h,w,n,k)) printf("YES\n");
  else printf("NO\n");

  return 0;
}

bool dfs(ll h,ll w,ll n,ll k){
  if(h==1){if((w % n)==k||((n==k)&&(w % n)==0)) return true; else return false;}
  else if(w==1){if((h % n)==k||((n==k)&&(h % n)==0)) return true; else return false;}
    if(k==1) return dfs(h-1,w,n,n)&&dfs(h,w-1,n,n);
    else return dfs(h-1,w,n,k-1)&&dfs(h,w-1,n,k-1);

}
