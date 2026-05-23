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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return vector<vector<int>> {};

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> result;
        vector<int> temp;

        while(!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if(!currNode) {
                result.push_back(temp);
                temp.clear();
                if(q.empty()) break;
                else q.push(NULL);
            }
            else {
                temp.push_back(currNode -> val);
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
            }
        }

        return result;
    }
};
