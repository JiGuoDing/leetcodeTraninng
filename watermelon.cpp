#include<bits/stdc++.h>
using namespace std;
int main(){
    int w = 0, w0 = 0;
    cin >> w;
    w0 = w - 2;
    if(w0 > 0 && w0 % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}