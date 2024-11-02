#include<bits/stdc++.h>
using namespace std;

int main()
{
    double A, B, C;
    cin >> A >> B >> C;

    double sides[] = {A, B, C};
    sort(sides, sides + 3, greater<double>());
    A = sides[0];
    B = sides[1];
    C = sides[2];

    if (A >= B + C) {
        cout << "NAO FORMA TRIANGULO" << endl;
    } else {
        if (pow(A, 2) == pow(B, 2) + pow(C, 2)) {
            cout << "TRIANGULO RETANGULO" << endl;
        } else if (pow(A, 2) > pow(B, 2) + pow(C, 2)) {
            cout << "TRIANGULO OBTUSANGULO" << endl;
        } else if (pow(A, 2) < pow(B, 2) + pow(C, 2)) {
            cout << "TRIANGULO ACUTANGULO" << endl;
        }

        if (A == B && B == C) {
            cout << "TRIANGULO EQUILATERO" << endl;
        } else if (A == B || B == C || A == C) {
            cout << "TRIANGULO ISOSCELES" << endl;
        }
    }

    return 0;
}