#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAME_Lenght 3
#define BOARD_LENGHT 13

char *createSpace(int poz, char Xchar, char Ochar)
{
  char *space = (char *)malloc(sizeof(char) * (GAME_Lenght + 1));

  space[0] = '|';
  space[1] = ' ';
  if (poz == 0)
    {
      space[2] = Ochar;
    }
  else
    space[2] = Xchar;
  space[3] = ' ';
  return space;
}

void printBoard(const int gamePoz[9], char Xchar, char Ochar)
{
  char rowPrint[] = {"_____________"};
  int rowLenght = strlen(rowPrint);

  for (int i = rowLenght; i < 7 * rowLenght; i += 2 * rowLenght)
    {
      printf("%s\n", rowPrint);
    }
}

int main()
{
  printf("Start of game:\n");
  char c[] = {"_____________"};

  printf("%s\n%ld", c, strlen(c));
  return 0;
}
