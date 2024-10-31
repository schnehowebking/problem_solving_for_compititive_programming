#include<bits/stdc++.h>
using namespace std;

int main()
{
    float N;
    cin >> N;

    if (N < 0 || N > 100) {
        cout << "Fora de intervalo" << endl;
    } else if (N <= 25) {
        cout << "Intervalo [0,25]" << endl;
    } else if (N <= 50) {
        cout << "Intervalo (25,50]" << endl;
    } else if (N <= 75) {
        cout << "Intervalo (50,75]" << endl;
    } else {
        cout << "Intervalo (75,100]" << endl;
    }
    return 0;
}