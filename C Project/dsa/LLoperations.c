#include <stdio.h>
#include <stdlib.h>

// creation of node for linked list
struct node
{
    int data;
    struct node *next;
};

// traversal function
void LLtraversal(struct node *ptr)
{
    printf("\nthe elements of list are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// insertion at start function
struct node *begininsert(struct node *head, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = val;
    return ptr;
}

// insert at any index function
struct node *insertAtIndex(struct node *head, int val, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

// insert at end function
struct node *endinsert(struct node *head, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}

// insert after particular node function
struct node *insertAfterNode(struct node *head, struct node *prevnode, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}

// deleting first node function
struct node *deletefirstnode(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// delete elemenet at particular index
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    struct node *ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
    return head;
}

// delete last element
struct node *deleteAtEnd(struct node *head)
{
    struct node *temp = head;
    struct node *ptr = head->next;
    while (ptr->next != NULL)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);
    return head;
}

// delete the first instance of given value
struct node *deleteKey(struct node *head, int val)
{
    struct node *temp = head;
    struct node *ptr = head->next;
    while (ptr->data != val && ptr->next != NULL)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    if (ptr->data == val)
    {
        temp->next = ptr->next;
        free(ptr);
    }
    return head;
}

// driver code
int main()
{
    // creation of LL
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 8;
    head->next = second;

    // link second and third nodes
    second->data = 9;
    second->next = third;

    // link third and fourth nodes
    third->data = 10;
    third->next = fourth;

    // terminate the list at the fourth node
    fourth->data = 11;
    fourth->next = NULL;

    LLtraversal(head);
    printf("\nafter adding element to the front of LL\n");
    head = begininsert(head, 3);
    LLtraversal(head);

    printf("\ninsert at index:\n");
    head = insertAtIndex(head, 2, 2);
    LLtraversal(head);

    printf("\nafter end insert :\n");
    head = endinsert(head, 4);
    LLtraversal(head);

    printf("\ninserting after a particular node:\n");
    head = insertAfterNode(head, second, 16);
    LLtraversal(head);

    printf("\ndeleting the first node:\n");
    head = deletefirstnode(head);
    LLtraversal(head);

    printf("\ndeleting the element at a particular index:\n");
    head = deleteAtIndex(head, 3);
    LLtraversal(head);

    printf("\ndeleting the element at the end:\n");
    head = deleteAtEnd(head);
    LLtraversal(head);

    printf("\ndeleting the element of particular value:\n");
    head = deleteKey(head, 15);
    LLtraversal(head);

    return 0;
}