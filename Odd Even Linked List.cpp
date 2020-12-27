// 328. Odd Even Linked List
// Medium. Faster than 76.43%
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        
        // even_head is marked so as to point the last of odd group's node to
        // even group's head
        ListNode *odd = head, *even_head = head->next;
        ListNode *even = even_head, *prev = NULL;
        
        while(odd || even)
        {
            if(odd && odd->next)
                odd->next = odd->next->next;
            if(even && even->next)
                even->next = even->next->next;
            
            if(odd)
            {
                prev = odd;
                odd = odd->next;
            }
            if(even)
                even = even->next;
        }
        
        // prev now points to the last of the odd node if it is not null
        // if it is null then that means there was only one node
        if(prev != NULL)
            prev->next = even_head;
        
        return head;
    }
};