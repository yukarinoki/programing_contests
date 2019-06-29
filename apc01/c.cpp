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
    int n; cin >> n;
    int s =0, e = n;
    int c = 0;
    cout << 0 << 0;
    string str; cin >> s;
    while(c < 20){
        if(str == "Vacant") return 0;
        else if(str == "Male"){
            cout << (n-s+1) / 2 << endl; c++;
            cin >> str;
            if((n-s+1) % 2 ==0){
                if(str == "Male") n = (n-s+1) / 2;
                else if(str == "Female") n =
            }else{
                if(str == "Male")
                else if(str == "Female")
            }
        }
        else if(str == "Female"){
            cout << (n-s+1) / 2 << endl; c++;
            cin >> str;
            if((n-s+1) % 2 ==0){
                if(str == "Male")
                else if(str == "Female")
            }else{
                if(str == "Male")
                else if(str == "Female")
            }
        }

    }
    return 0;
}