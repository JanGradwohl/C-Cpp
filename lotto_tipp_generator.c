/*
	Requirements (Anforderungen)

	Version A: Sie generieren einen Lotto-Tipp 6 aus 45
			   --> 6 zufällige Zahlen zw. 1..45, keine Doppelten

	Version B: Benutzer darf eingeben, wieviele Tipps er möchte

	Bsp: 1. Tipp =  6    23  17   4   45   44
		 2. Tipp =  18    6   1   2   37    9
		 usw....

*/

#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(0));

	int merker[46];  // 0..45, 0 wird nicht gebraucht werden
	int tipps;


	printf("Wie viele Tipps: ");
	scanf_s("%d", &tipps);

	for (int y = 0; y < tipps; y++) {
		int anzahl = 0;
		// Initialisierung
		for (int lauf = 0; lauf < 46; lauf++)
			merker[lauf] = 0;

		// merker[x] == 0 .... die zahl x wurde noch nicht verwendet
		// merker[x] == 1 .... die Zahl x wurde schon verwendet
		while (anzahl < 6) {
			int neueZahl = (rand() % 45) + 1;
			//int neueZahl;
			//scanf_s("%d", &neueZahl);

			if (merker[neueZahl] == 0) {
				printf("%d\t", neueZahl);
				merker[neueZahl] = 1;
				anzahl++;
			}
		}
		printf("\n");
	}

	getchar();
	getchar();

}
