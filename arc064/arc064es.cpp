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
  vector<pair<int, double> > t;
  rep(i,N){
    double tt = dist(xs,ys,x[i],y[i])-r[i];
    if(tt<0) tt = 0;
    t.push_back(mp(tt,i));
  }
  sort(all(t));
  rep(s,N){
    int i = t[s].second;
    rep(o,N){
      int j = t[o].second;
      if(i!=j){
	double dis = dist(x[i],y[i],x[j],y[j]) -r[i] -r[j];
	if(dis < 0){
	  if(t[s].first < t[o].first) t[s].first=t[o].first;
	  else t[o].first = t[s].first;
	} 
	else if(t[o].first > dis+t[s].first) t[o].first = dis + t[s].first;
      }
    }
    sort(all(t));
    // cout << t[s] << "\n";
  }
  double ans=0;
  int k = t[0].second;
  ans = t[0].first + dist(xt,yt,x[k],y[k]) -r[k];
  if(ans < 0) ans = 0;
  rep(i,N){
    k = t[i].second;
    double tem = t[i].first + dist(xt,yt,x[k],y[k]) -r[k]; 
    if(ans > tem) ans=tem;
  }
  printf("%.12lf\n", ans);
  return 0;
}
