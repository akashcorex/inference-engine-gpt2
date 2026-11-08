
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<double> numbers = {2, 4, 6, 8};

    double sum = 0;

    // Step 1: Calculate sum
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

    // Step 2: Calculate mean
    double mean = sum / numbers.size();

    cout << "Mean: " << mean << endl;

    // Step 3: Calculate squared deviations
    vector<double> deviations;

    for (int i = 0; i < numbers.size(); i++) {
        double difference = numbers[i] - mean;

        double squared = difference * difference;

        deviations.push_back(squared);
    }

    // Step 4: Calculate variance sum
    double variance_sum = 0;

    for (int i = 0; i < deviations.size(); i++) {
        variance_sum += deviations[i];
    }

    // Step 5: Calculate variance
    double variance = variance_sum / numbers.size();

    cout << "Variance: " << variance << endl;

    return 0;
}
