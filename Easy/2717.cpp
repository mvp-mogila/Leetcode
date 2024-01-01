// Task
// You are given a 0-indexed permutation of n integers nums.
// A permutation is called semi-ordered if the first number equals 1 and the last number equals n.
// You can perform the below operation as many times as you want until you make nums a semi-ordered permutation:
// - Pick two adjacent elements in nums, then swap them.

// Return the minimum number of operations to make nums a semi-ordered permutation.
// A permutation is a sequence of integers from 1 to n of length n containing each number exactly once.

// Example 1:
// Input: nums = [2,1,4,3]
// Output: 2

// Example 2:
// Input: nums = [2,4,1,3]
// Output: 3

// Example 3:
// Input: nums = [1,3,4,2,5]
// Output: 0

// Solution
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int one_pos, n_pos;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                one_pos = i;
            } else if (nums[i] == n) {
                n_pos = i;
            }
        }
        if (one_pos < n_pos) {
            return n - (n_pos + 1) + one_pos;
        } else {
            return n - (n_pos + 2) + one_pos; 
        }
    }
};

// Results
// Runtime:
// 11 ms (Beats 76.23%)
// Memory:
// 46.6 MB (Beats 99.18%)