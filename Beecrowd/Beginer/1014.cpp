#include<bits/stdc++.h>
using namespace std;

int main()
{
    int X;
    double L;
    cin>> X>>L;
    double consumption = X/L;
    cout << fixed << setprecision(3);
    cout <<consumption<<" km/l"<<endl;

    return 0;
}