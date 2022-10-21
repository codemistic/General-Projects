 Node* reverse(Node* head){
            if(head==NULL||head->next==NULL) return head;
            Node* curr=head,*prev=NULL, *next=NULL;
            while(curr){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
Node* rotate(Node* head, int k)
    {
        // Your code here
        int i=1;
        Node* temp= head;
        while(i<k){
            temp=temp->next;
            i++;
        }
        Node* head2= temp->next;
        temp->next=NULL;
        Node* newHead= reverse(head);
        Node* newtemp= newHead;
        while(newtemp->next!=NULL){
            newtemp=newtemp->next;
        }
        newtemp->next= reverse(head2);
        Node* ans= reverse(newHead);
        return ans;
    }
