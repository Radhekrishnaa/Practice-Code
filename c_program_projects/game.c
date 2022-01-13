#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int choice(char you,char computer){
   if(you==computer)
   return -1;
   if(you=='s'&&computer=='p')
   return 0;
   if(you=='p'&&computer=='s')
   return 1;
   if(you=='z'&&computer=='s')
   return 0;
   if(you=='s'&&computer=='z')
   return 1;
   if(you=='p'&&computer=='z')
   return 0;
   if(you=='z'&&computer=='p')
   return 1;
}
int main(){
    int number;
    char you,computer,result;
    srand(time(0));
    number = rand()%100;
    printf("\n\n\t\t******WELCOME******");
    printf("\nEnter your choice :\n 'p' for paper , 's' for stone,'z' for scissor.\n");
    scanf("%c",&you);
    if(number<33){
      computer= 'p';
    }
    
     else if(number>33&number<66){
        computer= 's';
    }
    else 
    computer= 'z';
    result=choice(you,computer);
    if(result==-1)
    printf("The match is draw!\n");
    else if(result==1)
    printf("You won!\n");
    else
    printf("YOu lose :(\n");
    printf("You choose %c and the computer choose %c",you,computer);
    return 0;
}