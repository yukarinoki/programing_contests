#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int main(){
  while(1){
  int w, h, p;
  scanf("%d%d%d", &w, &h, &p);
  if(w==0&&h==0&&p==0) break;
  int z[w][h], c[w][h];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      scanf("%d", &z[j][i]);
      c[j][i]=0;
    }
  }
  int x, y, ans=0;
  for(int i=0; i< p;i++){
    scanf("%d%d", &x ,&y);
    queue< pair<int, int> > q;
    if(c[x][y]!=1){
    q.push(make_pair(x,y));
    
    while(!q.empty()){
      int xx = q.front().first, yy = q.front().second;
      if(c[xx-1][yy]!=1&&xx-1!=-1&&z[xx-1][yy]<z[xx][yy]) q.push(make_pair(xx-1, yy));
      if(c[xx][yy+1]!=1&&yy+1!=h&&z[xx][yy+1]<z[xx][yy]) q.push(make_pair(xx, yy+1));
      if(c[xx+1][yy]!=1&&xx+1!=w&&z[xx+1][yy]<z[xx][yy]) q.push(make_pair(xx+1, yy));
      if(c[xx][yy-1]!=1&&yy-1!=-1&&z[xx][yy-1]<z[xx][yy]) q.push(make_pair(xx, yy-1));
      c[xx][yy]=1;
      q.pop();
    }  
    }
  }

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(1==c[j][i]) ans++;
    }
  }
      
      printf("%d\n", ans);
  }
    return 0;
}
