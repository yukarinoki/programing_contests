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
#define INF 1000000007

typedef long long ll;


int main(){
  ll n;
  cin >> n;
  ll t[n+1], a[n+1];
  ll c[n]; //0で未確定 1でtにより確定,2でaにより確定。
  rep(i,n){
    ll tem;
    cin >> tem;
    t[i] = tem; 
  }
  rep(i,n){
    ll tem;
    cin >> tem;
    a[i] = tem;
  }
  ll ts[n+1];
  ll as[n+1];
  ll be=0;
  if(n==1){
    if(t[0]!=a[0]) {printf("0\n");}
    else {printf("-1\n");}
    return 0;
  }
  rep(i,n){
    if(i==0){c[i]=1; ts[i]=t[i]; be = t[i];}
    else if(be!=t[i]){
      if(be>t[i]){cout << "0\n"; return 0;}
      c[i]=1; ts[i]=t[i]; be = t[i];
    }
    else if(be==t[i]){c[i]=0; ts[i]=t[i];}
  }
  rep(i,n){
    if(i==0){
      if(c[n-1-i]==1&&ts[n-1-i]!=a[n-i-1]){printf("0\n");return 0;}
      c[n-1-i]=2; as[n-1-i]=a[n-1-i]; be = a[n-1-i];}
    else if(be!=a[n-1-i]){
      if(be>t[n-1-i]){cout << "0\n"; return 0;}
      if(c[n-i-1]==1&&ts[n-i-1]!=a[n-i-1]){cout << "0\n"; return 0;}
      c[n-i-i]=2; as[n-1-i]=a[n-1-i]; be = a[n-1-i];
    }
    else if(be==a[n-1-i]){
      if(c[n-1-i]==0){as[n-1-i]=a[n-1-i];}
    }
  }
  ll ans=1;
  /*
  rep(i,n){
    cout << c[i] << " " ;
  }
  cout << "\n";
  rep(i,n){
    cout << ts[i] << " " ;
  }
  cout << "\n";
  rep(i,n){
    cout << as[i] << " " ;
  }
  cout << "\n";
  */
  rep(i,n){
    ll t1 = (ts[i] < as[i] ? ts[i] : as[i]) % INF ;
    ll t2 = t1 - (t1 / 1000000)*1000000;
    t1 = t1 / 1000000;
    if(c[i]==0) ans =  (((t1 * ans) % INF) * 1000000 + (t2 * ans)) % INF;
  }
  cout << ans << "\n";
  return 0;
}
