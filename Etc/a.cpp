#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
string dfs(vector<string> &ss,vector<string> &v,string &s,int i, int l){
  string emp("");
   if(i==l){
     if(!binary_search(v.begin(),v.end(), s)) return s;
     else return emp;
   }else{
     string tem(s);
     rep(j,ss[i].length()){
       tem[i] = ss[i][j];
       if(emp!=dfs(ss,v,tem,i+1,l)) return dfs(ss,v,tem,i+1,l);
     }
   }
  return emp;
}
int main(){
    int t;
    cin >> t;
    rep(k,t){
        int n,l;
        cin >> n >> l;
        vector<string> v(n),ss(l);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<int> kind(l);
        rep(i,l){
            rep(j,n){
                if(string::npos==ss[i].find(v[j][i])) ss[i].push_back(v[j][i]);
            }
            kind[i] = ss[i].length(); 
        }
        int mul=1,ti=0;
        while(ti<l && mul <= n) mul *= kind[ti++];
        if(ti == n && mul <= n){printf("Case #%d: -\n", k+1); continue;}
      sort(v.begin(),v.end());
   		string tem(l,' ');
      string s = dfs(ss,v,tem,0,l);
      string emp("");
      if(s==emp) printf("Case #%d: -\n", k+1);
      else {printf("Case #%d: ", k+1); cout << s << endl;}

    }
    return 0;
}