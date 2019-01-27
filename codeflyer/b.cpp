#include <iostream>
#include <string>
using namespace std;

int main(){
    int a,b,n;
    cin >> a >> b >> n;
    string x;
    cin >> x;
    for(int i=0;i<n;i++){
        if(x[i]=='S'){
            if(a>0) a--;
        }
        else if(x[i]=='C'){
            if(b>0) b--;
        }
        else if(x[i]=='E'){
            if(a>0||b>0){
                if(a>=b) a--;
                else if(a<b) b--; 
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}