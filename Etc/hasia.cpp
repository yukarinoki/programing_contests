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
#include <time.h>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define DBG(a) printf("%d\n", a)
#define dbg(a) printf("a \n")
#define INF 100000007


typedef long long ll;


int main(){
  clock_t start = clock();
  int n, m;
  scanf("%d%d", &m,&n);
  vector< pair<int ,int> > a;
  for(int i=0;i<m;i++){
    int tema,temb;
    scanf("%d%d", &tema,&temb);
    a.push_back(make_pair(tema,temb));
  }
  
  sort(a.begin(), a.end());
  int b[200000];
  int nn = 200000;
  rep(i,nn){b[i] = INF;}
  
  b[1]=0;
  queue<int> q;
  
  q.push(1);
  while(!q.empty()){
    int x = q.front();
    if(x==n) break;
    q.pop();
    for(int i=0;(i<m)&&((a[i]).first<x+1);i++){
      int c = x-(a[i]).first+(a[i]).second;
      if(c<nn){
	if(b[c]>b[x]+1){
	  b[c]=b[x]+1;
	  q.push(c);
	}
      }
    }
    clock_t end = clock();
    if(end-start>18000) break;
  }
  if(INF==b[n]) printf("-1\n");
  else printf("%d\n", (b[n]+1));
  
  return 0;
}




