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

double dist(int xs,int ys,int xe,int ye){
  return sqrt((double)((xs-xe)*(xs-xe) + (ye-ys)*(ye-ys)));
}

int main(){
  int xs,ys,xt,yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  int x[N],y[N],r[N];
  rep(i,N){
    cin >> x[i];
    cin >> y[i];
    cin >> r[i];
  }
  double t[N];
  rep(i,N){
   t[i] = dist(xs,ys,x[i],y[i])-r[i];
  }
  rep(s,N){
    rep(i,N){
      rep(j,N){
	if(i!=j){
	  double dis = dist(x[i],y[i],x[j],y[j]) -r[i] -r[j];
	  if(dis < 0){
	    if(t[i]<t[j]) t[j]=t[i];
	    else t[i] = t[j];
	  } 
	  else if(t[i] > dis+t[j]) t[i] = dis + t[j];
	}
      }
    }
    // cout << t[s] << "\n";
  }
  double ans=0;
  ans = t[0]+dist(xt,yt,x[0],y[0]) -r[0];
  rep(i,N){
    double tem = t[i] + dist(xt,yt,x[i],y[i]) -r[i]; 
    if(ans > tem) ans=tem;
  }
  printf("%.10lf\n", ans);
  return 0;
}
