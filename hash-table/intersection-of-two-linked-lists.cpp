/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* left = headA;
        ListNode* right = headB;
        while(left!=right){
            left = left->next;
            right = right->next;
            if(left==right) return left;
            if(left==NULL) left=headB;
            if(right==NULL) right=headA;
        }
        return left;
    }
};