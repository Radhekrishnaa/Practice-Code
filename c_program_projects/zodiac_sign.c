//*********************----ZODIAC_SIGN----****************************
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int month, day, menu, error; //It was storing the data input from user
    int flag; //The flag is to check whether bday entered is correct or not
    int choice;  //To have choice to run the program or not
    char name[50];
     system("COLOR E");
    printf("\n\n\t\t\t********** WELCOME **********\n");
MENU:
    printf("\n\t\t\t* MENU * \n");
    printf("\t\t\t For checking your zodiac sign\n \t\t\t* PRESS * \n \t\t\t(1) For checking your zodiac sign\n \t\t\t(2) For EXIT\n: ");
    scanf("%d", &menu); //For having the option whether to run or not
    
    system("COLOR C");
    switch (menu)
    {
        
    case 1:
        
        printf("\t\t\tYou have selected to check your zodiac sign\n");
            //For the one who selected to check the zodiac
        break;
    case 2:
        
        printf("\t\t\tYou have exited from the menu\n");
        break;
    default:
        
        printf("\t\t\t\t***ERROR***");
        system("COLOR C");
        printf("\t\t\tYou have selected wrong option\n RETRY\n");
        goto MENU;

        break;
    }
    system("COLOR B");
    if (menu == 1)
    {   
        printf("\t\t\tEnter your name \n:");  //For having the name of user
        scanf("%s", name);  //Taking the input of user
        printf("\t\t\tENTER your birth day(date)\n:");  //For having the birthday date
        scanf("%d", &day);
        printf("\t\t\tENTER your birth month (number)\n:");  //For having the birthday
        scanf("%d", &month);
    }
    
    if ((month <= 12 && month > 0) && (day <= 31 && day > 0))
    {   //For checking if the entered details are correct or not
        flag = 1;
    }
    else
    {   //For displaying the erroe msg after the wrong details filled
        printf("\n\t\t****ERROR****\n");
        printf("\tYou have entered wrong details\n");
        
        flag = 0;
    }
    system("COLOR F");

    while (flag == 1)
    {//Logic of identifying the zodiac sign of users
         system("COLOR D");
        if (month == 3 && day >= 21 || month == 4 && day <= 19)
        {   
            printf("\t\n\t\t\t%s : ***'ARIES'*** is your zodiac sign\n", name);
            printf("\t\t\t(March 21 - April 19)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Ram \n\t\t\tRuling Planet: MARS\n");
            printf("\t\t\tKey Traits: Competitive, energetic, impulsive, fearless\n");
        }
        if (month == 4 && day >= 20 || month == 5 && day <= 20)
        {
            printf("\t\n\t\t\t%s : ***'TAURUS'*** is your zodiac sign\n", name);
            printf("\t\t\t(April 20 - May 20)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Bull  \n\t\t\tRuling Planet: VENUS");
            printf("\t\t\tKey Traits: Resolute, grounded, tenacious, sensual\n");
        }
        if (month == 5 && day >= 21 || month == 6 && day <= 20)
        {
            printf("\t\n\t\t\t%s : ***'GEMINI'*** is your zodiac sign\n", name);
            printf("\t\t\t(May 21- June 20)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Twins \n\t\t\tRuling Planet: Mercury\n");
            printf("\t\t\tKey Traits: Witty, curious, charming, flighty\n");
        }
        if (month == 6 && day >= 21 || month == 7 && day <= 22)
        {
            printf("\t\n\t\t\t%s : ***'CANCER'*** is your zodiac sign\n", name);
            printf("\t\t\t(June 21 - July 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Crab \n\t\t\tRuling Planet: Moon\n");
            printf("\t\t\tKey Traits: Compassionate, giving, sentimental, nurturing\n");
        }
        if (month == 7 && day >= 23 || month == 8 && day <= 22)
        {
            printf("\t\n\t\t\t%s : ***'LEO'*** is your zodiac sign\n", name);
            printf("\t\t\t(July 23 - August 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Lion \n\t\t\tRuling Planet: Sun\n");
            printf("\t\t\tKey Traits: Charismatic, generous, optimistic, dramatic\n");
        }
        if (month == 8 && day >= 23 || month == 9 && day <= 22)
        {
            printf("\t\n\t\t\t%s : ***'VIRGO'*** is your zodiac sign\n", name);
            printf("\t\t\t(August - 23 and September - 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Virgin or Maiden \n\t\t\tRuling Planet: Mercury\n");
            printf("\t\t\tKey Traits: Health-conscious, analytical, service-oriented, detail-focused\n");
        }
        if (month == 9 && day >= 23 || month == 10 && day <= 22)
        {
            printf("\t\n\t\t\t%s : ***'LIBRA'*** is your zodiac sign\n", name);
            printf("\t\t\t(September 23 - October 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Scales \n\t\t\tRuling Planet: Venus\n");
            printf("\t\t\tKey Traits: Romantic, artistic, indecisive, diplomatic\n");
        }
        if (month == 10 && day >= 23 || month == 11 && day <= 21)
        {
            printf("\t\n\t\t\t%s : ***'SCORPIO'*** is your zodiac sign\n", name);
            printf("\t\t\t(October 23 - November 21)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Scorpion \n\t\t\tRuling Planets: Pluto and Mars\n");
            printf("\t\t\tKey Traits: Mysterious, magnetic, power-seeking, spiritual\n");
        }
        if (month == 11 && day >= 22 || month == 12 && day <= 21)
        {
            printf("\t\n\t\t\t%s : ***'SAGITTARIUS'*** is your zodiac sign\n", name);
            printf("\t\t\t(November 22 - December 21)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Archer \n\t\t\tRuling Planet: Jupiter\n");
            printf("\t\t\tKey Traits: Philosophical, free-spirited, unfiltered, wanderlusting\n");
        }
        if (month == 12 && day >= 22 || month == 1 && day <= 19)
        {
            printf("\t\n\t\t\t%s : ***'CAPRICON'*** is your zodiac sign\n", name);
            printf("\t\t\t(December 22 - January 19)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Goat \n\t\t\tRuling Planet: Saturn\n");
            printf("\t\t\tKey Traits: Traditional, down-to-earth, industrious, disciplined \n");
        }
        if (month == 1 && day >= 20 || month == 2 && day <= 18)
        {
            printf("\t\n\t\t\t%s : ***'AQUARIUS'*** is your zodiac sign\n", name);
            printf("\t\t\t(January 20 - February 18)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Water Bearer \n\t\t\tRuling Planet: Uranus\n");
            printf("\t\t\tKey Traits: Humanitarian, eccentric, individualistic, cool\n");
        }
        if (month == 2 && day >= 19 || month == 3 && day <= 20)
        {
            printf("\t\n\t\t\t%s : ***'PISCES'*** is your zodiac sign\n", name);
            printf("\t\t\t(February 19 - March 20)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Fish \n\t\t\tRuling Planets: Neptune\n");
            printf("\t\t\tKey Traits: Empathic, artistic, psychic, dreamy\n");
        }
        break;
    }
     system("COLOR 9");
    printf("\n\n\n\t\t\tTHANKYOU! %s\n ", name);
    printf("\n\t\t\tIF you want to check others zodiac sign\n");
    printf("\n\t\t\tThen PRESS:(1) For again trial \n\t\t\t(2) For EXIT\n:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        goto MENU;
    }
    else
    {
        printf("\n\t\t\t THANKYOU\n");
    }
    printf("\n\n\t\t\t-----------------------*************-------------------BY Radhe\n");
    return 0;
    
}
