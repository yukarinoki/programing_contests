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

bool check(double r,double x,double y,double xx,double yy){
  return (((x-xx)*(x-xx)+(y-yy)*(y-yy))<r*r+0.1);

  //<rならtrue
}
int main(){
  int n;
  double r;
  scanf("%d%lf",&n,&r);
  vector<double> ax,ay;
  rep(i,n){
    double tx,ty;
    scanf("%lf%lf",&tx,&ty);
    if(ax.empty()){ax.push_back(tx), ay.push_back(ty);}
    else{
      int c=1;
      rep(j, ax.size()){
	if(check(r,tx,ty,ax[j],ay[j])){c=0;break;}
      }
      if(c){ax.push_back(tx), ay.push_back(ty);}
    }
  }
  printf("%lu\n", ax.size());

  return 0;
}
