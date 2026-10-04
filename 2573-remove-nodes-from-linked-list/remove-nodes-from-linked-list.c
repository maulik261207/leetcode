/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverse(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *temp = head;
    while(temp!=NULL){
        struct ListNode *next = temp->next; 
        temp->next = prev;                  
        prev = temp;                        
        temp = next;                        
    }
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    head = reverse(head);
    struct ListNode *p = head;
    while(p!=NULL&&p->next!=NULL){
        if(p->val>p->next->val)    p->next=p->next->next;
        else p=p->next;
    }
    return reverse(head);
}