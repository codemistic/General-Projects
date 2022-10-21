#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int choice;
    float p, r, t, si, ci;
    printf("1. Simple Interest\n");
    printf("2. Compound Amount\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        
        case 1:
            printf("Enter the principal amount: ");
            scanf("%f", &p);
            printf("Enter the rate of interest: ");
            scanf("%f", &r);
            printf("Enter the time period: ");
            scanf("%f", &t);
            
            si = (p * r * t) / 100;
            printf("Simple interest = %.2f", si);
            break;
        
        case 2:
            printf("Enter the principal amount: ");
            scanf("%f", &p);
            printf("Enter the rate of interest: ");
            scanf("%f", &r);
            printf("Enter the time period: ");
            scanf("%f", &t);
            
            ci = p * pow((1 + r / 100), t);
            printf("Compound amount = %.2f", ci);
            break;
        
        default:
            printf("Invalid choice!");
    }
    return 0;
}

    