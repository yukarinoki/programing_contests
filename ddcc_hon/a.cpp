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
    int n; cin >> n;
    string s; cin >> s;
    
    int p = 0;
    int max_len = 0, max_pl = 0, max_pr = 0;
    while(p < n){
        if(s[p] =='>'){
            int tem_len=0;
            int tem_p = p;
            while(p < n && s[p] == '>'){tem_len++; p++;}
            if(tem_len > max_len){
                max_len = tem_len;
                max_pl = tem_p;
                max_pr = p;
            }
        }else p++;
    }
    s[max_pr] = '>';
    //cout << s << endl;
    double ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '>'){
            int k = 0;
            while(s[i] == '>'){
                ans += 1.0 /((double) k + 2.0);
                k++;
                i++;
            }
        }
        if(i < n && s[i] == '-'){
            ans += 1.0;
        }
    }
    printf("%.16lf\n", ans);
    return 0;
}