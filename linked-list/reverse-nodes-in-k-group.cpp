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
    ListNode* reverseNode(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* head , int k){
        k -=1;
        while(head!=NULL && k>0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode==NULL){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            reverseNode(temp);
            if(temp==head){
                head = KthNode;
            }
            else{
                prevNode->next = KthNode;
            }
            prevNode = temp;
            temp=nextNode;
        }
        return  head;
    }
};