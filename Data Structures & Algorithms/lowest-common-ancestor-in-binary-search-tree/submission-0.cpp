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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || root == p || root == q) return root;

        TreeNode *leftVal = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rightVal = lowestCommonAncestor(root -> right, p, q);

        if(leftVal && rightVal) return root;

        return leftVal ? leftVal : rightVal;
    }
};
