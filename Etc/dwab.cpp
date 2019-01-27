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
  char t[100001];
  cin >> t;
  int ans=0,tem=0,qc=0;
  int state=0;
  int i=0;
  while(t[i]!='\0'){
    if(state==2){
      if(t[i]=='5'){state=5;tem++;qc=0;}
      else if(t[i]=='?'){state=5;tem++;qc++;}
      else if(t[i]=='2'){if(ans<tem) ans=tem; state=2; tem= (qc%2 ? qc-1 : qc)+1;qc=0;}
      else{if(ans<tem) ans=tem; state=0;tem=0;qc=0;}
    }
    else if(state==5){
      if(t[i]=='2'){state=2;tem++;}
      else if(t[i]=='?'){qc++;state=2;tem++;}
      else if(t[i]=='5'){if(ans<tem) ans=tem; state=5; tem=(qc%2 ? qc : qc-1)+1; qc=0;}
      else{if(ans<tem) ans=tem; state=0; tem=0;}
    }
    else if(state==0){
      if(t[i]=='2'){state=2;tem=1;}
      else if(t[i]=='?'){state=2;tem=1;qc=1;}
    }
    i++;
  }
  if(ans<tem)ans = tem;
  if(ans%2){cout << ans-1 << "\n";}
  else{cout << ans << "\n";}
  return 0;
}
