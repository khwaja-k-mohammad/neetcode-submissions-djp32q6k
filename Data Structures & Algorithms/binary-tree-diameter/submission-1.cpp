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
    vector<int> findMaxDiameter(TreeNode *root)
    {
        if(!root) return vector<int>{0, 0};

        vector<int> left = findMaxDiameter(root -> left);
        vector<int> right = findMaxDiameter(root -> right);

        return vector<int> { 1 + max(left[0], right[0]), max(left[0] + right[0] + 1, max(left[1], right[1]))};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> result = findMaxDiameter(root);
        return result[1] - 1;
    }
};