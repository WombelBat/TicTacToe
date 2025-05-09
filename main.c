#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAME_Lenght 3
#define BOARD_LENGHT 13

char *createSpace(int poz, char Xchar, char Ochar)
{
  char *space = (char *)malloc(sizeof(char) * (GAME_Lenght + 1));

  // printf("its poz = %d \n", poz);
  space[0] = '|';
  space[1] = ' ';
  if (poz == -1)
  {
    // printf("it was O\n");

    space[2] = Ochar;
  }
  else if (poz == 1)
  {
    // printf("it was XXXX\n");

    space[2] = Xchar;
  }
  else
  {
    // printf("it was empty\n");

    space[2] = '-';
  }
  space[3] = ' ';

  return space;
}

char *contstructGameRow(const int gamePoz[9], const int start, const int end, char Xchar, char Ochar)
{
  int rowLenght = sizeof(char) * (GAME_Lenght) * 3 + 3 + 1;
  char *row = (char *)malloc(rowLenght);
  for (int i = start; i < end; i++)
  {
    // printf("%d %d \n", i, gamePoz[i]);

    strcat(row, createSpace(gamePoz[i], Xchar, Ochar));
  }
  row[rowLenght - 1] = '|';
  row[rowLenght] = '\n';
  return row;
}

void consructSegementOfBoard(char *gameboard, const int gamePoz[9], const int start, const int end, char Xchar, char Ochar)
{
  char rowPrint[] = {"_____________\n"};
  int rowLenght = strlen(rowPrint);
  strcat(gameboard, rowPrint);
  strcat(gameboard, contstructGameRow(gamePoz, start, end, Xchar, Ochar));
}

char *constructBoard(const int gamePoz[9], char Xchar, char Ochar)
{
  char *gameboard = (char *)malloc((BOARD_LENGHT + BOARD_LENGHT - 1) * 3 + BOARD_LENGHT + 10);
  for (int i = 0; i < 3; i++)
  {
    consructSegementOfBoard(gameboard, gamePoz, i * 3, (i + 1) * 3, Xchar, Ochar);
  }
  char rowPrint[] = {"_____________\n"};
  strcat(gameboard, rowPrint);
}

int checkValidity(int poz[9], int choice)
{
  int cor = 1;
  for (int i = 0; i < 9; i++)
  {
    if (!poz[i])
      cor = 0;
  }

  return cor;
}

void moveX(int *poz[9], int xORo, char x)
{
  int choice;
  do
  {
    printf("Enter a number from 1 to 9 representing the position of your charecter: ");
    scanf("%d", &choice);
    if (checkValidity(*poz, choice))
    {
      printf("\n space is ocupied renter ");
    }
  } while (checkValidity(*poz, choice));
  if (xORo)
  {
    *poz[choice] = 1;
  }
  else
  {
    *poz[choice] = -1;
  }
}
void ticTacToeGame()
{
  printf("Start of game:\n");
  char x = 'X'; // not -
  char o = 'O'; // not -
  int poz[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  char *game = constructBoard(poz, x, o);
  printf("%s\n", game);

  printf("Player starts first and is %c: ", x);
  printf("Enter a number from 1 to 9 representing the position of your charecter: ");
}
int main()
{
  printf("Start of game:\n");
  char c[] = {"_____________"};
  char x = 'X';
  char o = 'O';
  int poz[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

  char *game = constructBoard(poz, x, o);
  printf("%s \n %ld %d\n", game, strlen(game), (BOARD_LENGHT + BOARD_LENGHT - 1) * 3 + BOARD_LENGHT + 10);
  // printf("%s\n%ld", c, strlen(c));
  return 0;
}
