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
    int goodNodes(TreeNode* root) {
        
        queue<pair<int, TreeNode*>> q;
        q.push({ INT_MIN, root });
        q.push({ INT_MIN, NULL });

        int count = 0;

        while(!q.empty())
        {
            pair<int, TreeNode*> temp = q.front();
            q.pop();

            int maxi = temp.first;
            TreeNode *currNode = temp.second;

            if(!currNode)
            {
                if(q.empty()) break;
                else q.push({ 0, NULL });
                continue;
            }

            if(maxi <= currNode -> val) {
                count+=1;
                maxi = currNode -> val;
            }

            if(currNode -> left) q.push({ maxi, currNode -> left });
            if(currNode -> right) q.push({ maxi, currNode -> right });
        }

        return count;
    }
};
