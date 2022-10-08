// Queue implementation in C  
  
#include <stdio.h>  
#define SIZE_OF_QUEUE 7  
  
void enQueue(int);  
void deQueue();  
void display();  
  
int array_of_Queue[SIZE_OF_QUEUE], front_index = -1, rear_index = -1;  
  
int main() {  
    
  int data;  
    char ch;  
        /*  Perform three operations  */  
        do      
        {  
            printf("\nSelect one of the operations::");  
            printf("\n1. Insert data into the Queue");  
            printf("\n2. Display the data present in the Queue");  
            printf("\n3. Dequeue operation on the Queue\n");  
  
            int choice;  
            scanf("%d",&choice);              
            switch (choice)  
            {  
            case 1 :   
                printf("\nEnter the value to be inserted\n");  
                scanf("%d",&data);  
                enQueue(data);                       
                break;                            
            case 2 :   
                printf("\nContents of the Queue are::\n");  
                display();  
                break;   
            case 3 :   
                printf("\nDequeue Done.\n");  
                deQueue();  
                break;  
            default :   
                printf("Wrong Entry\n");  
                break;     
            }  
  
            printf("\nDo you want to continue (Type y or n)\n");  
            scanf(" %c",&ch);                          
        } while (ch == 'Y'|| ch == 'y');  
  return 0;  
}  
  
void enQueue(int value) {  
  if (rear_index == SIZE_OF_QUEUE - 1)  
    printf("\nQueue is Full!!");  
  else {  
    if (front_index == -1)  
      front_index = 0;  
    rear_index++;  
    array_of_Queue[rear_index] = value;  
    printf("\nInserted -> %d", value);  
  }  
}  
  
void deQueue() {  
  if (front_index == -1)  
    printf("\nQueue is Empty!!");  
  else {  
    printf("\nDeleted : %d", array_of_Queue[front_index]);  
    front_index++;  
    if (front_index > rear_index)  
      front_index = rear_index = -1;  
  }  
}  
  
// Function to print the queue  
void display() {  
  if (rear_index == -1)  
    printf("\nQueue is Empty!!!");  
  else {  
    int i;  
    printf("\nQueue elements are:\n");  
    for (i = front_index; i <= rear_index; i++)  
      printf("%d  ", array_of_Queue[i]);  
  }  
  printf("\n");  
}  
