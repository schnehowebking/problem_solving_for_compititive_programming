#include<bits/stdc++.h>
using namespace std;
double pi = 3.14159;
int main()
{
    double A, B, C;
    cin>>A>>B>>C;
    double triagle = 0.5*A*C;
    double circle = pi*(C*C);
    double trapezium = 0.5*C*(A+B);
    double squares = B*B;
    double rectangle = A*B;

    cout << fixed << setprecision(3);
    cout<<"TRIANGULO: "<< triagle << endl;
    cout<<"CIRCULO: "<< circle << endl;
    cout<<"TRAPEZIO: "<< trapezium << endl;
    cout<<"QUADRADO: "<< squares << endl;
    cout<<"RETANGULO: "<< rectangle << endl;
    return 0;
}