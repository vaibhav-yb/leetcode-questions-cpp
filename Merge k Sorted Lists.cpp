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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *newHead = NULL, *newEnd = NULL;
        while(true)
        {
            int ind = -1, minVal = INT_MAX;
            for(int i = 0; i < k; ++i)
            {
                if(lists[i] != NULL)
                {
                    if(lists[i]->val < minVal)
                    {
                        minVal = lists[i]->val;
                        ind = i;
                    }
                }
            }
            
            if(ind != -1)
            {
                // add the value at linklist at index = ind
                if(newEnd == NULL)
                {
                    newEnd = new ListNode(minVal);
                    newHead = newEnd;
                }
                else
                {
                    newEnd->next = new ListNode(minVal);
                    newEnd = newEnd->next;
                }
                lists[ind] = lists[ind]->next;
            }
            // if ind == -1, that means that the complete list has been traversed and added and
            // there are no more elements left to iterate so break out of the while loop now
            else
                break;
        }
        return newHead;
    }
};