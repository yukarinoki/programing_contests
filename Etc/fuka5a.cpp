#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  while(1){
  int n,k;
  scanf("%d%d", &n, &k);
  if(n==0&&k==0) break;
  vector<int> nn;
  for(int i=0;i<n;i++){
    int tem;
    scanf("%d", &tem);
    nn.push_back(tem);
}
  sort(nn.begin(), nn.end());
  int a=0,ans=0;
  while(a<k){
    ans+=nn[a++];
}
  printf("%d\n", ans);
  }  
return 0;
}
