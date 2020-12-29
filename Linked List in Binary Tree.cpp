// 1367. Linked List in Binary Tree
// Medium.

/*
  THIS SOLUTION IS GIVING TLE IN A FEW CASES BUT I THINK IT IS CORRECT AND
  IT NEEDS TO BE OPTIMIZED
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool doesPathExist(TreeNode *root, ListNode *head, bool changed)
    {
        if(head == NULL)
            return true;
        
        if(root == NULL)
            return false;
        
        if(changed && root->val != head->val)
            return false;
        
        bool matched = false, unmatched = false;
        if(root->val == head->val)
            matched = doesPathExist(root->left, head->next, true) || doesPathExist(root->right, head->next, true);
        
        unmatched = doesPathExist(root->left, head, changed) || doesPathExist(root->right, head, changed);
        
        return (matched || unmatched);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return doesPathExist(root, head, false);
    }
};