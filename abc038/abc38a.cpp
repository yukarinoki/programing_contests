#include <cstdio>

using namespace std;
int main(){
  char s[51];
  scanf("%s", s);
  int i=0, a=0;
  while(s[i]!='\0'){
    if(s[i]=='T') a=1;
    else a=0;
    i++;
}
  if(a==1)printf("YES\n");
  else printf("NO\n");
  return 0;
}
