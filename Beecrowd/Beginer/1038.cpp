#include<bits/stdc++.h>
using namespace std;

int main()
{
    double arr[5] = {4.00, 4.50, 5.00, 2.00, 1.50};

    double C, Up;
    cin>>C>>Up;
    cout << fixed << setprecision(2);

    if (C==1)
    {
        cout<<"Total: R$ "<<Up*arr[0]<<endl;
    }
    else if (C==2)
    {
        cout<<"Total: R$ "<<Up*arr[1]<<endl;
    }
    else if (C==3)
    {
        cout<<"Total: R$ "<<Up*arr[2]<<endl;
    }
    else if (C==4)
    {
        cout<<"Total: R$ "<<Up*arr[3]<<endl;
    }
    else if (C==5)
    {
        cout<<"Total: R$ "<<Up*arr[4]<<endl;
    }
    return 0;
}