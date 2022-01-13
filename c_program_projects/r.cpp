#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
int usrScore = 0, compScore = 0;
#include <iostream>
using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x, int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();
int checkwin();
void board();
int main1();
int main2();
int main3();
int main4();
int option1();
char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct coordinate1
{
 int x;
 int y;
 int direction;
};
typedef struct coordinate1 coordinate2;
coordinate2 head, bend[500], food, body[30];

int option1()
{
    int option;
 do
 {
        printf("1. Tic tak toe game \n");
        printf("2. Snake game \n");
        printf("3. Zodiac sign game \n");
        printf("4. Rock, Paper & Scissor Game \n");
        printf("\nEnter your option: ");
  scanf("%d", &option);
  switch (option)
  {
  case 1:
   printf("Tic Tak toe \n");
   main1();
   break;
  case 2:
   printf("Snake game \n");
   main2();
   break;
  case 3:
   printf("Zodiac sign game \n");
   main3();
   break;
  case 4:
   printf("Rock, Paper & Scissor Game \n");
   main4();
   break;
  default:
   break;
  }
 }while( option != 5);
 return 0;
}

int main()
{
option1();
}
//Snake game in c*************************************************************************************************

int main2()
{
 char key;
 Print();
 system("cls");
 load();                                                  
 length = 5;               
 head.x = 25;
 head.y = 20;
 head.direction = RIGHT;
 Boarder();
 Food(); //to generate food coordinates initially
 life = 3; //number of extra lives
 bend[0] = head;
 Move(); //initialing initial bend coordinate
 return 0;
}
void Move()
{
 int a, i;
 do
 {
  Food();
  fflush(stdin);
  len = 0;
  for (i = 0; i < 30; i++)
  {
   body[i].x = 0;
   body[i].y = 0;
   if (i == length)
    break;
  }
  Delay(length);
  Boarder();
  if (head.direction == RIGHT)
   Right();
  else if (head.direction == LEFT)
   Left();
  else if (head.direction == DOWN)
   Down();
  else if (head.direction == UP)
   Up();
  ExitGame();
 } while (!kbhit());
 a = getch();
 if (a == 27)
 {
  system("cls");
  exit(0);
 }
 key = getch();
 if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) || (key == LEFT && head.direction != RIGHT && head.direction != LEFT) || (key == UP && head.direction != DOWN && head.direction != UP) || (key == DOWN && head.direction != UP && head.direction != DOWN))
 {
  bend_no++;
  bend[bend_no] = head;
  head.direction = key;
  if (key == UP)
   head.y--;
  if (key == DOWN)
   head.y++;
  if (key == RIGHT)
   head.x++;
  if (key == LEFT)
   head.x--;
  Move();
 }
 else if (key == 27)
 {
  system("cls");
  exit(0);
 }
 else
 {
  printf("\a");
  Move();
 }
}
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y)
{
 HANDLE a;
 COORD b;
 fflush(stdout);
 b.X = x;
 b.Y = y;
 a = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(a, b);
}
void load()
{
 int row, col, r, c, q;
 gotoxy(36, 14);
 printf("loading...");
 gotoxy(30, 15);
 for (r = 1; r <= 20; r++)
 {
  for (q = 0; q <= 100000000; q++)
   ; //to display the character slowly
  printf("%c", 177);
 }
 getch();
}
void Down()
{
 int i;
 for (i = 0; i <= (head.y - bend[bend_no].y) && len < length; i++)
 {
  GotoXY(head.x, head.y - i);
  {
   if (len == 0)
    printf("v");
   else
    printf("*");
  }
  body[len].x = head.x;
  body[len].y = head.y - i;
  len++;
 }
 Bend();
 if (!kbhit())
  head.y++;
}
void Delay(long double k)
{
 Score();
 long double i;
 for (i = 0; i <= (10000000); i++)
  ;
}
void ExitGame()
{
 int i, check = 0;
 for (i = 4; i < length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
 {
  if (body[0].x == body[i].x && body[0].y == body[i].y)
  {
   check++; //check's value increases as the coordinates of head is equal to any other body coordinate
  }
  if (i == length || check != 0)
   break;
 }
 if (head.x <= 10 || head.x >= 70 || head.y <= 10 || head.y >= 30 || check != 0)
 {
  life--;
  if (life >= 0)
  {
   head.x = 25;
   head.y = 20;
   bend_no = 0;
   head.direction = RIGHT;
   Move();
  }
  else
  {
   system("cls");
   printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
   record();
   exit(0);
  }
 }
}
void Food()
{
 if (head.x == food.x && head.y == food.y)
 {
  length++;
  time_t a;
  a = time(0);
  srand(a);
  food.x = rand() % 70;
  if (food.x <= 10)
   food.x += 11;
  food.y = rand() % 30;
  if (food.y <= 10)
   food.y += 11;
 }
 else if (food.x == 0) //to create food for the first time coz global variable are initialized with 0
 {
  food.x = rand() % 70;
  if (food.x <= 10)
   food.x += 11;
  food.y = rand() % 30;
  if (food.y <= 10)
   food.y += 11;
 }
}
void Left()
{
 int i;
 for (i = 0; i <= (bend[bend_no].x - head.x) && len < length; i++)
 {
  GotoXY((head.x + i), head.y);
  {
   if (len == 0)
    printf("<");
   else
    printf("*");
  }
  body[len].x = head.x + i;
  body[len].y = head.y;
  len++;
 }
 Bend();
 if (!kbhit())
  head.x--;
}
void Right()
{
 int i;
 for (i = 0; i <= (head.x - bend[bend_no].x) && len < length; i++)
 {
  //GotoXY((head.x-i),head.y);
  body[len].x = head.x - i;
  body[len].y = head.y;
  GotoXY(body[len].x, body[len].y);
  {
   if (len == 0)
    printf(">");
   else
    printf("*");
  }
  /*body[len].x=head.x-i;
        body[len].y=head.y;*/
  len++;
 }
 Bend();
 if (!kbhit())
  head.x++;
}
void Bend()
{
 int i, j, diff;
 for (i = bend_no; i >= 0 && len < length; i--)
 {
  if (bend[i].x == bend[i - 1].x)
  {
   diff = bend[i].y - bend[i - 1].y;
   if (diff < 0)
    for (j = 1; j <= (-diff); j++)
    {
     body[len].x = bend[i].x;
     body[len].y = bend[i].y + j;
     GotoXY(body[len].x, body[len].y);
     printf("*");
     len++;
     if (len == length)
      break;
    }
   else if (diff > 0)
    for (j = 1; j <= diff; j++)
    {
     GotoXY(bend[i].x, (bend[i].y - j));
     printf("");
     body[len].x = bend[i].x;
     body[len].y = bend[i].y - j;
     GotoXY(body[len].x, body[len].y);
     printf("*");
     len++;
     if (len == length)
      break;
    }
  }
  else if (bend[i].y == bend[i - 1].y)
  {
   diff = bend[i].x - bend[i - 1].x;
   if (diff < 0)
    for (j = 1; j <= (-diff) && len < length; j++)
    {
     GotoXY((bend[i].x + j), bend[i].y);
     printf("");
     body[len].x = bend[i].x + j;
     body[len].y = bend[i].y;
     GotoXY(body[len].x, body[len].y);
     printf("*");
     len++;
     if (len == length)
      break;
    }
   else if (diff > 0)
    for (j = 1; j <= diff && len < length; j++)
    {
     GotoXY((bend[i].x - j), bend[i].y);
     printf("");
     body[len].x = bend[i].x - j;
     body[len].y = bend[i].y;
     GotoXY(body[len].x, body[len].y);
     printf("*");
     len++;
     if (len == length)
      break;
    }
  }
 }
}
void Boarder()
{
 system("cls");
 int i;
 GotoXY(food.x, food.y); //displaying food//
 printf("0");
 for (i = 10; i < 71; i++)
 {
  GotoXY(i, 10);
  printf("!");
  GotoXY(i, 30);
  printf("!");
 }
 for (i = 10; i < 31; i++)
 {
  GotoXY(10, i);
  printf("!");
  GotoXY(70, i);
  printf("!");
 }
}
void Print()
{
 //GotoXY(10,12);
 printf("\tWelcome to the Snake game.(press any key to continue)\n");
 getch();
 system("cls");
 printf("\tGame instructions:\n");
 printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
 printf("\n\nPress any key to play game...");
 if (getch() == 27)
  exit(0);
}
void record()
{
 char plname[20], nplname[20], cha, c;
 int i, j, px;
 FILE *info;
 info = fopen("record.txt", "a+");
 getch();
 system("cls");
 printf("Enter your name\n");
 scanf("%s\n]", plname);
 //********
 for (j = 0; plname[j] != '\0'; j++)
 { //to convert the first letter after space to capital
  nplname[0] = toupper(plname[0]);
  if (plname[j - 1] == ' ')
  {
   nplname[j] = toupper(plname[j]);
   nplname[j - 1] = plname[j - 1];
  }
  else
   nplname[j] = plname[j];
 }
 nplname[j] = '\0';
 //***********
 //sdfprintf(info,"\t\t\tPlayers List\n");
 fprintf(info, "Player Name :%s\n", nplname);
 //for date and time
 time_t mytime;
 mytime = time(NULL);
 fprintf(info, "Played Date:%s", ctime(&mytime));
 //**********
 fprintf(info, "Score:%d\n", px = Scoreonly()); //call score to display score
                                                // fprintf(info,"\nLevel:%d\n",10);//call level to display level
 for (i = 0; i <= 50; i++)
  fprintf(info, "%c", '_');
 fprintf(info, "\n");
 fclose(info);
 printf("wanna see past records press 'y'\n");
 cha = getch();
 system("cls");
 if (cha == 'y')
 {
  info = fopen("record.txt", "r");
  do
  {
   putchar(c = getc(info));
  } while (c != EOF);
 }
 fclose(info);
}
int Score()
{
 int score;
 GotoXY(20, 8);
 score = length - 5;
 printf("SCORE : %d", (length - 5));
 score = length - 5;
 GotoXY(50, 8);
 printf("Life : %d", life);
 return score;
}
int Scoreonly()
{
 int score = Score();
 system("cls");
 return score;
}
void Up()
{
 int i;
 for (i = 0; i <= (bend[bend_no].y - head.y) && len < length; i++)
 {
  GotoXY(head.x, head.y + i);
  {
   if (len == 0)
    printf("^");
   else
    printf("*");
  }
  body[len].x = head.x;
  body[len].y = head.y + i;
  len++;
 }
 Bend();
 if (!kbhit())
  head.y--;
}
/* End of snake game **********************************************************************************************/

// Tic tak toe *****************************************************************************************************

#include <iostream>
using namespace std;

// char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();

int main1()
{
    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);
    board();
    if (i == 1)
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
    return 0;
}
/*****
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
******/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
/*********
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********/

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "      |     |     " << endl;
    cout << "  " << square[1] << "   |  " << square[2] << "  |  " << square[3] << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "  " << square[4] << "   |  " << square[5] << "  |  " << square[6] << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "  " << square[7] << "   |  " << square[8] << "  |  " << square[9] << endl;
    cout << "      |     |     " << endl
         << endl;
}
/*********
                *end of project Tic tak toe **********************************************************************
********/

