#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
T dotProduct(const vector<T>& A, const vector<T>& B) {
    if (A.size() != B.size()) {
        throw invalid_argument("Vectors must be of the same size");
    }

    T result = 0; 

    for (size_t i = 0; i < A.size(); i++) {
        result += A[i] * B[i];
    }

    return result;
}

int main() {
    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 6};

    try {
        int result = dotProduct(A, B);
        cout << "Dot product: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}

