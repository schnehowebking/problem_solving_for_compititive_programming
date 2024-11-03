#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 200005;
int totalElements, elements[MAX_SIZE];

bool query(int first, int second) {
    cout << "? " << first << " " << second << endl;
    cout.flush();

    int response;
    cin >> response;
    return (response == 0);
}

void displayResult() {
    cout << "! ";
    for (int i = 1; i <= totalElements; i++) {
        cout << elements[i] << " ";
    }
    cout.flush();
    cout << endl;
}

void process() {
    cin >> totalElements;
    totalElements--;

    int currentPosition = totalElements;
    for (int i = totalElements - 1; i >= 2; i--) {
        bool isMatched = query(currentPosition, i);
        if (isMatched) {
            elements[currentPosition] = i;
            currentPosition--;
        }
    }
    elements[currentPosition] = 1;
    for (int i = 1; i < currentPosition; i++) {
        elements[i] = 0;
    }
    displayResult();
}

int main() {
    ios::sync_with_stdio(false);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        process();
    }
}