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
    int N=100;
    cout << N << endl;
    rep(i,N){
        int size = rand() % 5 + 5;
        int dame = rand() % 10 + 5;
        string s;
        rep(j,size){
            if(rand()%10) s+='S';
            else s+= 'C';
        }
        cout << dame << " " << s << endl;
    }
    return 0;
}