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
  int t1=0,t2=0,t3=0,t4=0;
  cin >> n;
  rep(i,n){
    int tem;
    cin >> tem;
    if(tem==1) t1++;
    else if(tem==2) t2++;
    else if(tem==3) t3++;
    else if(tem==4) t4++;
  }
  int ans=0;
  ans+=t4;
  ans+=t3;
  if(t3>t1) t1=0;
  else t1 -= t3;
  ans += t2/2;
  if(t2%2) t2=1;
  else t2=0;
  if(t2){ans++; if(t1-2>0)t1-=2;else t1=0;}
  ans += (t1 / 4) + (t1 % 4 ? 1 : 0); 
  cout << ans << "\n";
  return 0;
}
