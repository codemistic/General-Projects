#include <stdio.h>
#include <stdlib.h>
struct node
{ int info;
struct node *link;
} * head, *current, *last, *ptr, *ptr1;
struct node * newnode(int info)
{ struct node *new;
new = (struct node *) malloc(sizeof(struct node));
new->info = info;
return new;
}
void insatbeg(int info) {
printf("Enter the info part: ");
scanf("%d", &info);
ptr1 = newnode(info);
ptr1->link = head;
head = ptr1;
}
void insatend(int info) {
ptr = head;
printf("Enter the info part: ");
scanf("%d", &info);
ptr1 = newnode(info);
while (ptr->link != NULL)
ptr = ptr->link;
ptr->link = ptr1;
ptr1->link = NULL;
last = ptr1;
}
void insatpos(int info) {
int count = 1,pos;
printf("\nEnter the info:");
scanf("%d", &info);
printf("Enter the position: ");
scanf("%d", &pos);
ptr1 = newnode(info);
ptr = head;
if (pos == 1) {
ptr1->link = head;
head = ptr1;
} else {
while (count < pos-1 && ptr->link!=NULL) {
ptr = ptr->link;
count++; }
ptr1->link = ptr->link;
ptr->link = ptr1;
}
}
void insoninfo(int info) {
struct node *ptr2;
printf("Enter the info:");
scanf("%d", &info);
ptr2 = newnode(info);
ptr = head;
if (head->info > ptr2->info) {
ptr2->link = head;
head = ptr2;
} else {
while (ptr->link!=NULL && ptr->link->info < ptr2->info) {
ptr = ptr->link;
}
ptr2->link = ptr->link;
ptr->link = ptr2;
}
}
void display() {
ptr = head;
while (ptr != NULL) {
printf("%d\n", ptr->info);
ptr = ptr->link;
}
}
int main() {
int choice=0, ele;
head = malloc(sizeof(struct node));
current = malloc(sizeof(struct node));
last = malloc(sizeof(struct node));
head->info = 45;
head->link = current;
current->info = 98;
current->link = last;
last->info = 105;
last->link = NULL;
while (1) {
printf("\n\n1.Enter 1 to insert at beginning\n");
printf("2.Enter 2 to insert at end\n");
printf("3.Enter 3 to insert at a specific position\n");
printf("4.Enter 4 to insert on the basis of info\n");
printf("5.Enter 5 to display the list\n");
printf("6.Enter 6 to exit the program\n");
printf("\nEnter the choice : ");
scanf("%d", &choice);
switch (choice) {
case 1:
insatbeg(ele);
printf("Element inserted at the beginning\n");
break;
case 2:
insatend(ele);
printf("Element inserted at end\n");
break;
case 3:
insatpos(ele);
printf("Element inserted\n");
break;
case 4:
insoninfo(ele);
printf("Element inserted\n");
break;
case 5:
printf("Displaying the list....\n");
display();
break;
case 6:
printf("\nExiting the program\n");
exit(0);
break;
default:
printf("Wrong choice");
}
}
return 0;
}