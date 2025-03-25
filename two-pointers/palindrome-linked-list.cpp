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
    ListNode* Fun_reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev = NULL;
        temp=temp->next;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = Fun_reverse(slow);
        ListNode* left = head;
        ListNode* right = newHead;
        while(right!=NULL){
            if(right->val != left->val){
                return false;
            }
            left = left->next;
            right= right->next;
        }
        return true;
    }
};