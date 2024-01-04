// Minimum Number of Operations to Make Array Empty

// Task
// You are given a 0-indexed array nums consisting of positive integers.
// There are two types of operations that you can apply on the array any number of times:
// Choose two elements with equal values and delete them from the array.
// Choose three elements with equal values and delete them from the array.
// Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

// Example 1:
// Input: nums = [2,3,3,2,2,4,2,3,4]
// Output: 4

// Example 2:
// Input: nums = [2,1,2,2,3,3]
// Output: -1

// Solution
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> nums_count;
        for (size_t i = 0; i < nums.size(); ++i) {
            ++nums_count[nums[i]];
        }
        int count = 0;
        for (auto number: nums_count) {
            int tmp = number.second / 3;
            if (tmp == 0) {
                if (number.second % 2 == 0) {
                    count += number.second / 2;
                } else {
                    return -1;
                }
            } else {
                count += tmp;
                tmp = number.second % 3;
                switch (tmp) {
                    case 0:
                        continue;
                    case 1:
                        count += -1 + (tmp + 3) / 2;
                        break;
                    case 2:
                        ++count;
                        break;
                    default:
                        break;
                }
            }
        }
        return count;
    }
};

// Results
// Runtime:
// 117 ms (Beats 71.64%)
// Memory:
// 85.1 MB (Beats 90.6%)