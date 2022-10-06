#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *createNode(int val)
{
	struct node *r;
	r=(struct node *)malloc(sizeof(struct node));
	r->data=val;
	r->left=NULL;
	r->right=NULL;
	return r;
}
struct node *lc(struct node *d,int value)
{
	
	d->left=createNode(value);
	return d->left; 
}
struct node *rc(struct node *d,int value)
{
	
	d->right=createNode(value);
	return d->right; 
}
void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
int main()
{
	struct node* d=createNode(5);;
	
	lc(d,6);
	rc(d,7);
	lc(d->left,8);
	preorder(d);
	printf("\n");
	inorder(d);
	printf("\n");
	postorder(d);
	return 0;
}
