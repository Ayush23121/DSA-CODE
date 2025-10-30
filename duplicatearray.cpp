#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int j = 0; // index of last unique element
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1; // new length
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int newLength = sol.removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
