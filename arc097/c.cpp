#include <iostream>
#include <string>
using namespace std;

int main(){
    string s,s2;
    cin >> s;
    int K;
    cin >> K;
    int x[5],y[5];
    for(int i=0;i<5;i++){x[i]=-1; y[i]=-1;}
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=1; j+i<=n;j++){
            bool ch = false;
            for(int k=0;k<5;k++){
                if(x[k]!=-1 && y[k]!=-1 && s.substr(x[k],y[k]) == s.substr(i,j)){ch=true; break;}
                if((x[k]==-1&&y[k]==-1 )|| s.substr(x[k],y[k]) > s.substr(i,j)){
                    ch = true;
                    for(int l=4;l > k;l--){
                        x[l] = x[l-1];
                        y[l] = y[l-1]; 
                    }
                    x[k] = i;
                    y[k] = j;
                    break;
                }
            }
            if(!ch) break;
        }
    }

    cout << s.substr(x[K-1],y[K-1]) << endl;
    return 0;
}