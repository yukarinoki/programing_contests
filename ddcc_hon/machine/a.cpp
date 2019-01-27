#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int main(){
    int XST,YST,XA,YA,XB,YB,XE,YE; cin >> XST >> YST >> XA >> YA >> XB >> YB >> XE >> YE;
    //XP,XSP,XAS,XDS,YP,YSP,YAS,YDS,AS,BS,ES
    //X座標 mm(XP)
    //X速度 mm/sec(XSP),X加速時間 msec(XAS),X減速時間 msec(XDS)
    //Y座標 mm(YP),Y速度 mm/sec(YSP),Y加速時間 msec(YAS),Y減速時間 msec(YDS), 
    //A液供給時間 msec(AS),B液供給時間 msec(BS),排出時間 msec(ES)

    vector<pair<int,int> > point;
    for(int i = -28; i <=48;i+=4){
        for(int j= -28; j<=48;j+=4){
            if(i*i + j*j <= 51*51){
                point.push_back(mp(i,j));
            }
        }
    }
    srand((unsigned)time(NULL));
    if(rand() % 2 == 0){
    for(int i=0;i<1;i++){
    {   
        //100,500,60,100,100,500,90,200
        cout << XA  << "," << 200 <<  "," << 90 << "," << 200 << ",";
        cout <<  YA  << ","   << 200 <<  "," << 90 << "," << 200 << ",";
        cout << 2000 << "," << 0 << "," << 0 << endl;
    }
    {
        cout << XB +4 << "," << 200 <<  "," << 90 << "," << 200 << ",";
        cout <<  YB +4 << "," << 200 <<  "," << 90 << "," << 200 << ",";
        cout << 0 << "," << 2000 << "," << 0 << endl;
    }
    {
        cout << XE << "," << 200 <<  "," << 90 << "," << 200 << ",";
        cout <<  YE << "," << 200 <<  "," << 90 << "," << 200 << ",";
        cout << 0 << "," << 0 << "," << 4000 << endl;
    }
    }
    }
}