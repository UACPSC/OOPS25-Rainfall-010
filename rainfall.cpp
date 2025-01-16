/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<float> rainfall;
    float t, m, n;
    while (cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        cout << "Error: no rainfall data";
        return 1;
    }
    t = rainfall[0];
    m = rainfall[0];
    for (vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
        t += rainfall[i];
        if (rainfall[i] > m)
            m = rainfall[i];
    }
    cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    cout << "|:----------------|----------------|" << '\n';
    cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
    cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';

    return 0;
}
