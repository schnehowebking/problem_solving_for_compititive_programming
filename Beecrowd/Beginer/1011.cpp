#include<bits/stdc++.h>
using namespace std;
double pi = 3.14159;

int main()
{
    double r;
    cin>>r;
    double volumn = (4*pi*(r*r*r))/3;
    cout << fixed << setprecision(3);
    cout << "VOLUME = " << volumn << endl;
    
    return 0;
}