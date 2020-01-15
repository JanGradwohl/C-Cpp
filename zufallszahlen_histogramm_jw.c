#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTERVALL 7
#define MAX_ZUFALL 500

int main(void)
{
	/*Deklaration*/
	int iZufallsZahl;
	int iCounter;
	int iBalken;
	int iarrIntervalle[MAX_INTERVALL];
	int iAbsolut = 0;
	float fRelativ=0.0;

	/*Init*/
	iZufallsZahl = 0;
	srand(time(NULL));//init vom ´Zufallsgenerator
	for (iCounter = 0; iCounter < MAX_INTERVALL; iCounter++)
	{
		iarrIntervalle[iCounter] = 0;
	}

	/*Erzeuge Zufallszahlen 1 bis 500 (MAX_ZUFALL) */
	/*zähle in den Gruppen mit*/
	for (iCounter = 0; iCounter < MAX_ZUFALL; iCounter++)
	{
		iZufallsZahl = 1 + rand() % 21; //erzeuge eine Zufallszahl
		/*in der Gruppe mitaddieren*/
		//iarrIntervalle[(iZufallsZahl-1)/3]++;

		if (iZufallsZahl >= 1 && iZufallsZahl <= 3)
		{
			iarrIntervalle[0]++;
		}
		if (iZufallsZahl >= 4 && iZufallsZahl <= 6)
		{
			iarrIntervalle[1]++;
		}
		if (iZufallsZahl >= 7 && iZufallsZahl <= 9)
		{
			iarrIntervalle[2]++;
		}
		if (iZufallsZahl >= 10 && iZufallsZahl <= 12)
		{
			iarrIntervalle[3]++;
		}
		if (iZufallsZahl >= 13 && iZufallsZahl <= 15)
		{
			iarrIntervalle[4]++;
		}
		if (iZufallsZahl >= 16 && iZufallsZahl <= 18)
		{
			iarrIntervalle[5]++;
		}
		if (iZufallsZahl >= 19 && iZufallsZahl <= 21)
		{
			iarrIntervalle[6]++;
		}
	}
	//Ausgabe
	/*Überschrift*/
	printf(" Bereich     Anzahl    Relativ  Diagramm\n--------------------------------------------------------------------------------------------------------------------\n");
	for (iCounter = 0; iCounter < MAX_INTERVALL; iCounter++)
	{
		/*Abs Häufigkeit*/
		iAbsolut = iarrIntervalle[iCounter];
		fRelativ = ((float)iarrIntervalle[iCounter] / MAX_ZUFALL) * 100;
		printf("[%2d bis %2d]   %3d      %2.2f%%   ", iCounter + 1, (iCounter+1) * 3, iarrIntervalle[iCounter], fRelativ);
		for (iBalken = 0; iBalken < iAbsolut; iBalken++)
		{
			printf("%c", '#');
		}
		printf("\n");
	}
	
	getchar();
	return 0;
}
