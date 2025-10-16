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
    int count(ListNode* head){
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num=count(head);                                      
        if(num<k)
        return head;

        if(head==NULL){
            return NULL;
        }
        int x=k;
        ListNode* curr= head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr!=NULL && x--){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
           
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }

        return prev;
    }
};