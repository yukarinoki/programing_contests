#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  map<int, int> map;
  vector<int> a(n), b(n);

  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    b[i]=a[i];
}  
  sort(b.begin(),b.end());

  int tem=b[0];
  map[b[0]]=0;
  int naw=0;

  for(int i=1;i<n;i++){
    if(tem!=b[i]){map[b[i]]=++naw; tem=b[i];}
}
  for(int i;i<n;i++){
    printf("%d\n", map[a[i]]);
}
  return 0;
}
