// Hieght checker

// Task
// A school is trying to take an annual photo of all the students.
// The students are asked to stand in a single file line in non-decreasing order by height.
// Let this ordering be represented by the integer array expected where expected[i] is
// the expected height of the ith student in line. You are given an integer array heights
// representing the current order that the students are standing in. Each heights[i] is
// the height of the ith student in line (0-indexed).
// Return the number of indices where heights[i] != expected[i].

// Example 1:
// Input: heights = [1,1,4,2,1,3]
// Output: 3

// Example 2:
// Input: heights = [5,1,2,3,4]
// Output: 5

// Solution
func heightChecker(heights []int) int {
	expected := make([]int, len(heights))
	copy(expected, heights)
	slices.SortFunc(expected, func(a, b int) int {
		return a - b
	})
	var result int
	for i := 0; i < len(heights); i++ {
		if heights[i] != expected[i] {
			result++
		}
	}
	return result
}

// Results
// Runtime:
// 2 ms (Beats 58.46%)
// Memory:
// 2.3 MB (Beats 100%)