// 61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        deque<int> q;
        ListNode *temp = head;
        while(temp)
        {
            q.push_back(temp->val);
            temp = temp->next;
        }
        // if k is greater than the given list size, it would essentially mean that we will be
        // rotating the array and making it come back to original position after k / n times,
        // so why bother even rotating it
        if(k > q.size())
            k = k % q.size();
        
        // the following part rotates the array
        while(k--)
        {
            int val = q[q.size() - 1];
            q.pop_back();
            q.push_front(val);
        }
        head = NULL;
        ListNode *end = NULL;
        for(int i = 0; i < q.size(); ++i)
        {
            if(head == NULL)
            {
                head = new ListNode(q[i]);
                end = head;
            }
            else
            {
                end->next = new ListNode(q[i]);
                end = end->next;
            }
        }
        return head;
    }
};