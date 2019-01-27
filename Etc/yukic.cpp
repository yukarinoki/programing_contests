#include<cstdio>

int main(){
  int m;
  scanf("%d", &m);
  for(int i=0; i<m;i++){
    int t;
    scanf("%d", &t);
    t++;
    int j=0;
    while((t>>j)!=1){
      j++;
    }
    while(j!=0){
      j--;
      if((t>>j)&1) printf("R");
      else printf("L");
    }
    printf("\n");
  }
  return 0;
}
