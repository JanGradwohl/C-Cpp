#include "Random.h"
#include <ctime>        // für time(0)
#include <cstdlib>      // für srand und rand

Random::Random()
{
	srand(time(0));
}

int Random::Next()
{
	return (rand());    // Gibt zurück was rand zurückgibt
}

int Random::Next(int max)
{
	return(rand() % max);
}

int Random::Next(int min, int max)    // >= min && < max
{
	// z.B. min = -50, max=100
	int bereich = max - min;
	return((rand() % bereich) + min);      // 0 .. RAND_MAX (32767)	
}
