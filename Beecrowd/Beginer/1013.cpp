#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;


int main()
{
    int A, B , C;
    cin>> A >> B >>C;
    int max_ab = (A+ B + abs(A- B)) / 2;

    int greatest = (max_ab + C + abs(max_ab - C)) / 2;

    cout << greatest << " eh o maior" << endl;
    


    return 0;
}