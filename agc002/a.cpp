#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(a>0) cout << "Positive";
    else if(b>=0) cout << "Zero" ;
    else cout << ((b - a) % 2 ? "Positive" : "Negative");
    cout << endl;
    return 0;
}