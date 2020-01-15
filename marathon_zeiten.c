#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGHT 100

typedef struct {
	char name[NAME_LENGHT];
	int hh,mm,ss;
	int gesamtSekunden;
} RUNNER;



void main()
{
	char name[NAME_LENGHT];
	
	/* Tauschen von zwei ints
	int a,b, tmp;
	tmp = a;
	a = b;
	b = tmp;
	*/

	/*
	RUNNER r1;
	RUNNER r2;
	RUNNER runners[100];
	// runners[0].wert...
	strcpy(r1.name, "Test1");
	r1.wert = 1000;
	r2 = r1;  // Structs können zugewiesen werden
	printf("%s, %d\n", r2.name, r2.wert);

	getchar();
	*/

	/*
	char dest[100];
	char src[100];
	strcpy(dest, src);   // dest = src
	*/

	int hh, mm, ss;
	RUNNER runner[10000];


	FILE* handler;
	handler = fopen("C:\\tmp\\Hamburg_Marathon.txt", "r");            // fopen = file open
	// U:\\Hamburg_marathon.txt
	// r = read, w = write, a = append
	// File-Funktionen:
	//    fgetc, fputc, fprintf, fscanf, fread, fwrite,...

	if (handler == NULL) {
		printf("File nicht gefunden !\n");
		getchar();
		return -1;
	}

	int counter = 0;
	int gesamtSekunden = 0;

	int  aktuellSchnellsteZeit;
	char aktuellSchnellsterLaeufer[NAME_LENGHT];

	while ( fscanf(handler, "%s %d:%d:%d", name, &hh, &mm, &ss) != EOF)
	{
		gesamtSekunden = hh * 3600 + mm * 60 + ss;
		printf("Laeufer Nr. %d, name = %s, zeit = %d : %d : %d, gesamtzeit = %d\n", counter, name, hh, mm, ss, gesamtSekunden);

		runner[counter].hh = hh;
		runner[counter].mm = mm;
		runner[counter].ss = ss;
		runner[counter].gesamtSekunden = gesamtSekunden;
		strcpy(runner[counter].name, name);
	
		counter++;
	}

	fclose(handler);

	// Ab hier: sortieren !


	/*
	printf("Geben Sie ein (name hh:mm:ss):");
	scanf("%s %d:%d:%d", name, &hh, &mm, &ss);
	printf("name = %s\n", name);
	printf("zeit = %d : %d : %d\n", hh, mm, ss);
	*/

	getchar();
	getchar();

}