/*
Arbeiten mit Dateien

Funktionen:		

- fopen(dateinamen, modus)
- fclose(file-handler)
- fgetc(file-handler)    -> liesst jeweils ein Zeichen aus der Datei
- ...und weitere


	1.) File U:\\text.txt öffnen zum Lesen
	2.) Fule U:\\text_out.txt öffnen zum Schreiben
	3.) Jedes Zeichen c aus text.txt soll in einen Großbuchstaben umgewandelt und in text_out.txt geschrieben werden 

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char myToUpper(char in)
{
	if (in >= 'a'&&in <= 'z') {
		in = in - 32;
	}

	return in;
}

void main()
{
	FILE* filehandler;
	FILE* filehandler1;
	char c;

	// 
	// Zuerst das File zum Lesen öffnen
	//
	filehandler = fopen("U:\\text.txt", "r");   // r....read

	if (filehandler == NULL) {
		printf("File nicht vorhanden !\n");
		getchar();	
		return;  // springt aus main heraus = programm beendet sich
	}

	// 
	// Jetzt das File zum Schreiben öffnen
	//

	filehandler1 = fopen("U:\\text_out.txt", "w");

	if (filehandler1 == NULL) {
		fclose(filehandler);   // File zum Lesen ist bereits offen, also muss ich es hier wieder schliessen
		printf("File nicht zum schreiben vorhanden !\n");
		getchar();
		return;  // springt aus main heraus = programm beendet sich
	}

	while (       (c = fgetc(filehandler)) != EOF    ) {   // !!! Achtung auf die Klammerung !!!
		fputc(myToUpper(c), filehandler1);    //<<-- so werden zeichen geschrieben
	}

	// alle Files wieder "zumachen" (=schliessen)
	fclose(filehandler1);
	fclose(filehandler);

	getchar();
	getchar();
}