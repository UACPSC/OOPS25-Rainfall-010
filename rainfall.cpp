/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main() {

    // input hourly rainfall data
    std::vector<double> rainfall;
    double m;
    double n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate the average and heaviest rainfall
    double t = rainfall[0];
    m = rainfall[0];
    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
        t += rainfall[i];
        if (rainfall[i] > m)
            m = rainfall[i];
    }

    // output the rainfall report
    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    std::cout << "|:----------------|----------------|" << '\n';
    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';

    return 0;
}
