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
  ll n1,n2,n3,n4,n5,ans=0;
  cin >> n1 >> n2 >> n3 >> n4 >> n5;
  ans += n5;
  ans += n4;
  n1 -= n4*(125-64);
  if(n1<0) n1 = 0;
  ans += n3;
  //cout << n1;
  ll t = n3*7;
  ll quo,sub;
  if(n2<t){
    quo=n2/7;
    sub=n2%7;
    n2 -= t;
    n1 -= (quo*(125-27-56));
    //    cout << n1;
    n1 -= (125-27-8*sub);
    // cout << n1;
    n1 -= (n3-quo-1)*(125-27);
    //cout << n1;
  }
  else {n2 -= n3*7; n1 -= n3*(125-27-56);}
    //cout << ans;
  if(n2<0) n2=0;
  if(n1<0) n1=0;
  ans += (n2/8);
  //cout << n1;
  n1 -= (n2/8)*(125-64);
  if(n1<0)n1=0;
  if(n2%8>0){
    ans++;
    n1 -= ((125-(8*(n2%8))));
    if(n1<0) n1=0;
  }
  //cout << ans;
  ans += n1 / 125;
  if(n1%125 != 0)ans++;
  cout << ans << "\n";

  return 0;
}
