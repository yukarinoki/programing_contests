#include <cstdio>
#include <iostream>
#include <bitset>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

char map[52][52];
int flag[52][52];

int main(){
    int h,w,sum_w=0;
    cin >> h >> w;
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            if(i==0||j==0||i==h+1||j==w+1){flag[i][j]=1; map[i][j] = '#';}
            else {cin >> map[i][j]; flag[i][j] =0;}
            if(map[i][j]=='.') sum_w++;
        }
    }
    queue< pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(1,1),0));
    int get_flag=0,min_time=0;
    while(!q.empty()){
        int x,y,t;
        t = q.front().second;
        x = q.front().first.first;
        y = q.front().first.second;
        if(x==h&&y==w){
            get_flag=1;
            min_time=t;
            break;
        }
        q.pop();
        if(map[x+1][y]=='.'&&flag[x+1][y]==0){flag[x+1][y]=1; q.push(make_pair(make_pair(x+1,y), t+1));}
        if(map[x-1][y]=='.'&&flag[x-1][y]==0){flag[x-1][y]=1; q.push(make_pair(make_pair(x-1,y), t+1));}
        if(map[x][y+1]=='.'&&flag[x][y+1]==0){flag[x][y+1]=1; q.push(make_pair(make_pair(x,y+1), t+1));}
        if(map[x][y-1]=='.'&&flag[x][y-1]==0){flag[x][y-1]=1; q.push(make_pair(make_pair(x,y-1), t+1));}
    }
    if(get_flag==0) cout << "-1" << endl;
    else cout << (sum_w - min_time - 1) << endl;

    return 0;
}