/* Coded by:
							Manasij Haldar, B.E.-3rd Year, CSE_AIML, Chandigarh University.
							Language used: C, Concept Used: Linked List.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node    //Structure creation for the Linked List//
{
	int data;						//To the data (book-name)//
	struct node *link;
}node;

node *head=NULL;			//pointer for start of list//
node *tail=NULL;			//pointer for end of list//

int n;

void create();
void display();
void shiftend(int);

void main()
{
	create();

	printf("\n");
	shiftend(n);
}

void create()					//Creation of the bookshelf//
{
	node *p,*newn;
	int i,j,readval;
	printf("\tEnter number of elements to add: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newn = (node *)malloc(sizeof(node));
		printf("\tEnter integer Value: ");
		scanf("%d",&readval);
		newn->data=readval;
		newn->link=NULL;
		tail=newn;				//Assigning the end of list//

		if(head==NULL)
			head=newn;
		else
		{
			p=head;
			while(p->link!=NULL)
			{
				p=p->link;
			}
			p->link=newn;
		}
	}

	printf("\n\n\t\t*****EXISTING LIST*****\n");
	display();
}

void display()			//To display the existing List//
{
	node *p;
	p=head;
	if(p==NULL)
	{
		printf("\tEMPTY\n");
		return;
	}
	printf("\n\t\t");
	while(p->link!=NULL)
	{
		printf("%d -> ",p->data);
		p=p->link;
	}
	printf("%d\n\n",p->data);
}

void shiftend(int n)   //To shift the same elements at the last//
{
	node *p,*temp;
	int search;

	printf("\n\tEnter element name to push to last: ");
	scanf("%d",&search);
	p=head;									//Assigning traversal pointer to the start of the list//
	temp->link=head;				//Assigning a pointer to reconstruct linking and mark left-over position//

	while(n>0)			//Loop runs until total number of elements in the list are not traversed//
	{
		if(head->data==search)			//Condition to Shift element if found at start//
		{
			head=head->link;
			temp->link=head;
			tail->link=p;				//Moving element to tail//
			p->link=NULL;				//Unlinking the element from the next element//
			tail=tail->link;		//Setting new tail to the end//
			p=temp->link;				//Resassigning traversal pointer to the left-over position//
			n--;
			continue;
		}
		if(p->data==search)						//General condition to shift element if found at any random position//
		{
			temp->link=p->link;
			tail->link=p;				//Moving element to tail//
			p->link=NULL;				//Unlinking the element from the next element//
			tail=tail->link;		//Setting new tail to the end//
			p=temp->link;				//Resassigning traversal pointer to the left-over position//
		}
		else					//To traverse the pointers to their next locations if no conditions are met//
		{
			temp=temp->link;
			p=p->link;
		}
		n--;
	}
	printf("\n\n\t\t*****AFTER SHIFTING*****\n");
	display();
}
