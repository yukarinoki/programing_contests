#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int sqr(int n){
    return n*n;
}
int dist(int x,int y,int xx,int yy){
    return sqr(x-xx) + sqr(y-yy);
}
vector<bool> vc(1000000, false);

int check(vector<pair<int,int>> &v,int da,int db){
    int n = v.size();
    int aa = 0;
    for(int i=0;i<n-1;i++){
        if(vc[i]) continue;
        for(int j=i+1;j<n;j++){
            int dista = dist(v[i].first,v[i].second,v[j].first,v[j].second);
            if(dista == da || dista == db ){
                vc[j] = true;
                /*
                printf("ERROR: (%d,%d) <> (%d,%d)\n", vx[i],vy[i],vx[j],vy[j]); 
                return false;
                */
            }
            printf("%d,%d \n", v[i].first, v[i].second);
            aa++;
        }
    }
    return aa;
}

int main(){
    int n, da,db;
    cin >> n >> da >> db;
    vector<pair<int,int>> v;
    for(int i=0;i<2*n;i++){
        bool flag = true;
        {
        int j=0;
        while(j<v.size()){if(sqr(i-v[j].first)==da || sqr(i-v[j].first)==db /*|| sqr(i-vx[j]) == 1*/){flag = false; break;} j++;}
        }
        if(flag){v.push_back(make_pair(i,0));}
        //if(vx.size()==n) break;
    }
    cout << v.size() << endl;
    int m = v.size();
    for(int i=0;i<m;i++){
        for(int j=1;j<m;j++){
            v.push_back(make_pair((v[i].first),(v[(j+i) % n].first - v[i].first + (2*n)) % (2*n)));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    //for(int i=0;i<vx.size();i++) printf("%d,%d \n", vx[i], vy[i]);
    cout << check(v,da,db) << endl;
    return 0;
}