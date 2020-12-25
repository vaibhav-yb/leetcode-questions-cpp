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
        map<int, int> mp;
        while(temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        head = NULL;
        ListNode *end = head;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
            if(itr->second == 1)
            {
                if(end == NULL)
                {
                    end = new ListNode(itr->first);
                    head = end;
                }
                else
                {
                    end->next = new ListNode(itr->first);
                    end = end->next;
                }
            }
        }
        return head;
    }
};