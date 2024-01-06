// Largest 3-Same-Digit Number in String

// Task
// You are given a string num representing a large integer.
// An integer is good if it meets the following conditions:
// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.
// Note:
// A substring is a contiguous sequence of characters within a string.
// There may be leading zeroes in num or a good integer.
 
// Example 1:
// Input: num = "6777133339"
// Output: "777"

// Example 2:
// Input: num = "42352338"
// Output: "" 

// Solution
class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "   ";
        for (size_t i = 0; i < num.length() - 2; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2] && num[i] > result[0]) {
                result[0] = result[1]  = result[2] = num[i];
                i += 2;
            }
        }
        return (result == "   ") ? "" : result;
    }
};

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 6.82 MB (Beats 49.42%)