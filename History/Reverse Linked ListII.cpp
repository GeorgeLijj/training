/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if(head==NULL)return NULL;
        ListNode* rethead=head;
        ListNode* ltmp=NULL;
        ListNode* rtmp=NULL;
        ListNode* tmp;
        ListNode* prev;
        while(1){
            n--;
            m--;
            if(m==1)ltmp=head;
            if(n==-1){
                rtmp=head;
                break;
            }
            prev=head;
            head=head->next;
        }
        if(ltmp!=NULL)head=ltmp->next;
        else {
            head=rethead;
            rethead=prev;
        }
        prev=rtmp;
        while(head!=rtmp){
                tmp=head->next;
                head->next=prev;
                prev=head;
                head=tmp;
        }
        if(ltmp!=NULL){
            ltmp->next=prev;
        }
        return rethead;
    }
};
