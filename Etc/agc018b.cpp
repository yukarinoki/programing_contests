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

int main(){
    int N,M;
    cin >> N >> M ;
    int c[M],cp[N];
    int ans=N;
    int a[N][M];
    rep(i,N){
        rep(j,M){
            cin >> a[i][j]; 
        }
    }
    rep(i,M) c[i]=1;

    rep(i,M-1){
        rep(i,N) cp[i]=1;    
            int p_num[M];
            rep(k,M) p_num[k]=0;
            rep(j,M){
                rep(k,N){
                    if(cp[k]&&c[a[k][j]-1]){
                    cp[k]=0;
                    p_num[a[k][j]-1]++;
                }
            }
        }
        int maxm=0,max=0;
        rep(j,M){// cout << p_num[j] << ":" <<endl; 
        if(p_num[j] > max){ maxm=j; max = p_num[j];}}
        //cout << "max: "<< max << endl;
        if(ans > max) ans = max;
        c[maxm]=0;
    }
    cout << ans << endl;
    return 0;
}

