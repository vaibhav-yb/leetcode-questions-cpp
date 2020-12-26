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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *list2_end = list2;
        while(list2_end->next != NULL)
            list2_end = list2_end->next;
        
        ListNode *tail = list1, *head = NULL;
        
        while(b-- && tail)
            tail = tail->next;
        list2_end->next = tail->next;
        
        a -= 1;
        ListNode *temp = list1;
        head = list1;
        while(a-- && temp)
            temp = temp->next;
        temp->next = list2;
        return head;
    }
};