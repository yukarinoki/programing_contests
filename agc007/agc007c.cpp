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

double prob(int n){
  double p=1;
  rep(i,n){
    p*= 0.5;
  }
  p/=n;
  return p;
}

int main(){
  int N,d1,x;
  cin >> N >> d1 >> x;
  
  double p=0;
  rep(i,N){
    int tx = d1+2*i*x;
    double tp=0;
    rep(j,N){
      if(j<i){  
	tp+= prob(i-j+1);
      }
      else if(j>=i){
	tp+= prob(j-i+1);
      }
    }
    p+= ((2*tx+x)*tp);
  }

  cout << p << "\n";
  return 0;
}
