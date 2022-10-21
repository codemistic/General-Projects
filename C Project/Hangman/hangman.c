#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int guess, number, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    do{
        printf("Guess the number (1 to 100): ");
        scanf("%d", &guess);
        tries++;
        if(guess > number){
            printf("\nLower number please!\n");
        }else if(guess < number){
            printf("\nHigher number please!\n");
        }else{
            printf("\nCongrats! You guessed it in %d tries!", tries);
        }
    }while(guess != number);
    return 0;
}