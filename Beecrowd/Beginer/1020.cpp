#include<bits/stdc++.h>
using namespace std;

int main()
{
    int D;
    cin >> D;

    int Y = D / 365;
    D %= 365;
    int M = D / 30;
    int RD = D % 30;

    cout << Y << " ano(s)" << endl;
    cout << M << " mes(es)" << endl;
    cout << RD << " dia(s)" << endl;
    return 0;
}