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
double solve(double d1,double x,int n){
  double d[4];
  d[0]=d1;d[1]=d1+x;d[2]=d[1]+x;d[3]=d[2]+x;
  
  if(n==1) return (d[0]+d[1])/2;
  double nd1 = ((d[2]+d[1]+d[0]+d[2]+((2*n-2)*d[0]))/(2*n));
  double nx = (2*n+4) * x / (2*n);
  double p = (2*d1+(2*n-1)*x) / 2 ;
  // cout << p << " "<< nd1 <<" "<< nx << "\n";
  return p +  solve(nd1,nx,n-1);

}

int main(){
  int N,D1,X;
  cin >> N >> D1 >> X;
  double x = (double) X;
  double d1 = (double) D1;
  
  printf("%26.15lf\n",solve(d1,x,N));
  return 0;
}
