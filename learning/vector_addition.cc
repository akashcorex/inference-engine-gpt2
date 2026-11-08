
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
vector<T> vectorAddition(const vector<T>& A, const vector<T>& B) {

    if (A.size() != B.size()) {
        throw invalid_argument("Vectors must be of the same size");
    }

    vector<T> result;

    for (size_t i = 0; i < A.size(); i++) {
        result.push_back(A[i] + B[i]);
    }

    return result;
}

int main() {

    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 6};

    try {
        vector<int> result = vectorAddition(A, B);

        cout << "Vector addition: ";

        for (int num : result) {
            cout << num << " ";
        }
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
