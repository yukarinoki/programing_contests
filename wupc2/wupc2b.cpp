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
  cin >> n;
  char c[n+1];
  cin >> c;
  int i=-1,a=0;
  while(i<n){
    if(i>n-4) break;
    if(c[i+3]=='.'){i+=3;}
    else if(c[i+2]=='.'){i+=2;}
    else if(c[i+1]=='.'){i+=1;}
    else {a++;i+=3;}
  }
  cout << a;
  cout << endl;
  return 0;
}
