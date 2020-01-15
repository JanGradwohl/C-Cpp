
#include <stdio.h>
#include <string.h>

#define ZEILEN  10
#define SPALTEN 10

void init_matrix(char m[ZEILEN][SPALTEN]) 
{
	// ihr code hier
}

void print_matrix(char m[ZEILEN][SPALTEN]) 
{
	for (int x = 0; x < SPALTEN - 1; x++) {   // gehe durch alle Zeilen
			printf("%c", m[0][x]);
	}
}

// Testet, ob die matrix an jeder Stelle eine '1' hat
// returns 0 = nein
// returns 1 = ja
int test_matrix(char m[ZEILEN][SPALTEN]) 
{

}
/* Beispiel zum Arbeiten mit mehrdimensionalen Arrays */

// Hausübung: 
//            Array [10][10] wird initialisiert mit '0'
//            Benutzer gibt eine zweistellige Zahl ein 
//            erste Ziffer = Zeile, zweite Ziffer = Spalte
//            an die Stelle [zeile][spalte] wird eine '1' geschrieben
//            Programm wird beendet wenn alle Stellen eine '1' enthalten

void main()
{
	char matrix[ZEILEN][SPALTEN];   // 10 Zeilen (0-9) und 20 Spalten (0-19)

	// Beispiele für den Zugriff
	matrix[0][0] = 'A';   // "links oben"
	matrix[ZEILEN-1][SPALTEN-1] = 'Z';  // "rechts unten"

	// Beispiel zur Initialisierung
	for (int x = 0; x < SPALTEN; x++) {
		matrix[0][x] = '0';
	}

	print_matrix(matrix);

	getchar();
	getchar();

}


/* Zeichen ersetzen und manueller 0-Abschluss */
void main2()
{
	char input[255];
	char output[255*2];

	int output_idx = 0;   // zeigt auf die nächste leere Stelle

	gets_s(input, 255);

	// 1:1 Kopie
	for (int i = 0; i < strlen(input); i++) {
		int zeichen = (int)input[i];   // Trick, um "negative" Zeichen (ASCII > 128) zu erhalten
		
		switch( zeichen ) {
		case -31:         // -31 = ß (obwohl VS -33 sagt)
			output[output_idx] = 's';
			output_idx++;
			output[output_idx] = 's';
			output_idx++;
			output[output_idx] = 's';
			output_idx++;
			output[output_idx] = 's';
			output_idx++;
			break;
		case -124:  // -124 = ä 
			output[output_idx] = 'a';
			output_idx++;
			output[output_idx] = 'e';
			output_idx++;
			break;
		default:
			output[output_idx] = input[i];
			output_idx++;
		}
	}

	output[output_idx] = '\0';  // string-Abschluss

	 


	printf("Output = %s\n", output);

	getchar();
	getchar();

}



/* Fingerübungen mit SChleifen usw. */
void main01()
{
	unsigned int MAX, j;

	do {
		printf("Bitte geben Sie den MAX-Wert ein:");
		scanf_s("%d", &MAX);

		//for (size_t i = 1; i <= MAX; i++) 
		//{
		//	printf("%d\t%d\n", i,MAX-i+1);
		//}
		int i = 1;
		while (i <= MAX) {
			printf("%d\t%d\n", i, MAX - i + 1);
			i++;
		}
	} while (MAX != 0);

	getchar();
	getchar();
}