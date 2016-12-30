#define SWTICH 1 // the contestant should have switched
#define STAY 0 // the contestant should have stayed
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
 * randInt will generate a random integer greater than or equal to zero and less
 * than max.
 */
int randInt(int max);
