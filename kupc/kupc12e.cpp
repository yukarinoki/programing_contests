#include <random>
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
  int n,ans,po;
  scanf("%d", &n);
  po = 0;
  rep(i,n){
    char tem[n+1];
    scanf("%s", tem);  
    string tt = tem;
    int aa = count(all(tt), '-')+ 3 * count(all(tt), 'o');
    if(po<aa){po=aa; ans = i;}
  }
  random_device rnd; 
  
  ans++;
  rep(i,100){
    rep(j,9){
    printf("%d\n",ans); fflush(stdout);
    }
   
    printf("%d\n", ((rnd() % n) + 1)); fflush(stdout);
    }
  return 0;
}
