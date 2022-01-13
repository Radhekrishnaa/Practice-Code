#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number,guess,nguesses =1;
    srand(time(0));
    number = rand()%100+1;
    //printf("The number is %d\n",number);

    do
    {
        printf("GUESS the number from 1 to 100\n:");
        scanf("%d",&guess);

        if(guess>number)
        {
         printf("Enter a lower number!\n");
        }
        else if(guess<number){
            printf("Enter a higher number!\n");
        }
        else{
            printf("Congratulations ! you have guessed number in %d attempts\n",nguesses);
        }nguesses++;
    } while (guess!=number);
    
   

    return 0 ;
}