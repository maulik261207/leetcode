struct ListNode* reverseList(struct ListNode* head){
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