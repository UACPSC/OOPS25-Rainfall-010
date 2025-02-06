/*
    rainfall.cpp

    Rainfall report. Inputs are rain amounts per hour. Output is the average
    and heaviest hourly rainfall.
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

// maximum of the data
double max(const std::vector<double>& data) {
    auto maximum = data[0];
    for (const auto value : data) {
        if (value > maximum)
            maximum = value;
    }
    return maximum;
}

int main() {

    // input hourly rainfall data
    const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin), std::istream_iterator<double>() };
    if (!rainfall.size()) {
        std::cerr << "Error: no rainfall data\n";
        return 1;
    }

    // calculate the heaviest rainfall
    auto heaviest = rainfall[0];
    for (const auto rain : rainfall) {
        if (rain > heaviest)
            heaviest = rain;
    }

    // calculate the average rainfall
    double total = 0.0;
    for (const auto rain : rainfall) {
        total += rain;
    }
    const auto average = total / rainfall.size();

    // output the rainfall report
    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
    std::cout << "|:----------------|----------------|" << '\n';
    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';
    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';

    return 0;
}
