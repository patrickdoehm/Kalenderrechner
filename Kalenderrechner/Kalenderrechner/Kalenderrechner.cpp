/*
PE - Kalaneder Rechnung
*/

#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
int tag, monat, jahr;
char response;

int Schaltjahr_check() { // Aufgabe 1) Berechnen Sie, ob das Jahr des vom Benutzer eingegebenen Datums ein Schaltjahr ist.
	if ((jahr % 4 == 0 && jahr % 100 == 0 || jahr % 400 == 0));
	printf("\n Das angegebene Jahr ist ein Schaltjahr");
	return 0;
}

int main()
{

	printf("\n\nProgarmm zur Berechnung ob das von Ihnen eingegebene Datum ein Schaltjahr ist.\n");
	printf("_____________________________________________________________________________");
	printf("\nIst ihr Jahr ein Schaltjahr?\n");

	do {
	
		do {
		printf("Tag:");
		scanf("%i", &tag);
		while (getchar() != '\n');
		if ((tag >= 32) || (tag <= 0)) {
			printf("Bitte geben sie einen Tag zwischen 1 und 31 an.\n");
		}
	} while ((tag >= 32) || (tag <= 0));

	do {
		printf("Monat:");
		scanf("%i", &monat);
		while (getchar() != '\n');
		if ((monat >= 13) || (monat <= 0)) {
			printf("Bitte geben sie einen Monat zwischen 1 und 12 an.\n");
		}
	} while ((monat >= 13) || (monat <= 0));


		printf("Jahr:");
		scanf("%i", &jahr);

		printf("Das von Ihnen eingegebene Datum lautet:%i.%i.%i \n", tag, monat, jahr);
		if ((jahr % 4 == 0 && jahr % 100 == 0 || jahr % 400 == 0)) {
			printf("\nDas angegebene Jahr ist ein Schaltjahr");
		} 
		else
		{
			printf("\nDas von ihnen eingegebene Jahr ist kein Schaltjahr!");
		}

		printf("\n\nerneute Berechnung? (j/n)\n");
		scanf("%c", &response);
		//while (getchar() != '\n');
	} while (getchar() == 'j' || getchar() == 'J');

}