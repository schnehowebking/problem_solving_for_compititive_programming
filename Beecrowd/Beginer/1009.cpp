#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    double salary;
    double sales;

    getline(cin, name);
    
    cin >> salary >> sales;

    double commission = sales * 0.15;
    double totalSalary = salary + commission;

    cout << fixed << setprecision(2);
    
    cout << "TOTAL = R$ " << totalSalary << endl;

    return 0;
}