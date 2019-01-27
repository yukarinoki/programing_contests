/*
最後に赤にも青にもつながっている　→　最後のターンの人が勝ち
最後に赤にしかつながっていない -> 次郎くんの勝ち
最後に青にしかつながっていない -> 太郎君の勝ち

操作回数が偶数 -> 最初は太郎　最後は次郎
操作回数が奇数 -> 最初は太郎　最後は太郎

操作回数が偶数 青につながっているなら　太郎の勝ち　(つながっている青頂点に動かす -> (次郎動かす 太郎戻す を 以下繰り返し) )
操作回数が偶数 赤にしかつながっていない 次郎の勝ち (つながっている赤頂点に動かす -> 次郎はじめの点に動かす 以下繰り返し) 

操作回数が奇数 開始点が赤 次郎の勝ち (どこかに動かす -> 戻す 以下繰り返し -> 次郎が赤に動かす)
             つながっているすべての頂点が赤の頂点につながっている 　次郎の勝ち
             つながっている頂点のうちにある頂点があり、その頂点は青にしかつながっていない 太郎の勝ち
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    long long int n,m,k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int> > g(n);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    bool only_red[n], only_blue[n];
    for(int i=0; i<n;i++){
        bool red_flag = true,blue_flag= true;
        for(int j=0;j < g[i].size(); j++) if(s[g[i][j]]=='B'){red_flag = false; break;}
        for(int j=0;j < g[i].size(); j++) if(s[g[i][j]]=='R'){blue_flag = false; break;}
        only_red[i] = red_flag;
        only_blue[i] = blue_flag;
    }
    if(k%2 == 1){
        //操作回数が奇数 青につながっているなら　太郎の勝ち　(つながっている青頂点に動かす -> (次郎動かす 太郎戻す を 以下繰り返し) )
        //操作回数が奇数 赤にしかつながっていない 次郎の勝ち (つながっている赤頂点に動かす -> 次郎はじめの点に動かす 以下繰り返し) 
        for(int i=0;i<n;i++){
            if(only_red[i]) cout << "Second" << endl;
            else cout << "First" << endl;
        }
    }else if(k%2 == 0){
        //操作回数が偶数 開始点が赤 次郎の勝ち (どこかに動かす -> 戻す 以下繰り返し -> 次郎が赤に動かす)
        //             つながっているすべての頂点が赤の頂点につながっている 　次郎の勝ち
        //             つながっている頂点のうちにある頂点があり、その頂点は青にしかつながっていない 太郎の勝ち
        for(int i=0;i<n;i++){
            if(s[i] == 'R') cout << "Second" << endl;
            else{
                bool flag = true;
                for(int j=0;j < g[i].size();j++) if(only_blue[g[i][j]]){flag = false; break;}
                if(flag) cout << "Second" << endl;
                else cout << "First" << endl;
            }
        }
    }

    return 0;
}
