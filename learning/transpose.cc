#include <iostream>
#include <vector>

using namespace std;

class transpose {
    public:
        vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();

            vector<vector<int>> result(n, vector<int>(m));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result[j][i] = matrix[i][j];
                }
            }
            return result;
        }
};

int main() {
    // 1. create input
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 2. create object of transpose class
    transpose t;

    // 3. call transposeMatrix method
    vector<vector<int>> result = t.transposeMatrix(matrix);

    // 4. print result
    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}