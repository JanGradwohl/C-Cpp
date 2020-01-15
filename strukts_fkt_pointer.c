#include <stdio.h>

typedef struct {
	int tag, monat, jahr;
} Datum;

// Prototypen (Signaturen)
void leer(void);
int gibZufallszahl(void);
double avg3(int z1, int z2, int z3);
Datum datumsEingabe(void);

// Ohne Pointer
Datum nextDay_old(Datum aktualDay);  // call by value

// Funktion "nextDay"
// Input: Pointer auf eine Datums-Struktur !
// Output: int 0  falls alles ok -> Datums-Struktur enthällt dann den nächsten Tag
//         int -1 falls Datum nicht ok -> Struktur behält das ursprüngliche Datum
int nextDay(Datum* pDatum)
{
	// Zur Demonstration:
	pDatum->tag++; // Zähle eins dazu -> geht nat. nicht so einfach, es fehlt der Überlauf falls Monatsende usw...


	return 0;  // alles ok
	// oder return -1; // falls das Datum ungültig war
}


void main()
{   // Code zur Demonstration
	int a;     
	int* pa = &a;
	*pa = 5;   // wie a = 5  
	int b;
	b = *pa;   // *....De-referenz opereator   ("greift auf den Ort zu wo der Pointer hinzeigt")
	printf("a liegt an Adress %p\n", &a);

	Datum d1 = datumsEingabe();
	int ergebnis = nextDay(&d1);               // "call by reference"

	/*
	Datum* pd1 = &d1;                          // welche Werte hat d2
	int ergebnis = nextDay(pd1);
	*/
	printf("Ergebnis ist %d, nextDay ist %d.%d.%d\n", 
		 ergebnis, d1.tag, d1.monat, d1.jahr);

	int x1 = 5, x2 = 6, x3 = 9;
	double avg = avg3(x1, x2, x3);     // "call by value"
	printf("avg = %lf\n", avg);
	getchar();
	getchar();
}

//
// Implementierungen der obigen Funktionen
//
double avg3(int z1, int z2, int z3)    // z1, z2, z3 = lokale Variablen
{
	return (((double)z1 + (double)z2 + (double)z3) / 3.0);
}

Datum datumsEingabe(void)
{
	Datum meinDatum;
	printf("Datum (tag.monat.jahr):");
	scanf_s("%d.%d.%d", &meinDatum.tag, &meinDatum.monat, &meinDatum.jahr);
	return meinDatum;
}


