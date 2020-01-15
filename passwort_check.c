/*
	Passwort-check

	1.) Benutzer gibt einen string ein (max. 255 Zeichen)
	2.) Sie überprüfen ob das passwort folgende Eigenschaften hat:
			- Mindestens 8 Zeichen
			- Mindestens ein Großbuchstabe
			- Mindestens eine Ziffer (Zeichen '0' bis '9')
			- Mindestens ein Sonderzeichen (=alles was nicht Groß, Klein,
					oder Ziffer ist, z.B. "!$%...."
	3.) Ausgabe: "Passwort ok" oder "Passwort nicht ok" (opt. "Kein Sondernzeichen",...)

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void main()
{
	int Z = 0;
	int G = 0;
	int k = 0;
	int S = 0;
	int x;
	char eingabe[255];
	do {
		printf("Geben Sie ein Passwort ein:");
		gets(eingabe);
		printf("Len = %d\n", strlen(eingabe));
		if (strlen(eingabe) < 8) {
			printf("Passwort nicht ok\n");
		} else {
			for (int i = 0; i < strlen(eingabe); i++) {
				if (eingabe[i] >= 'A' && eingabe[i] <= 'Z') {
					G++;
				} else {
					if (eingabe[i] >= 'a'&&eingabe[i] <= 'z') {
						k++;
					} else {
						if (eingabe[i] >= '0'&&eingabe[i] <= '9') {
							Z++;
						} else {
							S++;
						}
					}
				}
			}
			if (G > 0 && k > 0 && Z > 0 && S > 0) {
				printf("passwort ok\n");
				x = 0;
			}
			else {
				printf("Passwort nicht ok\n");

				// optionale Ausgabe
				if (G == 0) printf("Es fehlt ein Großbuchstabe\n");
				if (Z == 0) printf("Es fehlt eine Ziffer\n");
				// ...usw...

			}
		}
	
	} while (x != 0);
	system("pause");
}




