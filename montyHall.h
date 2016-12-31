#ifndef MONTY_HALL_H_
#define MONTY_HALL_H_

#define CHANGE 1 // the contestant should have changed doors
#define STAY 0 // the contestant should have stayed with the original door
#define CAR -1 // the host revealed the car

/*
 * playGame will perform a single simulation of the game show described in the
 * Monty Hall math problem (see the README for more information). The function
 * takes the parameter "knows", which is true if the host knows which door is
 * in front of the car and false if the host has no more knowledge than the
 * contestant. The function then returns 1 if switching doors would have led
 * to the car and 0 if the car was behind the original door. If the host does
 * not know where the car is, it is possible that the car is revealed when a
 * randomly chosen door is opened. In these cases, the function will return -1.
 */
int playGame(int knows);

/*
 * If the user did not provide command line arguments, getInput will ask the
 * user whether the host knows where the car is and the number of simulations
 * to run. The function will also check the validity of the inputs.
 */
int getInput(int * knows, int * numSims);

#endif
