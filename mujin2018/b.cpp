#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main(){
    int num;
    cin >> num;
    string s;
    cin >> s;
    bool flag = false;
    rep(i, s.length()){
        if(num == 0){flag = true;}
        if(s[i] == '+') num++;
        else num--;
        if(num == 0){flag = true; break;}
    }
  
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}