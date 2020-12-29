// 148. Sort List
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
    void split(ListNode *source, ListNode **l1, ListNode **l2)
    {
        if(source == NULL || source->next == NULL)
            return;
        
        ListNode *fast = source->next, *slow = source;
        while(fast)
        {
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *l1 = source;
        *l2 = slow->next;
        slow->next = NULL;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode *k = NULL;
        
        if(l1->val < l2->val)
        {
            k = l1;
            k->next = merge(l1->next, l2);
        }
        else
        {
            k = l2;
            k->next = merge(l1, l2->next);
        }
        return k;
    }
    
    void mergeSort(ListNode **head)
    {
        ListNode *source = *head;
        if(source == NULL || source->next == NULL)
            return;
        ListNode *l1 = NULL, *l2 = NULL;
        split(source, &l1, &l2);
        mergeSort(&l1);
        mergeSort(&l2);
        *head = merge(l1, l2);
        
    }
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};