// Find First Palindromic String in the Array

// Task
// Given an array of strings words, return the first palindromic string in the array.
// If there is no such string, return an empty string "".
// A string is palindromic if it reads the same forward and backward.

// Example 1:
// Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"

// Example 2:
// Input: words = ["def","ghi"]
// Output: ""

// Solution
func firstPalindrome(words []string) string {
    var i, j int
    for ; i < len(words); i++ {
        for j = 0; j < len(words[i]) / 2; j++ {
            if (words[i][j] != words[i][len(words[i]) - j - 1]) {
                break
            }
        }
        if (j == len(words[i]) / 2) {
            return words[i]
        }
    }
    return ""
}

// Results
// Runtime:
// 8 ms (Beats 96.46%)
// Memory:
// 6.73 MB (Beats 72.57%)