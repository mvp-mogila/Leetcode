// Count Nodes Equal to Average of Subtree

// Task
// Given the root of a binary tree, return the number of nodes
// where the value of the node is equal to the average of the values in its subtree.
// Note:
// The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.

// Example 1:
// Input: root = [4,8,5,0,1,null,6]
// Output: 5

// Example 2:
// Input: root = [1]
// Output: 1

// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int subtree_nodes_summ = 0;
        int subtree_nodes_count = 0;
        int count = 0;
        countAverages(root, subtree_nodes_summ, subtree_nodes_count, count);
        return count;
    }

    void countAverages(TreeNode* root, int& subtree_nodes_summ, int& subtree_nodes_count, int& count) {
        if (root) {
            if (!root->left && !root->right) {
                ++count;
                ++subtree_nodes_count;
                subtree_nodes_summ += root->val;
            } else {
                int tmp_summ = subtree_nodes_summ;
                int tmp_count = subtree_nodes_count;
                countAverages(root->left, subtree_nodes_summ, subtree_nodes_count, count);
                countAverages(root->right, tmp_summ, tmp_count, count);
                subtree_nodes_count += tmp_count + 1;
                subtree_nodes_summ += tmp_summ + root->val;
                if (root->val == subtree_nodes_summ / subtree_nodes_count) {
                    ++count;
                }
            }
        }
    }
};

// Results
// Runtime:
// 3 ms (Beats 92.98%)
// Memory:
// 12.5 MB (Beats 58.49%)