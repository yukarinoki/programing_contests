#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define abs(x) (x>0?x:-x)
int main(){
  int t;
  char s[100001];
  scanf("%s", s);
  scanf("%d", &t);
  int x=0,y=0,c=0;
  for(int i=0;s[i]!='\0';i++){
    if(s[i]=='L') x--;
    else if(s[i]=='R')x++;
    else if(s[i]=='U')y++;
    else if(s[i]=='D')y--;
    else if(s[i]=='?')c++;
  }
  int dist = abs(x)+abs(y);
  
  int ans;
  if(t==1) ans=dist+c;
  else if(t==2){
    if(dist>c) ans = dist-c;
    else{c=c-dist; ans = c%2;}
}

  printf("%d\n", ans);
  return 0;
}

