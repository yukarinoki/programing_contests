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
  //グラフが２部か判定する。
  int n,m;
  scanf("%d%d", &n, &m);
  vector< vector <int> > gr(n+1);
  set<int> a, b;
  int ch[n+1];
  memset(ch, 0, sizeof(ch));
  int vf,vt;
  rep(i,m){
    scanf("%d %d", &vf, &vt);
    (gr[vf]).push_back(vt);
    (gr[vt]).push_back(vf);
  }
  queue<int> q;
  int t=0;
  q.push(vf);
  a.insert(vf);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    ch[now]=1;
    
    if(t==0){
      //bに入れる方を選ぶ
    for(int i=0; i<gr[now].size();i++){
      
      if(a.find(gr[now][i])!=a.end()&&ch[gr[now][i]]!=1){
	//あったら
	printf("-1\n");
	return 0;
      }
      if(!ch[gr[now][i]]){
      b.insert(gr[now][i]);
      q.push(gr[now][i]);
      }
      t=1;
    }
    }
    else if(t==1){
      //aに入れるほうを選ぶ.
      for(int i=0; i<gr[now].size();i++){
	if(b.find(gr[now][i])!=b.end()&&ch[gr[now][i]]!=1){
	  //あったら
	  printf("-1\n");
	  return 0;
	}
	if(!ch[gr[now][i]]){
	a.insert(gr[now][i]);
	q.push(gr[now][i]);
	}
	t=0;
      }
      
    }
    
  }
  printf("%lu\n", a.size());
  set<int>::iterator itr;
  for(itr = a.begin(); itr != a.end(); ++itr) {
    printf("%d ", *itr);      // イテレータの指す先のデータを表示
  }
  printf("\n%lu\n", b.size());
  for(itr = b.begin(); itr != b.end(); ++itr) {
    printf("%d ", *itr);      // イテレータの指す先のデータを表示
  }
  printf("\n");
  
  return 0;
}
