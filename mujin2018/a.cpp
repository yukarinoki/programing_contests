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
    string s;
    cin >> s;
    if(s.substr(0,5) == "MUJIN") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}