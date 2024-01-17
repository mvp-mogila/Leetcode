// Unique Number of Occurrences

// Task
// Given an array of integers arr, return true if the number of occurrences
// of each value in the array is unique or false otherwise.

// Example 1:
// Input: arr = [1,2,2,1,1,3]
// Output: true

// Example 2:
// Input: arr = [1,2]
// Output: false

// Solution
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurences;
        for (int num: arr) {
            ++occurences[num];
        }
        unordered_set<int> used;
        for (auto num: occurences) {
            if (used.find(num.second) == used.end()) {
                used.insert(num.second);
            } else {
                return false;
            }
        }   
        return true;
    }
};

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 8.60 MB (Beats 69.90%)