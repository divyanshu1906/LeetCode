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
    ListNode* mergeLL(ListNode* left, ListNode* right){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp=temp->next;
        }
        if(left!=NULL){
            temp->next = left;
        }
        if(right!=NULL){
            temp->next = right;
        }
        return dummyNode->next;
    }
    ListNode* findMiddle(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return mergeLL(left, right);
    }
};