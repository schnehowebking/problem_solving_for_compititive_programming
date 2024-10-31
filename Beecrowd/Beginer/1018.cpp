#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int bnotes[] = {100, 50, 20, 10, 5, 2, 1};
    cout << N << endl;

    for (int i = 0; i < 7; i++) {
        int count = N / bnotes[i]; 
        cout << count << " nota(s) de R$ " << bnotes[i] << ",00" << endl;
        N %= bnotes[i];   
    }

    return 0;
}