#include<bits/stdc++.h>
using namespace std;

int main()
{
    float N1, N2, N3, N4, examScore;
    cin >> N1 >> N2 >> N3 >> N4;

    // Calculate the weighted average
    float average = (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10.0;

    cout << fixed << setprecision(1);
    cout << "Media: " << average << endl;

    if (average >= 7.0) {
        cout << "Aluno aprovado." << endl;
    } else if (average < 5.0) {
        cout << "Aluno reprovado." << endl;
    } else {
        // Student is in exam
        cout << "Aluno em exame." << endl;
        cin >> examScore;
        cout << "Nota do exame: " << examScore << endl;

        // Recalculate the average with exam score
        float finalAverage = (average + examScore) / 2.0;
        
        if (finalAverage >= 5.0) {
            cout << "Aluno aprovado." << endl;
        } else {
            cout << "Aluno reprovado." << endl;
        }
        cout << "Media final: " << finalAverage << endl;
    }

    return 0;
}