// Range Sum of BST

// Task
// Given the root node of a binary search tree and two integers low and high,
// return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32

// Example 2:
// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23

// Solution
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root) {
            if (root->val >= low && root->val <= high) {
                return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
            } else if (root->val < low) {
                return rangeSumBST(root->right, low, high);
            } else {
                return rangeSumBST(root->left, low, high);
            }
        } else {
            return 0;
        }
    }
};

// Results
// Runtime:
// 96 ms (Beats 65.87%)
// Memory:
// 65 MB (Beats 51.83%)