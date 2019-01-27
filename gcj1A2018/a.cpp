#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

using namespace std;
char ww[105][105];
int w[105][105];



int main(){
    int t;
    cin >> t;
    rep(k,t){
        int r,c,h,v;
        cin >> r >> c >> h >> v;
        rep(i,r){
            cin >> ww[i];
        }
        rep(i,r) rep(j,c){
            if(i==0&&j==0) w[i][j] = (ww[i][j]=='@' ? 1 : 0);
            else if(i==0) w[i][j] = w[i][j-1] + (ww[i][j]=='@' ? 1 : 0);
            else if(j==0) w[i][j] = w[i-1][j] + (ww[i][j]=='@' ? 1 : 0);
            else w[i][j] = w[i-1][j] + w[i][j-1] - w[i-1][j-1] + (ww[i][j]=='@' ? 1 : 0);
        }
        if(v==1&&h==1){
            bool ccc = false;
            /*
            while(1){
                int i,j;
                cin >> i >> j;
                cout << "w[i][j] : "<< w[i][j] << endl;
            }
            */
            rep(i,r)
            {
                if(ccc) break;
                rep(j,c){
                int lu,ld,ru,rd;
                lu = w[i][j];
                ld = w[r-1][j] - lu;
                ru = w[i][c-1] - lu;
                rd = w[r-1][c-1] - ld - ru - lu;
                if(lu == ld && ld == ru && ru == rd){ ccc = true; break;}
                }
            }
            if(!ccc){printf("Case #%d: IMPOSSIBLE\n", k+1); continue;}
            else {printf("Case #%d: POSSIBLE\n", k+1); continue;}
        }

        if(w[r-1][c-1] % ( (h+1) * (v+1) ) != 0){ printf("Case #%d: IMPOSSIBLE\n", t+1); continue;}
        int e = w[r-1][c-1] / ( (h+1) * (v+1) ) ;
        if(e==0){printf("Case #%d: POSSIBLE\n", k+1); continue;}
        bool ng = false;
        int cur = 0;
        bool cut = false;
        rep(i,r){
            if(cut){cur = w[i][c-1] - w[i-1][c-1]; cut = false;}
            else cur += i==0 ? w[i][c-1] : w[i][c-1] - w[i-1][c-1];
            if(h < 0 || cur > (v + 1) * e){ng = true; break;}
            if(cur != 0 && cur % e == 0){
                if(cur == e) {cut = true; h--;}
                else if(cur % (v + 1) == 0 && cur / (v + 1) == e){ h--; cut = true;}
                //else {ng = true; break;}
            }
        }
        if(ng){printf("Case #%d: IMPOSSIBLE\n", k+1); continue;}
        ng = false;
        cur = 0;
        cut = false;
        rep(i,c){
            if(cut){cur = w[r-1][i] - w[r-1][i-1]; cut = false;}
            else cur += i==0 ? w[r-1][i] : w[r-1][i] - w[r-1][i-1];
            if(v < 0 || cur > (h + 1) * e){ng = true; break;}
            if(cur != 0 && cur % e == 0){
                if(cur == e) {cut = true; v--;}
                else if(cur % (h + 1) == 0 && cur / (h + 1) == e){ v--; cut = true;}
                else {ng = true; break;}
            }
        }
        if(ng){printf("Case #%d: IMPOSSIBLE\n", k+1); continue;}
        else {printf("Case #%d: POSSIBLE\n", k+1); continue;}
    }

    return 0;
}