//Zodiac sign
//*******----ZODIAC_SIGN----**********
#include <stdio.h>
#include <stdlib.h>
int main3()
{
    int month, day, menu, error; //It was storing the data input from user
    int flag;                    //The flag is to check whether bday entered is correct or not
    int choice;                  //To have choice to run the program or not
    char name[50];
    system("COLOR E");
    printf("\n\n\t\t\t**** WELCOME ****\n");
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
        // exit(0);
        // option1();
        break;
    default:
        printf("\t\t\t\t**ERROR**");
        system("COLOR C");
        printf("\t\t\tYou have selected wrong option\n RETRY\n");
        goto MENU;
        break;
    }
    system("COLOR B");
    if (menu == 1)
    {
        printf("\t\t\tEnter your name \n:");           //For having the name of user
        scanf("%s", name);                             //Taking the input of user
        printf("\t\t\tENTER your birth day(date)\n:"); //For having the birthday date
        scanf("%d", &day);
        printf("\t\t\tENTER your birth month (number)\n:"); //For having the birthday
        scanf("%d", &month);
    }
    if ((month <= 12 && month > 0) && (day <= 31 && day > 0))
    { //For checking if the entered details are correct or not
        flag = 1;
    }
    else
    { //For displaying the erroe msg after the wrong details filled
        printf("\n\t\t***ERROR*\n");
        printf("\tYou have entered wrong details\n");
        flag = 0;
    }
    system("COLOR F");
    while (flag == 1)
    { //Logic of identifying the zodiac sign of users
        system("COLOR D");
        if (month == 3 && day >= 21 || month == 4 && day <= 19)
        {
            printf("\t\n\t\t\t%s : *'ARIES'* is your zodiac sign\n", name);
            printf("\t\t\t(March 21 - April 19)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Ram \n\t\t\tRuling Planet: MARS\n");
            printf("\t\t\tKey Traits: Competitive, energetic, impulsive, fearless\n");
        }
        if (month == 4 && day >= 20 || month == 5 && day <= 20)
        {
            printf("\t\n\t\t\t%s : *'TAURUS'* is your zodiac sign\n", name);
            printf("\t\t\t(April 20 - May 20)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Bull  \n\t\t\tRuling Planet: VENUS");
            printf("\t\t\tKey Traits: Resolute, grounded, tenacious, sensual\n");
        }
        if (month == 5 && day >= 21 || month == 6 && day <= 20)
        {
            printf("\t\n\t\t\t%s : *'GEMINI'* is your zodiac sign\n", name);
            printf("\t\t\t(May 21- June 20)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Twins \n\t\t\tRuling Planet: Mercury\n");
            printf("\t\t\tKey Traits: Witty, curious, charming, flighty\n");
        }
        if (month == 6 && day >= 21 || month == 7 && day <= 22)
        {
            printf("\t\n\t\t\t%s : *'CANCER'* is your zodiac sign\n", name);
            printf("\t\t\t(June 21 - July 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Crab \n\t\t\tRuling Planet: Moon\n");
            printf("\t\t\tKey Traits: Compassionate, giving, sentimental, nurturing\n");
        }
        if (month == 7 && day >= 23 || month == 8 && day <= 22)
        {
            printf("\t\n\t\t\t%s : *'LEO'* is your zodiac sign\n", name);
            printf("\t\t\t(July 23 - August 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Lion \n\t\t\tRuling Planet: Sun\n");
            printf("\t\t\tKey Traits: Charismatic, generous, optimistic, dramatic\n");
        }
        if (month == 8 && day >= 23 || month == 9 && day <= 22)
        {
            printf("\t\n\t\t\t%s : *'VIRGO'* is your zodiac sign\n", name);
            printf("\t\t\t(August - 23 and September - 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Virgin or Maiden \n\t\t\tRuling Planet: Mercury\n");
            printf("\t\t\tKey Traits: Health-conscious, analytical, service-oriented, detail-focused\n");
        }
        if (month == 9 && day >= 23 || month == 10 && day <= 22)
        {
            printf("\t\n\t\t\t%s : *'LIBRA'* is your zodiac sign\n", name);
            printf("\t\t\t(September 23 - October 22)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Scales \n\t\t\tRuling Planet: Venus\n");
            printf("\t\t\tKey Traits: Romantic, artistic, indecisive, diplomatic\n");
        }
        if (month == 10 && day >= 23 || month == 11 && day <= 21)
        {
            printf("\t\n\t\t\t%s : *'SCORPIO'* is your zodiac sign\n", name);
            printf("\t\t\t(October 23 - November 21)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Scorpion \n\t\t\tRuling Planets: Pluto and Mars\n");
            printf("\t\t\tKey Traits: Mysterious, magnetic, power-seeking, spiritual\n");
        }
        if (month == 11 && day >= 22 || month == 12 && day <= 21)
        {
            printf("\t\n\t\t\t%s : *'SAGITTARIUS'* is your zodiac sign\n", name);
            printf("\t\t\t(November 22 - December 21)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Archer \n\t\t\tRuling Planet: Jupiter\n");
            printf("\t\t\tKey Traits: Philosophical, free-spirited, unfiltered, wanderlusting\n");
        }
        if (month == 12 && day >= 22 || month == 1 && day <= 19)
        {
            printf("\t\n\t\t\t%s : *'CAPRICON'* is your zodiac sign\n", name);
            printf("\t\t\t(December 22 - January 19)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Goat \n\t\t\tRuling Planet: Saturn\n");
            printf("\t\t\tKey Traits: Traditional, down-to-earth, industrious, disciplined \n");
        }
        if (month == 1 && day >= 20 || month == 2 && day <= 18)
        {
            printf("\t\n\t\t\t%s : *'AQUARIUS'* is your zodiac sign\n", name);
            printf("\t\t\t(January 20 - February 18)is within which this zodiac sign lies\n");
            printf("\t\t\tSymbol: The Water Bearer \n\t\t\tRuling Planet: Uranus\n");
            printf("\t\t\tKey Traits: Humanitarian, eccentric, individualistic, cool\n");
        }
        if (month == 2 && day >= 19 || month == 3 && day <= 20)
        {
            printf("\t\n\t\t\t%s : *'PISCES'* is your zodiac sign\n", name);
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
    printf("\n\n\t\t\t-----------------------*****-------------------BY Radhe\n");
    return 0;
}
/*End of Zodiac sign ***********************************************************************************************/

//Paper stone scissor*************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// int usrScore = 0, compScore = 0;
void checkOptions(int usr, int comp)
{
    // 1 = scissor 2= paper 3=rock
    if (usr == comp)
    {
        printf(" --------------------\n");
        printf("|    Its a tie       |\n");
        printf(" --------------------\n");
    }
    else if (usr == 1)
    {
        if (comp == 2)
        {
            printf(" --------------------\n");
            printf("|      You Won :)    |\n");
            printf("| You : Scissor      |\n");
            printf("| Computer : Paper   |\n");
            printf(" --------------------\n");
            usrScore++;
        }
        else
        {
            printf(" --------------------\n");
            printf("|     You Lose :(    |\n");
            printf("| You : Scissor      |\n");
            printf("| Computer : Rock    |\n");
            printf(" --------------------\n");
            compScore++;
        }
    }
    else if (usr == 2)
    {
        if (comp == 1)
        {
            printf(" --------------------\n");
            printf("|      You Lose :(   |\n");
            printf("| You : Paper        |\n");
            printf("| Computer : Scissor |\n");
            printf(" --------------------\n");
            compScore++;
        }
        else
        {
            printf(" --------------------\n");
            printf("|     You Won :)     |\n");
            printf("| You : Paper        |\n");
            printf("| Computer : Rock    |\n");
            printf(" --------------------\n");
            usrScore++;
        }
    }
    else if (usr == 3)
    {
        if (comp == 1)
        {
            printf(" --------------------\n");
            printf("|      You Won :)    |\n");
            printf("| You : Rock        |\n");
            printf("| Computer : Scissor |\n");
            printf(" --------------------\n");
            usrScore++;
        }
        else
        {
            printf(" --------------------\n");
            printf("|     You Lose :(    |\n");
            printf("| You : Rock         |\n");
            printf("| Computer : Paper    |\n");
            printf(" --------------------\n");
            compScore++;
        }
    }
    else if (usr == 4)
    {
        printf(" --------------------\n");
        if (usrScore > compScore)
            printf("|      You Won :)    |\n");
        else if (usrScore < compScore)
            printf("|     You Lose :(    |\n");
        else
            printf("|      Its a tie     |\n");
        printf("|     Final Score    |\n");
        printf("| You : %d            |\n", usrScore);
        printf("| Computer: %d        |\n", compScore);
        printf(" --------------------\n");
        printf("\a");
    }
    else
    {
        Beep(750, 500);
        printf("\n Invalid Option");
    }
}
int main4()
{
    int userChoice, compChoice;
    srand(time(0));
    printf("\t\t\t\t==========Welcome to Rock, Paper & Scissor Game==========");
    while (userChoice != 4)
    {
        printf("\nPlease select the option: ");
        printf("\n1.Scissor");
        printf("\n2.Paper");
        printf("\n3.Rock");
        printf("\n4.Quit\n");
        scanf("%d", &userChoice);
        compChoice = (rand() % 3) + 1;
        checkOptions(userChoice, compChoice);
    }
    return 0;
}
