#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;

int dp[1<<20][2][20];
int able[21];
//dp[S][x][n] := S が終わって x のオフィスにいて n回移動しているときの最小の時間
bool isup(int s, int i){
    return (s & (1<<i)) != 0;
}
void fill(int n, vector<vector<int>> &v){
    for(int i=0;i<n;i++){
        able[i] = 0;
        for(int j=0; j < v[i].size(); j++){
            able[i] |= (1 << v[i][j]);
        }
    }
}
void putbit(int s){
    for(int i=31;i>=0;i--){
        putchar( (s&(1<<i)) == 0 ? '0' : '1');
    }
    putchar(' ');
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,m,c,d;
    cin >> n >> m >> c >> d;
    vector<vector<int>> tb(n);
    int  a[2][n];
    for(int i=0;i<n;i++) cin >> a[0][i] >> a[1][i];
    for(int i=0;i<m;i++) {
        int tx,ty; cin >> tx >> ty; 
        tb[ty-1].push_back(tx-1);
    }
    fill(n,tb);
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;

    for(int s = 0; s < (1<<n); s++) 
        for(int x = 0; x<2;x++)
            for(int k=0; k < n ; k++){
                if(dp[s][x][k] == -1) continue;
                for(int i=0;i<n;i++){
                    if(!isup(s,i) && (able[i]&s) == able[i]){
                        int ns = s | (1<<i);
                        if(a[x][i] <= a[x==1 ? 0 : 1][i]){
                            if(dp[ns][x][k] == -1) dp[ns][x][k] = dp[s][x][k] + a[x][i];
                            else dp[ns][x][k] = min(dp[ns][x][k], dp[s][x][k] + a[x][i]);
                        }
                        else{
                        int nx = (x == 1 ? 0 : 1);
                        if(dp[ns][x][k] == -1) dp[ns][x][k] = dp[s][x][k] + a[x][i];
                        else dp[ns][x][k] = min(dp[ns][x][k], dp[s][x][k] + a[x][i]);
                        if(dp[ns][nx][k+1] == -1) dp[ns][nx][k+1] = dp[s][x][k] + a[nx][i] + (c*k+d);
                        else dp[ns][nx][k+1] = min(dp[ns][nx][k+1], dp[s][x][k] + a[nx][i] + (c*k+d));
                        }
                    }
                }
    }
    /*
    for(int i=0;i<(1<<n);i++){
        putbit(i);
        if(able[i]) cout << "true" << endl;
        else cout << "false" << endl;
    }
    */
    int ans = 1<<30;
    for(int i=0;i<2;i++) for(int j=0;j<n;j++){
        if(dp[(1<<n)-1][i][j]!=-1) ans = min(ans, dp[(1<<n)-1][i][j]);
    }
    cout << ans << endl;
    return 0;
}