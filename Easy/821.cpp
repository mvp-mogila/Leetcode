// Shortest Distance to a Character

// Task
// Given a string s and a character c that occurs in s,
// return an array of integers answer where answer.length == s.length and answer[i]
// is the distance from index i to the closest occurrence of character c in s.
// The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

// Example 1:
// Input: s = "loveleetcode", c = "e"
// Output: [3,2,1,0,1,0,0,1,2,2,1,0]

// Example 2:
// Input: s = "aaab", c = "b"
// Output: [3,2,1,0]

// Solution
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.length();
        std::vector <int> distance(len);
        int i = 0;
        while (i < len && s[i] != c) {
            i++;
        }
        int last_pos = i;
        while (i >= 0) {
            distance[i] = last_pos - i;
            i--;
        }
        for (i = last_pos + 1; i < len; i++) {
            if (s[i] == c) {
                for (int j = i; j > last_pos; j--) {
                    distance[j] = (i - j > j - last_pos) ? j - last_pos : i - j;
                }
                last_pos = i;
            }
        }
        if (last_pos != len - 1) {
            while (--i > last_pos) {
                distance[i] = i - last_pos;
            }
        }
        return distance;
    }
};

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 7.1 MB (Beats 84.96%)