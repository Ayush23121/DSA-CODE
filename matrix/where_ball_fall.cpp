#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);

        for (int start = 0; start < n; start++) {
            int col = start;

            for (int row = 0; row < m; row++) {
                int dir = grid[row][col];
                int next_col = col + dir;

                // check walls or "V" trap
                if (next_col < 0 || next_col >= n || grid[row][next_col] != dir) {
                    col = -1;
                    break;
                }

                col = next_col;
            }

            ans[start] = col;
        }

        return ans;
    }
};

int main() {
    Solution s;

    // Example test case
    vector<vector<int>> grid = {
        {1,1,1,-1,-1},
        {1,1,1,-1,-1},
        {-1,-1,-1,1,1},
        {1,1,1,1,-1},
        {-1,-1,-1,-1,-1}
    };

    vector<int> result = s.findBall(grid);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
