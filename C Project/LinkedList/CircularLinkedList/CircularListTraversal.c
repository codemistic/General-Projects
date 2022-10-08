
/*    Insert First Node in Circular Linked List       */

#include<stdio.h>

#include<stdlib.h>

struct node{
    int data;
     struct node* next;                             // self referencing structure
};

void lltraversal(struct node* head){   
     struct node *ptr = head;
     int i=1;           
       do{
         printf(" Element %d is %d\n",i, ptr -> data);
         i++;           // to access the data use arrow operator
         ptr = ptr -> next;                     // ptr gets another address everytime
       }while(ptr != head);
}


int main(){
                 int data,index;     
                              // creation of nodes
    struct node *head;
       head = (struct node*)malloc(sizeof(struct node));
    struct node *second;
       second = (struct node*)malloc(sizeof(struct node));
    struct node *third;
       third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth;
       fourth = (struct node*)malloc(sizeof(struct node));

    
                                                      // initialisation of nodes

            // initial values of first node
       head->data = 2003;
       head->next = second;

            // initial values of second node
       second->data = 1970;
       second->next = third;

            // initial values of third node
       third->data = 1973;
       third->next = fourth;

            // initial values of fourth node
        fourth->data = 1998;
       fourth->next = head;             // this defined the circular linked list

                  // this creates another pointer ptr that access the values in a linked list

         lltraversal(head);
     
    return 0;
}
