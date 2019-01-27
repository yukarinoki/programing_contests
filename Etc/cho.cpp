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
  int j=3;
  vector<int> primet;
  primet.push_back(2);
  
  while(primet.size() < 100){
    bool f=true;
    rep(i,primet.size()){
      if(j%primet[i]==0){
	f=false;
	break;
      }
    }
    if(f){primet.push_back(j++);}
  }
  
  rep(i,100){
    cout << (2162160 * primet[i]) << "\n";    

  }
 
  return 0;
}
