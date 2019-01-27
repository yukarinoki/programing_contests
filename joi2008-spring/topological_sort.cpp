#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/******************************
    verified by http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
******************************/

int topological_sort(vector<int> &in_degree,vector<vector<int> > &dag, vector<int> &sorted){
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
}
int main(){
    int n,e; cin >> n >> e;
    vector<int> in_degree(n);
    for(int i=0;i<n;i++) in_degree[i] = 0;
    vector<vector<int> > dag(n);
    vector<int> sorted;
    for(int i=0;i<e;i++){
        int f,t; cin >> f >> t;
        dag[f].push_back(t);
        in_degree[t]++;
    }
 
    for(int i=0;i<n;i++) topological_sort(in_degree, dag, sorted);
    for(int i=0;i<n;i++) cout << sorted[i] << endl;
    return 0;
}