// Number of Lines To Write String

// Task
// You are given a string s of lowercase English letters and an array widths denoting
// how many pixels wide each lowercase English letter is.
// Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.
// You are trying to write s across several lines, where each line is no longer than 100 pixels.
// Starting at the beginning of s, write as many letters on the first line
// such that the total width does not exceed 100 pixels.
// Then, from where you stopped in s, continue writing as many letters as you can on the second line.
// Continue this process until you have written all of s.
// Return an array result of length 2 where:
// result[0] is the total number of lines.
// result[1] is the width of the last line in pixels.

// Example 1:
// Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],
// s = "abcdefghijklmnopqrstuvwxyz"
// Output: [3,60]

// Example 2:
// Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],
// s = "bbbcccdddaaa"
// Output: [2,4]

// Solution
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result(2);
        result[0] = 1;
        result[1] = 0;
        size_t i = 0;
        while (i < s.length()) {
            if (result[1] + widths[s[i] - 'a'] < 100) {
                result[1] += widths[s[i] - 'a'];
            } else if (result[1] + widths[s[i] - 'a'] == 100) {
                if (i + 1 != s.length()) {
                    result[0]++;
                    result[1] = 0;
                } else {
                    result[1] += widths[s[i] - 'a'];
                }
            } else {
                result[1] = widths[s[i] - 'a'];
                result[0]++;
            }
            i++;
        }
        return result;
    }
};

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 7.4 MB (Beats 22.15%)