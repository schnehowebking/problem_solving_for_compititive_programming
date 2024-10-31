#include<bits/stdc++.h>
using namespace std;

int main()
{
    double A, B, C;
    cin >> A >> B >> C;

    double dscmnt = B * B - 4 * A * C;

    if (A == 0 || dscmnt < 0) {
        cout << "Impossivel calcular" << endl;
    } else {
        double R1 = (-B + sqrt(dscmnt)) / (2 * A);
        double R2 = (-B - sqrt(dscmnt)) / (2 * A);

        cout << fixed << setprecision(5);
        cout << "R1 = " << R1 << endl;
        cout << "R2 = " << R2 << endl;
    }
    return 0;
}