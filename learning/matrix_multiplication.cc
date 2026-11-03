// std::vector<float> Stores a list of decimal numbers
// assert() automatically check wheather a result is correct or not

// Understand how a matrix is stored in c++
// std::vector<float> A = {
//    1, 2, 3,
//    4, 5, 6,
//    7, 8, 9
// };

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using Tensor = std::vector<float>;

Tensor matMul(
    const Tensor& A,
    int rowsA,
    int colsA,
    const Tensor& B,
    int rowsB,
    int colsB
) {
    // The inner dimension must match
    assert(colsA == rowsB);

    // Verify that the arrays contain the expected numbers of values
    assert(A.size() == static_cast<size_t>(rowsA * colsA));
    assert(B.size() == static_cast<size_t>(rowsB * colsB));

    // Result dimesions: rowsA x colsB
    Tensor result(rowsA * colsB, 0.0f);

    for(int i = 0; i < rowsA; i++) {
        for(int k = 0; k < colsA; k++) {
            float a = A[i * colsA + k];

            for(int j = 0; j < colsB; j++) {
                float b = B[k * colsB + j];
                result[i * colsB + j] += a * b;
            }
        }
    }

    return result;
}

int main() {
    Tensor A = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Tensor B = {
        1, 2,
        3, 4,
        5, 6
    };

    Tensor C = matMul(A, 3, 3, B, 3, 2);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << C[i * 2 + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}