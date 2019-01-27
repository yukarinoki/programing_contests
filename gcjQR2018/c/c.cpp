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

int main(){
    int t;
    cin >> t;
    rep(l,t){
        int a;
        cin >> a;
        if(a==20){
            // make 3 * 7 prepared space
            // 10 11 12 ans 10 ~ 16
            a = (a + 2) / 3;
            bool m[15][20];
            rep(i,15) rep(j,20) m[i][j]=false;
            int pd = 0;
            int ii,jj;
            int ny=11;
            cout << "11 11" << endl;
            cin >> ii >> jj;
            while(!(ii==0&&jj==0)){
                m[ii][jj]=true;
                if(m[10][ny-1]&&m[11][ny-1]&&m[12][ny-1]&&ny!=15) ny++;
                cout << "11 " << ny << endl;
                cin >> ii >> jj;
            }
        }
        else if(a==200){
                        // make 3 * 67 prepared space
            // 10 11 12 ans 10 ~ 76
            bool m[15][80];
            rep(i,15) rep(j,80) m[i][j]=false;
            int pd = 0;
            int ii,jj;
            int ny=11;
            cout << "11 11" << endl;
            cin >> ii >> jj;
            while(!(ii==0&&jj==0)){
                m[ii][jj]=true;
                if(m[10][ny-1]&&m[11][ny-1]&&m[12][ny-1]&&ny!=75) ny++;
                cout << "11 " << ny << endl;
                cin >> ii >> jj;
            }
        }
        else{

            // make 3 * 7 prepared space
            // 10 11 12 ans 10 ~ 16
            a = (a + 2) / 3;
            bool m[15][10+a+5];
            rep(i,15) rep(j,15+a) m[i][j]=false;
            int pd = 0;
            int ii,jj;
            int ny=11;
            cout << "11 11" << endl;
            cin >> ii >> jj;
            while(!(ii==0&&jj==0)){
                m[ii][jj]=true;
                if(m[10][ny-1]&&m[11][ny-1]&&m[12][ny-1]&&ny!=8+a) ny++;
                cout << "11 " << ny << endl;
                cin >> ii >> jj;
            }
        }
    }
    return 0;
}