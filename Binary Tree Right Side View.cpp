// 199. Binary Tree Right Side View
// Medium.

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
    // we will perform level order traversal and will only leep the last node
    // i.e. the right most node which would mean the rightside view of the tree
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int nodeCount = q.size();
            for(int i = 0; i < nodeCount; ++i)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                if(i == nodeCount - 1)
                    res.emplace_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};