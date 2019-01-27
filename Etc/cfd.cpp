#include <iostAream>
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

  int r,c;
  int n;
  scanf("%d %d",&r ,&c);
  int t[r][c];
  rep(i,r){
    rep(j,c){
      t[i][j]=-1;
    }
  }

  scanf("%d", &n);
  
  rep(i,n){
    int rr,cc,a;
    scanf("%d", &rr);
    scanf("%d", &cc);
    scanf("%d", &a);
    t[rr-1][cc-1] = a;
  }
  ll mm=0;
  int a=0;
    rep(i,r-1){
      rep(j,c-1){
	if(t[i][j]==-1&&t[i+1][j]!=-1&&t[i][j+1]!=-1&&t[i+1][j+1]!=-1){
	  t[i][j]=t[i+1][j]+t[i][j+1]-t[i+1][j+1];
	  if(t[i][j]<0){printf("No\n");return 0;}
	}
	else if(t[i+1][j]==-1&&t[i][j]!=-1&&t[i][j+1]!=-1&&t[i+1][j+1]!=-1){
	  t[i+1][j]= t[i][j]-t[i][j+1]+t[i+1][j+1];
	  if(t[i+1][j]<0){printf("No\n");return 0;}
	}
	else if(t[i][j+1]==-1&&t[i+1][j]!=-1&&t[i][j]!=-1&&t[i+1][j+1]!=-1){
	  t[i][j+1]=-t[i+1][j]+t[i][j]+t[i+1][j+1];
	  if(t[i][j+1]<0){printf("No\n");return 0;}
	}
	else if(t[i+1][j+1]==-1&&t[i+1][j]!=-1&&t[i][j+1]!=-1&&t[i][j]!=-1){
	  t[i+1][j+1]=t[i+1][j]+t[i][j+1]-t[i][j];
	  if(t[i+1][j+1]<0){printf("No\n");return 0;}
	}
	else if(t[i+1][j+1]!=-1&&t[i+1][j]!=-1&&t[i][j+1]!=-1&&t[i][j]!=-1){
	  if((t[i+1][j+1]+t[i][j])!=(t[i][j+1]+t[i+1][j])){printf("No\n");return 0;}
	}
	if(mm>10000000){printf("Yes\n"); return 0;}
      }
    }

  printf("Yes\n");
50
  return 0;
}
