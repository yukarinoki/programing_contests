#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mcod(t,a,b) make_pair((t), make_pair((a), (b)))

double powerd (double x, int y)
{
    double temp;
    if (y == 0)
    return 1;
    temp = powerd (x, y / 2);
    if ((y % 2) == 0) {
        return temp * temp;
    } else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

double  dp[505][505];
char    c[505][505];
bool    check[505][505];

typedef pair<int,pair<int,int> > cod;

int main(){
    int n,m;
    cin >> n >> m;
    rep(i,n) cin >> c[i];
    pair<int,int>  sc,hm;
    rep(i,505) rep(j,505){ check[i][j]= i<n && j<m ? true : false; dp[i][j]= 32.0;}
    rep(i,n) rep(j,m){
        if(c[i][j]=='s'){sc.first = i; sc.second = j; check[i][j]=false;}
        else if(c[i][j]=='g'){ hm.first = i; hm.second = j; check[i][j]=false;}
        else if(c[i][j]=='#'){ check[i][j]=false; dp[i][j]=0;}
    }
    priority_queue<pair<double, pair<int, pair<int, int> > > > q;
    
    int x = sc.first, y= sc.second,t=0;
    if(x<n&&check[x+1][y]){ dp[x+1][y] = (double)(c[x+1][y] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x+1][y], mcod(t+1,x+1,y)));}
    if(x>0&&check[x-1][y]){ dp[x-1][y] = (double)(c[x-1][y] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x-1][y], mcod(t+1,x-1,y)));}
    if(y<m&&check[x][y+1]){ dp[x][y+1] = (double)(c[x][y+1] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x][y+1], mcod(t+1,x,y+1)));}
    if(y>0&&check[x][y-1]){ dp[x][y-1] = (double)(c[x][y-1] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x][y-1], mcod(t+1,x,y-1)));}

    while(!q.empty()){
        x = q.top().second.second.first; y = q.top().second.second.second; t = q.top().second.first;
        q.pop();
        check[x][y]=false;
        if(x<n&&check[x+1][y]){ dp[x+1][y] = dp[x][y] < (double)(c[x+1][y] - '0') * powerd(0.99,t+1) ? dp[x][y] : (double)(c[x+1][y] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x+1][y], mcod(t+1,x+1,y)));}
        if(x>0&&check[x-1][y]){ dp[x-1][y] = dp[x][y] < (double)(c[x-1][y] - '0') * powerd(0.99,t+1) ? dp[x][y] : (double)(c[x-1][y] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x-1][y], mcod(t+1,x-1,y)));}
        if(y<m&&check[x][y+1]){ dp[x][y+1] = dp[x][y] < (double)(c[x][y+1] - '0') * powerd(0.99,t+1) ? dp[x][y] : (double)(c[x][y+1] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x][y+1], mcod(t+1,x,y+1)));}
        if(y>0&&check[x][y-1]){ dp[x][y-1] = dp[x][y] < (double)(c[x][y-1] - '0') * powerd(0.99,t+1) ? dp[x][y] : (double)(c[x][y-1] - '0') * powerd(0.99,t+1);  q.push(make_pair(dp[x][y-1], mcod(t+1,x,y-1)));}
    }
    x = hm.first; y = hm.second;
    
    double max = 0;
    max = dp[x+1][y]!=32.0 && max < dp[x+1][y] ? dp[x+1][y] : max;
    max = dp[x-1][y]!=32.0 && max < dp[x-1][y] ? dp[x-1][y] : max;
    max = dp[x][y+1]!=32.0 && max < dp[x][y+1] ? dp[x][y+1] : max;
    max = dp[x][y-1]!=32.0 && max < dp[x][y-1] ? dp[x][y-1] : max;

    if(max==0) printf("-1\n");
    else printf("%.11lf\n", max);

    return 0;
}