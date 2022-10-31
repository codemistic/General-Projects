#include <iostream>
#include <bits/stdc++.h>
class node
{
private:
    /* data */
public:
    int data;
    node *next;
 
};

  void print_list(node* head){
      node* list=head;
       while (list!=NULL)
       {
          std::cout<<list->data<<"\n";
           list=list->next;/* code */
       }
       
        
    }
class node* insert_begin(int val,node* head){
    node * start;
    start= new node();
    start->data=val;
    start->next=head;
    return start;
    
}
class node* insert_index(int val,node* head,int index){
    node * ptr=head;
    node * p;
    p= new node();
    p->data=val;
    int i=0;
    while (i!=index-1)
    {
        ptr=ptr->next;
        i++;/* code */
    }
    p->next=ptr->next;

    ptr->next=p;

    return head;
    
}
class node* insert_last(int val,node* head){
    node * ptr=head;
    node * end;
    end= new node();
    end->data=val;

    while (ptr->next!=NULL)
    {
        ptr=ptr->next;/* code */
    }
    ptr->next=end;
    end->next=NULL;

    return head;
    
}

using namespace std;

int main()
{
    node *first;
    first = new node();
    node *second;
    second = new node();
    node *third;
    third = new node();
    node *fourth;
    fourth = new node();
    first->data = 7;
    first->next = second;
    second->data = 10;
    second->next = third;
    third->data = 46;
    third->next = fourth;
    fourth->data = 84;
    fourth->next = NULL;
    print_list(first);
    first = insert_begin(101,first);
    cout<<"After insertion of element at start of the linked list\n";
    print_list(first);
   first= insert_last(416,first);
    cout<<"After insertion of element at end of the linked list\n";

    print_list(first);

    first=insert_index(555,first,2);
    cout<<"After insertion of element at an index of the linked list\n";

    print_list(first);   
    
    return 0;
}
