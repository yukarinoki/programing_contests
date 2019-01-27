#include <vector>
#include <iostream>
using namespace std;
typedef vector<vector<int> > graph;
int n;
bool c[100005];
char m[100005];
int dfs(int now,bool from,int val,graph &g){
    c[now] = true;

    if(g[now].size()==0){
        if(from) return m[now]=='W' ? 2 : 1;
        else return m[now]=='B' ? 2 : 1; 
    }
    int arr[g[now].size()];
    if(from){
        int ret = 0;
        for(int i=0;i<g[now].size();i++){
            int id = g[now][i];
            dfs(id,from,int );
        } 
        

    }
     


}

int main(){
    cin >> n;
    graph g(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    cin >> m;
    for(int i=0;i<n;i++) c[i] = false;

    return 0;
}