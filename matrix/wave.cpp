#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>>& arr) {
    int n = arr.size();        // rows
    int m = arr[0].size();     // columns

    for (int col = 0; col < m; col++) {
        if (col % 2 == 0) {
            // Top to bottom
            for (int row = 0; row < n; row++)
                cout << arr[row][col] << " ";
        } else {
            // Bottom to top
            for (int row = n - 1; row >= 0; row--)
                cout << arr[row][col] << " ";
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    wavePrint(arr);
    return 0;
}
