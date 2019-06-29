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
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;

int main(){
    int r,c; cin >> r >> c;
    int mat[r][c];
    bool same_flag = true;
    int sr,sc;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> mat[i][j];
    
    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            if(mat[i][0]!=mat[i][j]){
                same_flag = false;
                sr = i;
                sc = j;
                break;
            }
        }
        if(same_flag==false) break;
    }
    
    int xo = mat[0][0];
    for(int i=1;i<r;i++) xo = xo^mat[i][0];
    if(xo > 0){
        cout << "TAK" << endl;
        for(int i=0;i<r;i++) cout << 1 << " ";
        cout << endl;
        return 0;
    }
    if(same_flag){
        cout << "NIE" << endl;
        return 0;
    }
     cout << "TAK" << endl;
    xo = 0;
    for(int i=0;i<r;i++){
        if(i==sr){
            xo = xo^mat[i][sc];
            cout << sc+1 << " ";
        }else{
            xo = xo^mat[i][0];
            cout << 1 << " ";
        }
    }
    cout << endl;
    return 0;
}