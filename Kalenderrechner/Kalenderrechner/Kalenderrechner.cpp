/*
PE - Kalaneder Rechnung
*/

#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
int tag, monat, jahr;
int i;
int r = 0;
char response;
int tage_im_monat;

//Arrays
unsigned monats_laenge [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char wochen_tage[7][11]= {"Monatag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};

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

		//____________________________ [AUFGABE 1] __________________________________
		printf("Jahr:");
		scanf("%i", &jahr);

		printf("Das von Ihnen eingegebene Datum lautet:%i.%i.%i \n", tag, monat, jahr);
		if ((jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0)) {
			monats_laenge[2] = { 29 };
			printf("\nDas angegebene Jahr ist ein Schaltjahr.");
		}
		else
		{
			printf("\nDas von ihnen eingegebene Jahr ist kein Schaltjahr!");
		}
		//____________________________ [AUFGABE 2] __________________________________
		
		//monats_laenge[monat] = tage_im_monat;
		if (tag >= 1 && tag <= monats_laenge[monat -1]) {
			printf("\nIhr eingegebenes Datum ist korrekt.");
		}
		else 
		{
			printf("\nIhr eingegebenes Datum ist nicht korrekt!");
		}

		
		scanf("%c", &response);
		//____________________________ [AUFGABE 3] __________________________________
		i = 0;													//Wird 0 gesetzt, um bei 0 anzufangen
		for (i = 0; i <= (monat - 2); i++) {					// for-Schleife läuft so lange bis i größer ist als monat-2. Nachdem die schleife einmal durchgelaufen ist, wird i um +1 erhöht. | monat-2, um alle monate bis 1 vor eingegebenen monat zu "addieren."
			r += monats_laenge[i];							    // monats_laenge i wird mit r addiert. "r" wird mit dem Ergebniss der addition überchrieben.
			}
		r += tag;												// r wird mit dem eingegebenen Tag addiert."r" wird mit dem Ergebniss dieser Addition überschrieben. 
		printf("\nIhr eingegebenes Datum ist der %i. Tag im Jahr.", r);
		
		//____________________________ [AUFGABE 4] __________________________________


		//____________________________ [AUFGABE 5] __________________________________


		//_________________________ [AUFGABE 6 | ZUSATZ] ____________________________
		printf("\n\nerneute Berechnung? (j/n)\n");
	} while (getchar() == 'j' || getchar() == 'J');

}

