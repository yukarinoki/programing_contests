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
#define MAX_AREA 1.73205080757
#define PI 3.141592653589

bool equal(double a, double b){
    if(a>b) swap(a,b);
    if(b-a <= 0.000002) return true;
    else return false;
}
void inv_rotate(double &x, double &y,double theta){
    double tx,ty;
    tx = cos(theta)*x + sin(theta) * y;
    ty = -sin(theta)*x + cos(theta) * y;
    x = tx;
    y = ty;
}
int main(){
    int t;
    cin >> t;
    rep(l,t){
        double a;
        cin >> a;
        if(1.0 <= a <= 1.414213){
            double delta = a / sqrt(2.0);
            delta = (PI / 4.0) - asin(delta);
            double ax=0.5,ay=0,bx=0,by=0.5;
            inv_rotate(ax,ay,delta);
            inv_rotate(bx,by,delta);
            printf("Case #%d: \n", l+1);
            printf("%.7lf %.7lf 0\n", ax,ay);
            printf("%.7lf %.7lf 0\n", bx,by);
            printf("0 0 0.5\n");
        }else{
            double a[3],b[3],c[3];
            double ng = PI / 4.0, ok = 0.0;

        }
    }
}



