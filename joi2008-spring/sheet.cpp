#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sorted;

int topological_sort(vector<int> &in_degree,vector<vector<int> > &dag){
    int n = dag.size();
    if(sorted.size() == n) return 0;
    for(int i=0;i<n;i++){
        if(in_degree[i] == 0){
            sorted.push_back(i);
            in_degree[i]--;
            for(auto x: dag[i]) in_degree[x]--;
        }
    }
    return topological_sort(in_degree, dag);
}

int main(){
    int n,w,h; cin >> n >> w >> h;
    vector<int> in_degree(n);
    for(int i=0;i<n;i++) in_degree[i] = 0;
    vector<vector<int> > dag(n);
    vector<pair<int,int>> ul(n), dr(n);
    for(int i=0;i<n;i++){ ul[i].first = w, ul[i].second = h;}
    for(int i=0;i<n;i++){ dr[i].first = 0, dr[i].second = 0;}
    int map[h][w];
    for(int i=0;i<h;i++) for(int j=0;j<w;j++){
        cin >> map[i][j];
        int idx = map[i][j]-1;
        if(idx>-1){
            ul[idx].first = min(j, ul[idx].first);
            ul[idx].second = min(i, ul[idx].second);
            dr[idx].first = max(j, dr[idx].first);
            dr[idx].second = max(i, dr[idx].second);
        }
    }
    int done[1024];
    for(int i=0;i<n;i++){
        memset(done,0,sizeof(done));
        done[0] = done[i+1] = 1;
        for(int x=ul[i].first; x <= dr[i].first;x++)
            for(int y=ul[i].second; y <= dr[i].second;y++){
                    if(done[map[y][x]]) continue;
                    dag[i].push_back(map[y][x]-1);
                    in_degree[map[y][x]-1]++;
                    done[map[y][x]] = 1;
        }
    }
    /*
    for(int i=0;i<n;i++) {
        cout << i+1 << "(" << ul[i].first<< "," << ul[i].second<< ")" << "(" << dr[i].first<< "," << dr[i].second<< ")"<<endl;
        for(auto x: dag[i]) cout << x+1 << " ";
        cout << endl;
        cout << "in_degree: " << in_degree[i] << endl;
    }
    */

    topological_sort(in_degree, dag);
    for(int i=0;i<n;i++) cout << sorted[i]+1 << " ";
    cout << endl;
    return 0;
}