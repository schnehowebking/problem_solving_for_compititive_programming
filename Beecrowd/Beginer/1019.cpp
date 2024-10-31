#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int hours = N / 3600;
    int minutes = (N % 3600) / 60;
    int seconds = N % 60;

    cout << hours << ":" << minutes << ":" << seconds << endl;
    return 0;
}