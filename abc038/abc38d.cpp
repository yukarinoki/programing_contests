#include <cstdio>
#include <vector>
#include <queue>
#include <pair>
#include <algorithm>

using namespace std;
int main(){
  int n;
  scanf("%d", &n);
  vector<pair <int, int> > hw;
  int table[n][n];
  int h, w;
  for(int i=0;i<n;i++){
    pair <int int> tem;
    scanf("%d%d", &tem.first, &tem.second);
    hw.push_back(tem);
}
  int cc[n];
  priority_queue<pair<int, int>> pp;

  for(int i=0;i<n;i++){
    int c=;
    for(int j=0;j<n;j++){
      if(hw[i].first>hw[j].first&&hw[i].second>hw.second[j]){ table[j][i]=1; c=1;}
      else table[i][j]=0;
    }
    int pair<int,int> tem;
    tem.first=0;tem.second=i;
    if(c=0) pp.push(tem)
  }
  int ans=0;
  while(!pp.empty){
    if(!cc[pp.top.second]){
      for(int i=0;i<n;i++){
	if()
}
}
    else{if(pp.top.first>ans) ans=pp.top.first; pp.pop;}
}
  

  return 0;
}
