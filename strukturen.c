#include <stdio.h>

/*
	Strukturen:

	struct [bezeichner1] { Liste_von_Komponenten } [bezeichner2];

	Beispiel mit Strukturen:

    Benutzer kann zwei Geburtstage eingeben (nur gültige Werte!) 
	Sie bestimmen wer "jünger" ist !
	Ausgabe: "Geburtstag x ist jünger !"
	
	Tipp: Das Julianische Datum berechnet von einem Datum die Anzahl
	      der Tage von 1.1.-4712 bis zu diesem Datum.
		  Diese Werte lassen sich dann leicht vergleichen.

	Alternative: ein Verzweigungsbaum aus IF-Abfragen
	
*/

typedef struct  
{
	unsigned int tag;     
	unsigned int monat;
	unsigned short jahr;  
	unsigned int jd;        // das Julianische Datum (siehe unten)
} DATUM;


void main()
{
	DATUM datum1;
	DATUM datum2;

	DATUM daten[32];    // Array von Strukturen geht auch !
	daten[0].tag = 5;   // Beispiel für Zugriff

	int	k, l, jd;

	// Erstes Datum 
	printf("Geben Sie Datum 1 ein (Durch . getrennt):");
	scanf_s("%d.%d.%d", &datum1.tag, &datum1.monat, &datum1.jahr);
		
	k=(datum1.monat-14)/12;
	l=datum1.jahr+k+4800;
	jd=datum1.tag-32075+1461*l/4 + 367* ((datum1.monat-2-12*k)/12)-3*((l+100)/100)/4;
	datum1.jd = jd;   // Julianische Datum wird in der Strukt selbst abgelegt

	printf("Geben Sie Datum 2 ein (Durch . getrennt):");
	scanf_s("%d.%d.%d", &datum2.tag, &datum2.monat, &datum2.jahr);

	// Zweites Datum
	k=(datum2.monat-14)/12;
	l=datum2.jahr+k+4800;
	jd=datum2.tag-32075+1461*l/4 + 367* ((datum2.monat-2-12*k)/12)-3*((l+100)/100)/4;
	datum2.jd = jd;  // Julianische Datum wird in der Strukt selbst abgelegt

	if (datum1.jd > datum2.jd) {
		printf("Zweiter ist älter !");
	} else {
		if (datum1.jd < datum2.jd) {
			printf("Erster ist älter !");
		} else {
			printf("Beide gleich alt !");
		}
	}

	getchar();
	getchar();
}

