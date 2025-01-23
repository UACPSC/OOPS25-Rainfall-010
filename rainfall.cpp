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
    double n;
    while (std::cin >> n) {
        rainfall.push_back(n);
    }
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate the average and heaviest rainfall
    auto total = rainfall[0];
    auto heaviest = rainfall[0];
    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
        total += rainfall[i];
        if (rainfall[i] > heaviest)
            heaviest = rainfall[i];
    }

    // output the rainfall report
    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    std::cout << "|:----------------|----------------|" << '\n';
    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';

    return 0;
}
