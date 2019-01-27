#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
        string s; cin >> s;
        bool flag = true;
        for(int j=1;j<s.length();j++){
            if(s[j]!=s[0]){flag = false; break;}
        }
        if(flag){
            cout << -1 << endl;
            continue;
        }

        string ss = s;
        reverse(s.begin(),s.end());
        if(s != ss){
            cout << ss << endl;
            continue;
        }

        for(int j=s.length()-1; j>0; j--){
            if(s[0] != s[j]){
                swap(s[0], s[j]);
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}