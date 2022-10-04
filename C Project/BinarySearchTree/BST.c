#include <stdio.h>
#include <stdlib.h>
// Declearing Structure of Node Of TREE.
/*
            45 ->root
          /   \
        40    50
Left CHild    Right child
*/
struct node
{
    int data;
    struct node *left, *right;
};
/*Function to get new node */
struct node *Newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL; // ASSIGN null TO LEFT CHILD 
    temp->data = data;
    temp->right = NULL; // ASSIGN NULL TO RIGHT CHILD
    return temp;
}

/*Function to insert element in tree*/
struct node *insert(struct node *root, int data)
{
    // check for root is null or not
    if (root == NULL)
        root = Newnode(data); // root will create new node

    // According to BST rule,element will be inserted
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
/*Function for getting pre-order traversal of tree.This function works
on principle of VLR
V-Visit Current node then visit(print data of node)
L-Left Sub-tree then visit
R-Right Sub-Tree*/
void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
/*Function for getting in-order traversal of tree.This function works on principle of LVR
Check for root is having left sub-tree if found,then visit node and Apply LVR for current node
L-Left Sub-tree then visit
V-Visit Current node then visit(print data of node)
R-Right Sub-Tree*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left); // Root will be updated by root->left new root will be root->left
    printf("%d ", root->data);
    inorder(root->right);
}
/*Function for getting Post-order traversal of tree.This function works on principle of LRV
check for root is having left sub-tree if found,then visit right sub-tree and Apply LVR for node
L-Left Sub-tree then visit
R-Right Sub-Tree
V-Visit Current node then visit(print data of node)*/
void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// Execution of Program will start from here
// IF NOT FOUND INCLUDE EXTRA FILES...
void main()
{
    int choice, data;
    struct node *root = NULL; // Declearing Root node
    while (1)
    {
        printf("\nSELECT CHOICE:");
        printf("\n1.ENTER ELEMENT");
        printf("\n2.PRE-ORDER TRAVERSAL");
        printf("\n3.IN-ORDER TRAVERSAL");
        printf("\n4.POST-ORDER TRAVERSAL");
        printf("\n5.Exit");
        printf("\nYOUR CHOICE::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);

        default:
            printf("\nEnter valid choice");
            break;
        }
    }
}