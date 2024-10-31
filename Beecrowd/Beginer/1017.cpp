#include<bits/stdc++.h>
using namespace std;

int main()
{
    int time, speed; 
    cin >> time >> speed;
    
    double distance = time * speed;
    
    double liters_needed = distance / 12.0;
    
    cout << fixed << setprecision(3) << liters_needed << endl;
    return 0;

}