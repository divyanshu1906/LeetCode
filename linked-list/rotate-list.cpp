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
        if(!head || !head->next || k==0) return head; 
        int len = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        if(k%len==0)return head;
        k = k%len;
        int p = len-k;
        temp->next=head;
        ListNode* lastNode = head;
        while(--p){
            lastNode = lastNode->next;
        }
        ListNode* newHead = lastNode->next;
        lastNode->next = NULL;
        return newHead;
    }
};