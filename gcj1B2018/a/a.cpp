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
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))
#define DEBUGM(d,n,m,i,j) printf("DEBUGM :\n"); rep(i,n){ rep(j,m) if(inf==d[i][j]) printf("inf "); else printf("%d ", d[i][j]); printf("\n");} printf("DEBUGM END LINE\n")

typedef vector<vector<pair<int,int> > > graph;
typedef long long ll;

const ll INF =1LL << 62;
const int inf =1 << 29;

void print_vec(vector<int> &c){
    rep(i,c.size()){
        cout << c[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    rep(k,t){
        int n,l;
        cin >> n >> l;
        vector<int> c(l);
        rep(i,l) cin >> c[i];
        int hc;
        if(100 % n == 0){
            printf("Case #%d: 100\n", k+1);
            continue;
        }else if((n*5) % 1000 == 0){ 
            //ぴったり0.5にできる
            hc = (n*5) / 1000;
            vector<pair<int,int>> vc;
            rep(j,l){
                if(((c[j] % (2*hc) / hc) == 1)) vc.push_back(mp(0,j));
                else vc.push_back(mp(c[j]%hc,j));
            }
            sort(all(vc), greater<pair<int,int> >());
            int sum=0;
            rep(i,l) sum += c[i];
            int sr = n - sum;
            rep(j,l){
                int va = vc[j].first, idx = vc[j].second;
                if(va==0) break;
                if(sr==0) break;
                if(sr < hc - va) {
                    break;
                }else{
                    c[idx] += hc - va;
                    sr -= hc - va;
                }
            }
            if(sr>0){
                int tim = sr / hc;
                rep(i,tim) c.push_back(hc);
                if((sr % hc) != 0){
                    c.push_back(sr%hc);
                }
            }
            int ans=0;
            rep(i,c.size()){
                ans += round( (double)(c[i]*100) / (double)n );
            }
            printf("Case #%d: %d\n", k+1, ans);
        }else{
            //ぴったり0.5にできない
            double in,dec;
            dec = modf(100.0 /(double)n , &in);
            //cout << "dec: " << dec << endl;
            hc = floor(0.5 / dec) + 1;
            vector<pair<int,int>> vc;
            rep(j,l){
            
                dec = modf((double)(c[j]*100) /(double)n, &in);
                if(dec >= 0.5) vc.push_back(mp(inf, j));
                else{
                int tim =  floor((0.5 - dec) / (1.0 /(double) n)) + 1;
                vc.push_back(mp(tim,j));
                }
            }
            sort(all(vc));
            int sum=0;
            rep(i,l) sum += c[i];
            int sr = n - sum;

            rep(j,l){
                int va = vc[j].first, idx = vc[j].second;
                if(va>=hc) break;
                if(sr==0) break;
                if(sr < va) {
                    break;
                }else{
                    c[idx] += va;
                    sr -= va;
                }
            }
            if(sr>0){
                int tim = sr / hc;
                rep(i,tim) c.push_back(hc);
                sr = sr % hc;
                if((sr % hc) != 0){
                    c.push_back(sr%hc);
                }
            }
            int ans=0;
            rep(i,c.size()){
                ans += round( (double)(c[i]*100) / (double)n );
            }
            printf("Case #%d: %d\n", k+1, ans);
           // printf("hc: %d,sr: %d\n", hc,sr);
            //print_vec(c);
        }
            
    }

    return 0;
}