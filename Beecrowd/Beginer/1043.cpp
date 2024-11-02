#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    float A, B, C;
    cin >> A >> B >> C;

    if (A + B > C && A + C > B && B + C > A) {
        float perimeter = A + B + C;
        cout << fixed << setprecision(1);
        cout << "Perimetro = " << perimeter << endl;
    } else {
        float area = ((A + B) * C) / 2;
        cout << fixed << setprecision(1);
        cout << "Area = " << area << endl;
    }

    return 0;
}