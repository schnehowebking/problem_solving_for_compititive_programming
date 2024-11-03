#include <bits/stdc++.h>
using namespace std;

void processCase() {
    int length, position;
    cin >> length >> position;

    if (length >= 3 && (position == 1 || position == length)) {
        cout << -1 << "\n";
        return;
    }
    if (length == 1) {
        cout << 1 << "\n" << 1 << "\n";
        return;
    }

    cout << 3 << "\n";
    cout << 1 << " ";
    if (position % 2 == 1) {
        cout << position - 1 << " " << position + 2 << "\n";
    } else {
        cout << position << " " << position + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    int testCount;
    cin >> testCount;

    while (testCount--) {
        processCase();
    }

    return 0;
}