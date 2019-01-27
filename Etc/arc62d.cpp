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
  string s;
  cin >> s;
  int p=0,g=0,win=0,lose=0;
  rep(i,s.length()){
    if(s[i]=='p'){
      if(g>p){
	p++;
      }
      else{
	g++;
	lose++;
      }
    }else if(s[i]=='g'){
      if(g>p){
	p++;
	win++;
      }
      else{
	g++;
      }
    } 
  }
  cout << (win-lose) << "\n";

  return 0;
}
