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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<pair<int, TreeNode*>> q;
        q.push({ 0, root });
        q.push({ 0, NULL });

        while(!q.empty())
        {
            pair<int, TreeNode*> temp = q.front();
            q.pop();

            int level = temp.first;
            TreeNode *currNode = temp.second;

            if(currNode == NULL)
            {
                if(q.empty() || q.front().second == NULL) break;
                else q.push({ level + 1, NULL });
                continue;
            }

            if(level == result.size()) result.push_back(currNode -> val);

            if(currNode -> right) q.push({ level + 1, currNode -> right });
            if(currNode -> left) q.push({ level + 1, currNode -> left });
        }

        return result;
    }
};
