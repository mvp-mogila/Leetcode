// Number of Even and Odd Bits

// Task
// You are given a positive integer n.
// Let even denote the number of even indices in the binary representation of n (0-indexed) with value 1.
// Let odd denote the number of odd indices in the binary representation of n (0-indexed) with value 1.
// Return an integer array answer where answer = [even, odd].

// Example 1:
// Input: n = 17
// Output: [2,0]

// Example 2:
// Input: n = 2
// Output: [0,1]

// Solution
func evenOddBit(n int) []int {
    index := 0
    result := make([]int, 2)
    for n > 0 {
        result[index % 2] += n & 1
        n >>= 1
        index++
    }
    return result
}

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 2.16 MB (Beats 92.61%)