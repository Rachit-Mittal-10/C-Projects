// Number Guessing Game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int user_num, comp_num;
    int ctr = 0;

    // Random Number generation
    srand(time(NULL));
    comp_num = rand()%100 + 1;
    
    do{
        printf("Enter The Number: ");
        scanf("%d",&user_num);
        ctr++;

        if(user_num>comp_num){
            printf("Guess Smaller\n");
        }
        else{
            printf("Guess Bigger\n");
        }
    }while(user_num!=comp_num);
    printf("You guessed it in %d attempts",ctr);
    return 0;
}