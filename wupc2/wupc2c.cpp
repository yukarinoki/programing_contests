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
  int n,m;
  cin >> n;
  cin >> m;
  int t[n][m];
  char c[m+1];
  rep(i,n){
    cin >> c;
    rep(j,m){
      if('X'==c[j])t[i][j]=-1;
      else t[i][j] = (c[j]-'0');
      
    }
   
  }
  int min = n > m ? m: n;
  int d[n][m][n][m];
  rep(i,n){
    rep(j,m){
      rep(k,n){
	rep(l,m){
	  d[i][j][k][l]=0;
	  if(((k-i)*(k-i))==((l-j)*(l-j))){
	  int kx = k-i;
	  int ly = l-j;
	    if(kx>-1&&ly>-1){
	    rep(tem,k-i+1){
	      if(t[i+tem][j+tem]==-1){d[i][j][k][l]=-1; break;}
	      d[i][j][k][l]+=t[i+tem][j+tem];
	    }
	    }else if(kx>-1&&ly<1){
	      rep(tem,k-i+1){
		if(t[i+tem][j-tem]==-1){d[i][j][k][l]=-1; break;}
		d[i][j][k][l]+=t[i+tem][j-tem];
	      }
	    }else if(kx<1&&ly>-1){
	      rep(tem,ly+1){
		if(t[i-tem][j+tem]==-1){d[i][j][k][l]=-1; break;}
		d[i][j][k][l]+=t[i-tem][j+tem];
	      }
	    }else if(kx<1&&ly<1){
	      rep(tem,-kx+1){
		if(t[i-tem][j-tem]==-1){d[i][j][k][l]=-1; break;}
		d[i][j][k][l]+=t[i-tem][j-tem];
	      }
	    }
	  }
	  else {d[i][j][k][l]=-1;
	  
	  }
	  //	   cout << i << "," << j << "," << k <<","<<l<<"\n";
	  //  cout << d[i][j][k][l];
	  // cout << "\n";
	}
	
      }
    }
  }
  int max = 0;
      rep(i,n){
	rep(j,m){
	  rep(k,4){
	    if(k==0){
	      //down right
	      int l = ((m-j-1) > (n-i-1) ? (n-i-1) : (m-j-1));
	      l++;
	      int mm=0;
	      rep(tem,l){
		if(d[i+tem][j][i][j+tem]<0) break;
		else mm+=d[i+tem][j][i][j+tem];

	      }
	      max = mm > max ? mm : max;
	      
	    }
	    else if(k==1){
	      //up right
	      int l = (i > (m-j-1) ? (m-j-1) : i);
	      l++;
	      int mm=0;
	      rep(tem,l){
		if(d[i][j+tem][i-tem][j]==-1) break;
		else mm+=d[i][j+tem][i-tem][j];
		//if(mm==4){
	      	//	cout << i << ","<< j << "," << tem << "," << "\n";
		//	break;
		// }  
	      }
	      max = mm > max ? mm : max;
	    }
	    else if(k==2){
		//down left
	      int l = j > (n-i-1) ? (n-i-1) : j;
		l++;
		int mm=0;
		rep(tem,l){
		  if(d[i][j-tem][i+tem][j]==-1) break;
		  else mm+=d[i][j-tem][i+tem][j];
		}
		max = mm > max ? mm : max;
	      }
	    else if(k==3){
		//up left
	      int l = (i > j ? j : i);
		l++;
		int mm=0;
		rep(tem,l){
		  if(d[i][j-tem][i-tem][j]==-1) break;
		  else mm+=d[i][j-tem][i-tem][j];
		}
		max = (mm > max ? mm : max);
	      }
	   
	  }
	}
      }
      cout << max;
      cout << endl;

  return 0;
}
