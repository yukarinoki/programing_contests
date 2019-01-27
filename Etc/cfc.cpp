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
  char tb[26][26]; //tb[a][b],aをb動かす.
  rep(i,26){tb[i][0]=(i + 'a');}
  rep(i,26){
    rep(j,26){
      if(j!=0){
	if(tb[i][j-1]=='z') tb[i][j]='a';
	else tb[i][j] = (1 + tb[i][j-1]);
      }
    }
  }
  // printf("**\n");
  char c[100001];
  scanf("%s", c);
  ll k;
  scanf("%lld", &k);
  if(c[1]=='\0'){
    ll kk = k % 26;
    c[0] = tb[c[0]-'a'][kk];
    printf("%s\n", c);
  }
  else{
    int i;
    while(k!=0&&c[i+1]!='\0'){
      int tem = 'z'-c[i];
      if(tem<k){ c[i]='a'; k = k - (tem +1);}
      i++;
      // printf("%s\n", c);
      // printf("%d\n", k);
    }
    if(k!=0) c[i] = tb[c[i]-'a'][k%26];
    printf("%s\n", c);
  }
  return 0;
}
