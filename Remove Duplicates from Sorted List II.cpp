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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        ListNode *newHead = NULL, *newEnd = NULL;
        map<int, int> mp;
        while(temp)
        {
            if(temp->next != NULL && temp->val != temp->next->val)
            {
                if(newEnd == NULL)
                {
                    newEnd = new ListNode(temp->val);
                    newHead = newEnd;
                }
                else
                {
                    newEnd->next = new ListNode(temp->val);
                    newEnd = newEnd->next;
                }
                temp = temp->next;
            }
            else
            {
                int value = temp->val;
                if(temp->next == NULL)
                {
                    if(newEnd == NULL)
                    {
                        newEnd = new ListNode(temp->val);
                        newHead = newEnd;
                    }
                    else
                    {
                        newEnd->next = new ListNode(temp->val);
                        newEnd = newEnd->next;
                    }
                }
                while(temp != NULL && value == temp->val)
                    temp = temp->next;
            }
        }
        return newHead;
    }
};