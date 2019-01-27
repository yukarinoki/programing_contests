#include <cstdio>

int main(){
  int n;
  scanf("%d", &n);
  int a[n][n], b[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[j][i]=0;
      b[j][i]=0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
      scanf("%d", &a[j][i]);
    }
  }
  b[0][0]=a[0][0];
  for(int i=1;i<n;i++){
    for(int j=0;j<i+1;j++){
      int x = a[j][i] + b[j][i-1]; 
      int y = a[j][i] + b[j-1][i-1];
      if(x>y||j-1==-1) b[j][i] = x;
      else  b[j][i] = y;
      //  printf("%d ", b[j][i]);
    }
     // printf("\n");
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(ans<b[i][n-1]) ans = b[i][n-1];
  }
  printf("%d\n", ans);
  return 0;
}
