#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
     struct node* prev;
     struct node* next;                             
};

void traversalofll(struct node* ptr){ 
   struct node* ptr2 = ptr;  
     do{
        printf("Element : %d\n", ptr-> data);
        ptr = ptr->next;
     }while(ptr != NULL);

     
}

int main(){
    int data;     
                              // creation of nodes
    struct node *head;
       head = (struct node*)malloc(sizeof(struct node));
    struct node *second;
       second = (struct node*)malloc(sizeof(struct node));
    struct node *third;
       third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth;
       fourth = (struct node*)malloc(sizeof(struct node));
         system("cls");
    
                                                      // initialisation of nodes

            // initial values of first node
       head -> data = 2003;
       head -> prev = NULL;
       head -> next = second;

            // initial values of second node
       second -> data = 1970;
       second -> prev = head;
       second -> next = third;

            // initial values of third node
       third -> data = 1973;
       third -> prev = second;
       third -> next = fourth;

            // initial values of fourth node
       fourth -> data = 1998;
       fourth -> prev = third;
       fourth -> next = NULL;     

                  // this creates another pointer ptr that access the values in a linked list
        
       traversalofll(head);

        
    return 0;
}
