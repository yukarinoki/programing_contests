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
  int h,w,b=0,ans=0;
  scanf("%d%d", &h,&w);
  char c[h][w+1];
  rep(i,h){
    scanf("%s", c[i]);
  }
  
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#'){
	b++;
      }
    }
  }
  while(b>0){
    int kh[w], kw[h];  memset(kh,0,sizeof(kh));
  memset(kw,0,sizeof(kw));
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#'){
	kh[j]++;
	kw[i]++;
      }
    }
  }
  
  //  rep(i,h){
  //printf("%s", c[i]); printf("\n");
  //}
  //printf("\n");
  
    int map[h][w],cc=1;

    memset(map, 0, sizeof(map));
    rep(i,h){
      rep(j,w){
	if(c[i][j]=='.'){
	  cc=0;
	  
	  if(kh[j]>0){
	    map[i][j]++;
	    rep(l,h){
	      if(c[l][j]=='#'&&kw[l]==1){
		map[i][j]++;
	      }
	    }
	  }
	  if(kw[i]>0){
	    map[i][j]++;
	    rep(l,w){
	      if(c[i][l]=='#'&&kh[l]==1){
		map[i][j]++;
	      }
	    }
	}
	}
      }
    }

    int max=0,mx,my;
    rep(i,h){
      rep(j,w){
	if(map[i][j]>max){
	  max=map[i][j];
	  mx=j;my=i;
	}
      }
    }
    
    if(cc){printf("-1\n"); return 0;}
      //爆破はmx,my
      b=b-kh[mx]-kw[my];
      //  printf("(%d,%d) block:%d\n", (mx+1),(my+1), b);
      
      
      rep(i,h) c[i][mx]='.';
      rep(i,w) c[my][i]='.';
      ans++;
  }
    printf("%d\n", ans);
    return 0;
}
