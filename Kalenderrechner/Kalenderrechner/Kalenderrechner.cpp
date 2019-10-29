/*
PE - Kalaneder Rechnung
*/

#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tag, monat, jahr;

	printf("\n\nProgarmm zur Berechnung ob das von Ihnen eingegebene Datum ein Schaltjahr ist.\n");
	printf("_____________________________________________________________________________");
	printf("\nIst ihr Jahr ein Schaltjahr?\n");

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
	return 0;
}