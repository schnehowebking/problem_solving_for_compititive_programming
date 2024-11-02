#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int numbers[] = {a, b, c};

    sort(numbers, numbers + 3);

    for (int i = 0; i < 3; i++) {
        cout << numbers[i] << endl;
    }

    cout << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}