// Minimum Deletions to Make Character Frequencies Unique

// Task
// A string s is called good if there are no two different characters in s that have the same frequency.
// Given a string s, return the minimum number of characters you need to delete to make s good.
// The frequency of a character in a string is the number of times it appears in the string.

// Example 1:
// Input: s = "aab"
// Output: 0

// Example 2:
// Input: s = "aaabbbcc"
// Output: 2

// Solution
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> letters_freq;
        for (auto c: s) {
            ++letters_freq[c];
        }
        unordered_set<int> freq;
        int delete_count = 0;
        for (auto letter: letters_freq) {
            int letter_freq = letter.second;
            while (letter_freq && freq.find(letter_freq) != freq.end()) {
                --letter_freq;
                ++delete_count;
            }
            if (letter_freq) {
                freq.insert(letter_freq);
            }
        }
        return delete_count;
    }
};

// Results
// Runtime:
// 75 ms (Beats 43.49%)
// Memory:
// 17.9 MB (Beats 15.8%)