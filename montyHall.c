#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "montyHall.h"

int main()
{
  int thisNum;

  thisNum = randInt(3);
  printf("thisNum = %d\n", int);
  return EXIT_SUCCESS;
}

int playGame(int knows)
{
  int carDoor;
  int playerDoor;
  int hostDoor;

  return 0;
}

int randInt(int max)
{
  int temp; // holds the initial number between 0 and RAND_MAX
  int randNum; // the return value
  int i; // a counter within the for loop
  
  srand(time(NULL));
  temp = rand();
  randNum = 0; // initially assumed that randNum is zero

  for (i = max - 1; i > 0; i--)
    {
      if (temp > ((i * MAX_RAND) / max))
	{
	  randNum = i;
	  i = 0;
	}
    }

  return randNum;
}
