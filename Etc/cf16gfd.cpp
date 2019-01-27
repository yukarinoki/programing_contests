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
  int aa[6],ba[6];
  rep(i,6){
    cin >> aa[i]; 
  }
  rep(i,6){
    cin >> ba[i];
  }
  double a=0,b=0;
  rep(i,6){
  if(aa[i]==ba[i]){
      a += aa[i]*0.005;
      b += ba[i]*0.005;
  }else if(aa[i] > ba[i]){
      b+= ba[i]*0.01;
  }else if(aa[i]<ba[i]){
    a+= aa[i]*0.01;
    }
  
  cout << a << ":" << b << " ";
  }
  if(a>b) printf("%.12lf\n", 1-a);
  else printf("%.12lf\n", 1-b);
  return 0;
}
