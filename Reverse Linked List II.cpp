// 92. Reverse Linked List II
// Medium.
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // m - n == 0 means that they both signify the same node (it can't be reversed)
        if(m - n == 0 || head == NULL)
           return head;
        
        ListNode *tail = NULL, *prev = NULL, *mid = NULL, *temp = head, *newNode = NULL;
        for(int i = 1; i <= n; ++i)
        {
            if(i == m)
            {
                // mid stores the node just before the beginning of the reverse linked list
                mid = prev;
                tail = temp;
                prev = temp;
                temp = temp->next;
            }
            else if(i > m)
            {
                newNode = temp->next;
                temp->next = prev;
                prev = temp;
                temp = newNode;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        // prev is the beginning of reversed linked list
        if(mid)
            mid->next = prev;
        else
            head = prev; // if mid == NULL, then that means the list if reversed from the beginning
        
        // temp now points to node just after the end-point of the reversed linked list
        tail->next = temp;
        
        return head;
    }
};