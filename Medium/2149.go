// Rearrange Array Elements by Sign

// Task
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should rearrange the elements of nums such that the modified array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Example 1:
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

// Example 2:
// Input: nums = [-1,1]
// Output: [1,-1]

// Solution
func rearrangeArray(nums []int) []int {
    var result = make([]int, len(nums))
    var lastPositive, lastNegative int = 0, 1
    for _, num := range(nums) {
        if (num < 0) {
            result[lastNegative] = num
            lastNegative += 2
        } else {
            result[lastPositive] = num
            lastPositive += 2
        }
    }
    return result
}

// Results
// Runtime:
// 210 ms (Beats 62.82%)
// Memory:
// 13.19 MB (Beats 66.67%)