// 109. Convert Sorted List to Binary Search Tree

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
    TreeNode* addToTree(vector<int> &arr, int beg, int end, TreeNode *root)
    {
        int mid = beg + (end - beg) / 2;
        
        root = new TreeNode(arr[mid]);
        
        if(mid != beg)
            root->left = addToTree(arr, beg, mid-1, root->left);
        if(mid != end)
            root->right = addToTree(arr, mid+1, end, root->right);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> arr;
        ListNode *temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        TreeNode *root = NULL;
        return addToTree(arr, 0, arr.size()-1, root);;
    }
};