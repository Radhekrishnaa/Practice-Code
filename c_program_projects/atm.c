#include<stdio.h>

int main(){
   float x ,y;//x is a intial amount for ones account and y is input 
   int ch;//ch is for taking a input of choice for doing task
   printf("\n\t\t******WELCOME IN DIGITAL ATM*********\n\n");
    printf("\t\tEnter a intial amount for your account\nRS:");

    scanf("%f",&x);
    // printf("\t\t You have a  amount \" RS,%f  \" for your account\n",x);
  //  printf("\t\t What u want to further carry out ");
   choice:
    printf("\t\t MENU: \n For Credit - 1 ,\n For Debit - 2 ,\n For Balance enquiry - 3, \nFor Exit - 4\n");
   printf("You want to carry out : \n ");
    scanf("\n%d", &ch);
    if(ch > 4){
      printf("\tPlease enter a valid number !\n");
  goto choice;
    }
    switch(ch){
    case 1:
    printf("\tEnter the amount u want to credit : \n RS:");
    scanf("\n%f",&y);
    x=x+y;
    printf("\tYour new account balance is  :RS:%f\n \t\tTHANKYOU !\n",x);
    break;
    case 2:
    printf("\tEnter the the amount u want to debit : \nRS:");
    scanf("\n%f",&y);
    
    if(x>=y){
    x=x-y;
    printf("\t Your current account balance is=RS:%f\n\t\tTANKYOU! \n",x);

    }
    else{
        printf("\tYour account has insufficient balance\n");
    }
    break;
    case 3:
    printf("\tYour account balance :RS:%f\n \n\t]\tTHANKYOU!\n",x);
  break;
  case 4 :
  printf("\t THANKYOU!\n \tYour session has been ended\n");
  break;
  default:
  printf("OPPS ! you have done something wrong\n THANKYOU! try again\n");
 
    }
    
    return 0 ;
}