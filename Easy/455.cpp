// Task
// Assume you are an awesome parent and want to give your children some cookies.
// But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
// and each cookie j has a size s[j]. If s[j] >= g[i],
// we can assign the cookie j to the child i, and the child i will be content.
// Your goal is to maximize the number of your content children and output the maximum number.

// Example 1
// Input: g = [1,2,3], s = [1,1]
// Output: 1

// Example 2
// Input: g = [1,2], s = [1,2,3]
// Output: 2

// Solution
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        if (!g.empty() && !s.empty()) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int i = 0;
            size_t j = 0;
            while (i < g.size() && j < s.size()) {
                if (g[i] <= s[j]) {
                    ++count;
                } else {
                    while (j < s.size() && g[i] > s[j]) {
                        ++j;
                    }
                    if (j == s.size()) {
                        return count;
                    } else {
                        ++count;
                    }
                }
                ++i;
                ++j;
            }
        }
        return count;
    }
};

// Results
// Runtime:
// 20 ms (Beats 90.30%)
// Memory:
// 17.8 MB (Beats 37.8%)
