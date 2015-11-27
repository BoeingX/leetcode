/**
 *
 * Definition for singly-linked list.
 *
 * struct ListNode {
 *
 *     int val;
 *
 *     ListNode *next;
 *
 *     ListNode(int x) : val(x), next(NULL) {}
 *
 * };
 *
 **/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return false;
        ListNode *tortue = head;
        ListNode *lievre = head->next;
        while(lievre->next != NULL && lievre->next->next != NULL){
            if(lievre == tortue)
                return true;
            tortue = tortue->next;
            lievre = lievre->next->next;
        }
        return false;
    }
};
