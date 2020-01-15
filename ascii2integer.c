#include <stdio.h>
#include <string.h>
#include <math.h>


/*
	Implementieren Sie eine Funktion die einen string (char [])bekommt
	und testet ob dieser string nur aus Ziffernzeichen ('0'..'9')besteht.
	Name: isNumber
	Input   : char[] mit '\0' - Terminierung
	Rückgabe: int 1 falls ja (alles Ziffern)
	          int 0 falls nein  (Buchstabe, Sonderzeichen usw. gefunden
*/
int isNumber(char in[]) {

	for (int i = 0; i < strlen(in); i++) {
		if(in[i] <'0' || in[i] > '9' )
		{
			return 0;
		}
	}
	return 1;
}

/*
	Funktion: Ascii2Int
	Input   : ein char[] mit '\0' - Terminierung, nur positive Zahlen
	Ouput   : int als Werte des Input-Arrays

	Falls in der Eingabe auch Nicht-Ziffern gefunden werden, soll
	die Funktione eine Fehlertext ausgeben und -1 zurückgeben

*/
int Ascii2Int(char in[]) 
{
	int summe = 0;

	if (isNumber(in) == 0) {
		printf("Nur Ziffern sind erlaubt !\n");
		return -1;
	}
	// else
	for (int i = 0; i < strlen(in); i++) {
		summe = summe + (in[i] - 48) * pow(10.0, (double)(strlen(in)-1-i));  // "casting"
	}

	return summe;

}

int main()
{
	char eingabe[10];

	printf("Ihr Eingabewert (als Text):");
	gets_s(eingabe, 10);

	int wert = Ascii2Int(eingabe); 

	printf("\"%s\" = %d\n", eingabe, wert);

	getchar();
	getchar();
}