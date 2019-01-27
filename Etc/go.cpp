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

int solve(int ame,int sm){
  int n = ame / 12;
  if(n==0){
    int t = 12 - ame;
    if(sm<=t){ return 0;}
    else{ return 500 + solve(1,sm-t-1);
    }
  }
  else{
    int t = sm - n;
    int aa = (ame % 12) + n;
    return n*500 + solve(aa,t);
  }
}



int main(){
  rep(i,100){
    printf("%d, %d\n",i,i*100+solve(3*i,i));
  }

  return 0;
}
