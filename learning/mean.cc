
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> numbers = {2, 4, 6, 8};

    int sum = 0;

    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

    double mean = (double)sum / numbers.size();

    cout << "Mean: " << mean;

    return 0;
}
