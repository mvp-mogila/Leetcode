// Monotonic Array

// Task
// An array is monotonic if it is either monotone increasing or monotone decreasing.
// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
// An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

// Example 2:
// Input: nums = [6,5,4,4]
// Output: true


// Solution
func isMonotonic(nums []int) bool {
    var (
        i int = 1
        decr bool = false
    )
    for ; i < len(nums); i++ {
        if nums[i] < nums[i - 1] {
            decr = true
            break
        } else if nums[i] > nums[i - 1] {
            decr = false
            break
        }
    }
    for ; i < len(nums); i++ {
        if decr {
            if nums[i] > nums[i - 1] {
                return false
            }
        } else {
            if nums[i] < nums[i - 1] {
                return false
            }
        }
    }
    return true
}

// Results
// Runtime:
// 126 ms (Beats 61.31%)
// Memory:
// 8.67 MB (Beats 59.12%)