// Leaf-Similar Trees

// Task
// Consider all the leaves of a binary tree, from left to right order,
// the values of those leaves form a leaf value sequence.
// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

// Example 1:
// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true

// Example 2:
// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false

// Solution
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        findLeafs(root1, leafs1);
        vector<int> leafs2;
        findLeafs(root2, leafs2);
        return leafs1 == leafs2;
    }

    void findLeafs(TreeNode* root, vector<int>& leafs) {
        if (root) {
            if (!root->left && !root->right) {
                leafs.push_back(root->val);
            } else if (!root->left) {
                findLeafs(root->right, leafs);
            } else if (!root->right) {
                findLeafs(root->left, leafs);
            } else {
                findLeafs(root->left, leafs);
                findLeafs(root->right, leafs);
            }
        }
    }
};

// Results
// Runtime:
// 0 ms (Beats 100%)
// Memory:
// 13.19 MB (Beats 77.17%)