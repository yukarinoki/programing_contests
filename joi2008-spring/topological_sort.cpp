#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/******************************
    verified by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
******************************/
vector<int> sorted;
/* int topological_sort(vector<int> &in_degree,vector<vector<int> > &dag){
    int n = dag.size();
    if(sorted.size() == n) return 0;
    for(int i=0;i<n;i++){
        if(in_degree[i] == 0){
            sorted.push_back(i);
            in_degree[i]--;
            for(auto x: dag[i]) in_degree[x]--;
        }
    }
    return 0;
} */



int topological_sort(vector<vector<int> > &dag){
    int n = dag.size();
    vector<int> in_degree(n);
    for(int i=0;i<n;i++){
        for(auto x: dag[i]){
            in_degree[x]++;
        }
    }
    queue<int> node_set;
    for(int i=0;i<n;i++){
        if(in_degree[i] == 0){
            node_set.push(i);
        }
    }
    while(!node_set.empty()){
        int node = node_set.front();
        node_set.pop();
        sorted.push_back(node);
        for(auto x: dag[node]){
            in_degree[x]--;
            if(in_degree[x] == 0) node_set.push(x);
        }
    }
    return 0;
}
int main(){
    int n,e; cin >> n >> e;
    //vector<int> in_degree(n);
    //for(int i=0;i<n;i++) in_degree[i] = 0;
    vector<vector<int> > dag(n);
    for(int i=0;i<e;i++){
        int f,t; cin >> f >> t;
        dag[f].push_back(t);
        //in_degree[t]++;
    }
 
    topological_sort(dag);
    for(int i=0;i<n;i++) cout << sorted[i] << endl;
    return 0;
}