#include<bits/stdc++.h>
using namespace std;

int main()
{
    int pcode, punits;
    double pprice;
    int T= 2;

    double totalPrice = 0;

    while (T--)
    {
        cin>>pcode>>punits>>pprice;
        double total= punits*pprice;

        totalPrice += total;

    }

    cout << fixed << setprecision(2);
    
    cout << "VALOR A PAGAR: R$ " << totalPrice << endl;
    

    
    return 0;
}