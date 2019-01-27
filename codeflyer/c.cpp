#include <iostream>
#include <string>
using namespace std;
int x[100005];
int main(){
    int n,d;
    long long int ans = 0;
    cin >> n >> d;
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n-2;i++){
        if(x[i]+d >= x[n-1]){
            break;
        }
        if(x[i+1]-x[i] > d){
            continue;
        }
        int out,inm;
        int ok = i+1, ng = n-1;
        while(ng-ok > 1){
            int mid = (ok+ng) / 2;
            if(x[mid]-x[i]<=d){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        out = ng;
        if(ng-x[ng-1]>d){
            continue;
        }

        if(x[ng]-x[i+1]<=d){
            inm = i+1;
        }else{
            ok = i+1,ng=ng-1;
            while(ng-ok>1){
                int mid = (ng+ok) / 2;
                while()
            }
        }

    }
    cout << ans << endl;
    return 0;
}