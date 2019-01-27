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
#include <list>
using namespace std; 
  

class Graph 
{ 
    int V;    
    list<int> *adj; 
  

    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 

void Graph::connectedComponents() 
{ 
   
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 

            DFSUtil(v, visited); 
  

        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 

    visited[v] = true; 

    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
    return v;
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  

void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  

int main() 
{ 
    int t; cin >> t;
    for(int abatimet=0; abatimet < t; abatimet++){
    int n,m; cin >> n >> m;
    Graph g(n);
    for(int i=0;i<n;i++){
        int u,v; cin >> u >> v;
        g.addEdge(u-1,v-1);
    }

    g.connectedComponents(); 
    }
    return 0; 
} 