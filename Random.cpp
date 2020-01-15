#include "Random.h"
#include <ctime>        // f�r time(0)
#include <cstdlib>      // f�r srand und rand

Random::Random()
{
	srand(time(0));
}

int Random::Next()
{
	return (rand());    // Gibt zur�ck was rand zur�ckgibt
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
