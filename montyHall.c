#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "montyHall.h"

#define NUM_SIMS 1000000

int main()
{
  int i; // a counter variable
  int numChanges = 0; // the number of times the contestant should have changed
  int numStays = 0; // the number of times the contestant should have switched
  int numCars = 0; // the number of times the host reveals the car
  int result; // the result of an individual run
  float changePer;
  float stayPer;
  float carPer;

  int knows = 0; // whether the host knows where the car is
  
  srand(time(NULL));
  for (i = 0; i < NUM_SIMS; i++)
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

  changePer = (float) numChanges / NUM_SIMS;
  stayPer = (float) numStays / NUM_SIMS;
  carPer = (float) numCars / NUM_SIMS;
  
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
