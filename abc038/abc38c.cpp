#include <cstdio>

using namespace std;
int main(){
  int i,n;
  scanf("%d", &n);
  if(n==1){printf("1\n"); return 0;}
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
}
  int l=1,r=0;
long long int ans=0;
  for(r=1;r<n;r++){
    if(a[r-1]<a[r]) l++;
    else{ans+=((l+1)*l)/2; l=1;}
}
  ans+=((l+1)*l)/2;
  printf("%lld\n", ans);
  return 0;
}
