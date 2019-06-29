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
bool check_p(int x){
    int a = 2;
    while(a < 4194305){
        if(a - 1== x) return true;
        a = a * 2;
    }
    return false;
}
int getpos(int x){
    int a = 1048576;
    while((a & x) == a) a = a / 2;
    a *= 2;
    return a - 1;
}

int main(){
    int x; cin >> x;
    vector<int> op;
    int c=0;
    while(1){
        if(check_p(x)){
            cout << c << endl;
            rep(i, op.size()) cout << op[i] << " ";
            if(c!=0) cout << endl;
            return 0;
        }
        if(c==0){
            x ^= 2097151;
            c++;
            op.push_back(21);
        }else{
            int t = getpos(x);
            int pos = 0, ch = 1;
            while(t+1 != ch){ch *= 2; pos++;}
            x ^= t;
            c++;
            op.push_back(pos);
        }
        if(check_p(x)){
            cout << c << endl;
            rep(i, op.size()) cout << op[i] << " ";
            if(c!=0) cout << endl;
            return 0;
        }else{
            x = x + 1;
            c++;
        }
    }
    return 0;
}