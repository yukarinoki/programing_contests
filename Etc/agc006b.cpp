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
  int N,x;
  cin >> N >> x;
  if(x==1||x==N*2-1){cout << "No\n"; return 0;}
  else cout << "Yes\n";
  //NとN+1番目にx!=2*N-2  x+1 x x-1 x+2 x==2*n-2 x-1 x x+1 x-2

  if(x!=2*N-2){
    int j=1;
    rep(i,2*N-1){
      if(i==N-2){cout << x+1 << "\n";}
      else if(i==N-1){cout << x << "\n";}
      else if(i==N){cout << x-1 << "\n";}
      else if(i==N+1){cout << x+2 << "\n";}
      else if(j==x-1){j=x+3;cout << j << "\n"; j++;}
      else {cout << j << "\n"; j++;}
    }
  }
  if(x==2*N-2){
    int j=1;
    rep(i,2*N-1){
      if(i==N-2){cout << x-1 << "\n";}
      else if(i==N-1){cout << x << "\n";}
      else if(i==N){cout << x+1 << "\n";}
      else if(i==N+1){cout << x-2 << "\n";}
      else if(j==x-2){j=x+2;cout << j << "\n"; j++;}
      else {cout << j << "\n"; j++;}
    }
  }
  

  return 0;
}
