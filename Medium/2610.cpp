// Convert an Array Into a 2D Array With Conditions

// Task
// You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
// The 2D array should contain only the elements of the array nums.
// Each row in the 2D array contains distinct integers.
// The number of rows in the 2D array should be minimal.
// Return the resulting array. If there are multiple answers, return any of them.
// Note that the 2D array can have a different number of elements on each row.

// Example 1:
// Input: nums = [1,3,4,1,2,3,1]
// Output: [[1,3,4,2],[1,3],[1]]

// Example 2:
// Input: nums = [1,2,3,4]
// Output: [[4,3,2,1]]

// Solution
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, size_t> nums_frequency;
        size_t rows_count = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            ++nums_frequency[nums[i]];
            if (rows_count < nums_frequency[nums[i]]) {
                rows_count = nums_frequency[nums[i]];
            }
        }
        vector<vector<int>> result(rows_count);
        for (auto number: nums_frequency) {
            for (size_t i = 0; i < number.second; ++i) {
                result[i].push_back(number.first);
            }
        }
        return result;
    }
};

// Results
// Runtime:
// 12 ms (Beats 57.77%)
// Memory:
// 29.9 MB (Beats 70.51%)