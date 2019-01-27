#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;
bool check(int a,int b,int c){
    // If a==b==c return false, else return true;
    if(a==b&&b==c) return false;
    else return true;
}

int main(){
    int c[3][3],oc[3][3]; //c[i][j] = c_(i,j)
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c[i][j];
            oc[i][j] = c[i][j]; 
        }
    }

    for(int j=0;j<3;j++){
            c[j][0] = oc[j][1]-oc[j][0]; 
    }
    for(int j=0;j<3;j++){
              c[j][1] = oc[j][2]-oc[j][0]; 
    }
    for(int j=0;j<3;j++){
              c[j][2] = oc[j][2]-oc[j][1]; 
    }
    if(check(c[0][0],c[1][0],c[2][0])||check(c[0][1],c[1][1],c[2][1])||check(c[0][2],c[1][2],c[2][2])){
        cout << "No" << endl;
        return 0;
    }
    //b3-b2,b3-b1,b2-b1
    if(c[0][1]-c[0][0]!=c[0][2]) cout << "No" << endl;
    else         cout << "Yes" << endl;
    return 0;
}