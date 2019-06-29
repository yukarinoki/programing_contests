#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int map[2005][2005];

int main(){
    int h,w; cin >> h >> w;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> map[i][j];
    int left = 0, right = 1000000001;
    while(right - left > 1){
        int mid = (left + right) / 2;
        bool flag = true, flag2 = true;
        // xxxxxxo
        // xxxxooo
        // xxooooo
        // xoooooo
        {
        bool ioiin = false;
        int joimin = map[0][0], joimax = map[0][0];
        int ioimin, ioimax;
        int joiw=w;

        for(int i=0;i<h;i++){
            for(int j=0;j<joiw;j++){
                if(joimin > map[i][j] && mid < joimax - map[i][j]){joiw = j; break;}
                else if(joimax < map[i][j] && mid < map[i][j] - joimin){joiw = j; break;}
                else {
                    joimin = min(joimin, map[i][j]);
                    joimax = max(joimax, map[i][j]);
                }
            }
            for(int j=joiw;j<w;j++){
                if(ioiin == false){ioimin = ioimax = map[i][j]; ioiin = true;}

                if(ioimin > map[i][j] && mid < ioimax - map[i][j]){ printf("j: %d, ioimin: %d, map[i][j]: %d\n", j, ioimax, map[i][j]);i=h; j=w;flag = false; break;}
                else if(ioimax < map[i][j] && mid < map[i][j] - ioimin){i=h; j=w; printf("j: %d, ioimin: %d, map[i][j]: %d\n", j, ioimin, map[i][j]);flag = false;break;}
                else {
                    ioimin = min(ioimin, map[i][j]);
                    ioimax = max(ioimax, map[i][j]);
                }
            }
            printf("mid: %d, i: %d, joiw: %d\n", mid, i, joiw);
        }
        }

        {
        bool ioiin = false;
        int joimin = map[0][0], joimax = map[0][0];
        int ioimin, ioimax;
        int joiw=h;
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) swap(map[i][j], map[i][w-j-1]);
        for(int i=0;i<w;i++){
            for(int j=0;j<joiw;j++){
                if(joimin > map[j][i] && mid < joimax - map[j][i]){joiw = j; break;}
                else if(joimax < map[j][i] && mid < map[j][i] - joimin){joiw = j; break;}
                else {
                    joimin = min(joimin, map[j][i]);
                    joimax = max(joimax, map[j][i]);
                }
            }
            for(int j=joiw;j<h;j++){
                if(ioiin == false){ioimin = ioimax = map[j][i]; ioiin = true;}

                if(ioimin > map[j][i] && mid < ioimax - map[j][i]){ printf("j: %d, ioimin: %d, map[i][j]: %d\n", j, ioimax, map[j][i]);i=w; j=h;flag2 = false; break;}
                else if(ioimax < map[j][i] && mid < map[j][i] - ioimin){i=w; j=h; printf("j: %d, ioimin: %d, map[i][j]: %d\n", j, ioimin, map[j][i]);flag2 = false;break;}
                else {
                    ioimin = min(ioimin, map[j][i]);
                    ioimax = max(ioimax, map[j][i]);
                }
            }
            printf("mid: %d, j: %d, joiw: %d\n", mid, i, joiw);
        }
        }

        if(flag || flag2) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}