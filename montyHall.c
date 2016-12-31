#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "montyHall.h"

int main(int argc, char * argv[])
{
  int i; // a counter variable
  int numChanges = 0; // the number of times the contestant should have changed
  int numStays = 0; // the number of times the contestant should have switched
  int numCars = 0; // the number of times the host reveals the car
  int result; // the result of an individual run
  float changePer;
  float stayPer;
  float carPer;

  char input;
  int knows = -1; // whether the host knows where the car is
  int numSims = -1;

  if (argc == 3)
    {
      knows = atoi(argv[1]);
      numSims = atoi(argv[2]);
    }
  else if (argc == 1)
    {
      getInput(&knows, &numSims);
    }
  srand(time(NULL));
  for (i = 0; i < numSims; i++)
    {
      result = playGame(knows);
      if (result == CHANGE)
	{
	  numChanges++;
	}
      else if (result == STAY)
	{
	  numStays++;
	}
      else
	{
	  numCars++;
	}
    }

  changePer = (float) numChanges / numSims;
  stayPer = (float) numStays / numSims;
  carPer = (float) numCars / numSims;
  
  printf("Contestant should switch = %.3f\n", changePer);
  printf("Contestant should stay = %.3f\n", stayPer);
  printf("Host reveals car = %.3f\n", carPer);
  return EXIT_SUCCESS;
}

int playGame(int knows)
{
  int carDoor; // the door with the car
  int playerDoor; // the door that the player chooses
  int hostDoor; // the door that the host opens

  carDoor = rand() % 3;
  playerDoor = rand() % 3;
  do
    {
      hostDoor = rand() % 3;
    } while (hostDoor == playerDoor || (knows && hostDoor == carDoor));
  
  if (playerDoor == carDoor)
    {
      return STAY;
    }
  else if (hostDoor == carDoor)
    {
      return CAR;
    }
  else
    {
      return CHANGE;
    }
}

void getInput(int * knows, int * numSims)
{
  char input[1];

  *knows, *numSims = -1;
  do
    {
      printf("Does the host know which door contains the car? (y/n): ");
      scanf("%s", input);
      if (input[0] == 'y' || input[0] == 'Y')
	{
	  *knows = 1;
	}
      else if (input[0] == 'n' || input[0] == 'N')
	{
	  *knows = 0;
	}
      else
	{
	  printf("You did not enter a valid character.\n");
	}
    } while (*knows == -1);

  do
    {
      printf("How many simulations would you like to run?: ");
      scanf("%d", numSims);
      if (*numSims <= 0)
	{
	  printf("Please enter an integer greater than 0.\n");
	}
    } while (*numSims <= 0);

  return;
}
