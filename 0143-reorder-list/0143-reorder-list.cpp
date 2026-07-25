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


 ListNode* rev(ListNode*r){
    if(!r) return NULL;
    ListNode*prv = NULL;
    while(r){
        ListNode*nxt = r->next;
        r->next =  prv;
        prv = r;
        r = nxt;
    }
     return prv;
 }
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next ) return;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*sec  =rev(slow->next);
        slow->next =NULL;
        ListNode*me = head;
        ListNode*ans = me;
        while(sec){
            ListNode*a = me->next;
            ListNode*b = sec->next;
            me->next = sec;
            sec->next = a;

            me = a;
            sec = b;


        }
        
    }
};