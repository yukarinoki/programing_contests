
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
  int n;
  vector<int> vi,vo;//,v; 
  scanf("%d", &n);
  char in[n][6],out[n][6];
  rep(i,n){
    scanf("%s%s", in[i], out[i]);
  }
  rep(i,n){
    int inn,outt;
    inn = 60*atoi(strtok(in[i],":")) + atoi(strtok(NULL, ":"));
    outt = 60*atoi(strtok(out[i], ":"))+atoi(strtok(NULL,":"));
    //   v.push_back(mp(inn,out));
    vi.push_back(inn);
    vo.push_back(outt);
    printf("(%d,%d)\n", inn,outt);
  }
  sort(all(vi));
  sort(all(vo));
  int max=0,now=0,vii=0,voi=0;
  rep(i,2040){    
    while(vi[vii]<=i&&vii<n){
      vii++;
      now++;
    }
    
    while(vo[voi]<=i&&voi<n){
      voi++;
      now--;
    }
    
    if(max<now){max=now;
      printf("(i:%d)\n",i);
	   }
    }
    printf("%d\n", max);
  
  return 0;
}
