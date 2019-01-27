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
  ll n,x=1,y=1;
  cin >> n;

  for(int i=0;i<n;i++){
    ll tx,ty;
    cin >> tx >> ty;

    if(y / ty  >= x / tx){
      //xが少ない
      while((y % ty) != 0){
	y++;
      }
      x = (y / ty) * tx;
    }
    else{
      while((x % tx)!=0){
	x++;
      }
      y = (x / tx) * ty;
    }
    
  }
  cout << (x+y) << "\n";
  return 0;
}
