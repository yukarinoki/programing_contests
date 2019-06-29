#include <iostream>
#include <map>
using namespace std;
long n;
long tmp = 1;
map<int, bool> b;
int main()
{
    cin >> n;
    if(n < 10)
    {
        cout << 9;
        return 0;
    }
    while(n > 1)
    {
        ++ n;
        if(b[n]) break;
        b[n] = true;
        while(n % 10 == 0) n /= 10;
        ++ tmp;
    }
    cout << tmp;
    return 0;
}