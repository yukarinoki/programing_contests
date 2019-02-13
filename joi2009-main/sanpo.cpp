#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int dp[1005][1005];
int main(){
  int h,w,n; cin >> h >> w >> n;
  int sv[h][w]; 
  for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> sv[i][j];
  for(int i=0;i<h;i++) for(int j=0;j<w;j++) dp[i][j] = 0;
 
  for(int i=0;i<h;i++) for(int j=0;j<w;j++){
   	if(i==0&&j==0) dp[i][j] = n-1;
   	else if(i==0){
      dp[i][j] += (dp[i][j-1] / 2)  + (sv[i][j-1]==1 && dp[i][j-1]%2 ? 1 : 0);
    }
    else if(j==0){
      dp[i][j] += (dp[i-1][j] / 2)  + (sv[i-1][j]==0 && dp[i-1][j]%2 ? 1 : 0);
    }
    else{
      dp[i][j] += (dp[i][j-1] / 2)  + (sv[i][j-1]==1 && dp[i][j-1]%2 ? 1 : 0);
      dp[i][j] += (dp[i-1][j] / 2) + (sv[i-1][j]==0 && dp[i-1][j]%2 ? 1 : 0);
    }
  }

  for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(dp[i][j]%2) sv[i][j] = (sv[i][j]==0 ? 1 : 0);
  //for(int i=0;i<h;i++){for(int j=0;j<w;j++) cout << dp[i][j] << " "; cout << endl;}
  int x=1,y=1;
  while(x < w+1 && y < h+1){
  	if(sv[y-1][x-1] == 0) y++;
    else x++;
  }
	
  cout << y << " " << x << endl;
  return 0;
 }