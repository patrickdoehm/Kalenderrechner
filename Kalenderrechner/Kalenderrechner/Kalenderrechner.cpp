/*
PE - Kalaneder Rechnung
*/

#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
int tag, monat, jahr;
int i;
int a, b, c, d;
int w, t, x, y;
int r = 0;
char response;
int tage_im_monat;

//Arrays
unsigned monats_laenge [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned monatjz[13] = { 0,0,3,3,6,1,4,6,2,5,0,3,5 };

void firstweekday(int tag, int monat, int jahr) {
	tag = 1;
	monat = 1;
	int ergebnis = 0;
	int tagesziffer = (tag % 7);
	int monatsziffer = monatjz[monat];
	int jahresziffer = ((jahr % 100) + ((jahr % 100) / 4)) % 7;
	int jahrhundertziffer = (3 - ((jahr / 100) % 4)) * 2;

	if (jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0) {
		tagesziffer = tagesziffer + 6;
	}
	ergebnis = (tagesziffer + monatsziffer + jahresziffer + jahrhundertziffer) % 7;

	if (ergebnis == 0) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Sonntag");
	}
	if (ergebnis == 1) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Montag");
	}
	if (ergebnis == 2) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Dienstag");
	}
	if (ergebnis == 3) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Mittwoch");
	}
	if (ergebnis == 4) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Donnerstag");
	}
	if (ergebnis == 5) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Freitag");
	}
	if (ergebnis == 6) {
		printf("\nDer erste Tag im angegebenen Jahr ist ein Samstag");
	}
}

//Welcher wochentag?
void wichweekday(int tag, int monat, int jahr) {
	int ergebnis = 0;
	int tagesziffer = (tag % 7);
	int monatsziffer = monatjz[monat];
	int jahresziffer = ((jahr % 100) + ((jahr % 100) / 4)) % 7;
	int jahrhundertziffer = (3 - ((jahr / 100) % 4)) * 2;

	if ((monat <= 2) && (jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0)) {
		tagesziffer = tagesziffer + 6;
	}
	ergebnis = (tagesziffer + monatsziffer + jahresziffer + jahrhundertziffer) % 7;

	if (ergebnis == 0) {
		printf("\nDer angegebene Tag ist ein Sonntag");
	}
	if (ergebnis == 1) {
		printf("\nDer angegebene Tag ist ein Montag");
	}
	if (ergebnis == 2) {
		printf("\nDer angegebene Tag ist ein Dienstag");
	}
	if (ergebnis == 3) {
		printf("\nDer angegebene Tag ist ein Mittwoch");
	}
	if (ergebnis == 4) {
		printf("\nDer angegebene Tag ist ein Donnerstag");
	}
	if (ergebnis == 5) {
		printf("\nDer angegebene Tag ist ein Freitag");
	}
	if (ergebnis == 6) {
		printf("\nDer angegebene Tag ist ein Samstag");
	}
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
		
		if (tag >= 1 && tag <= monats_laenge[monat -1]) {
			printf("\nIhr eingegebenes Datum ist korrekt.");
		}
		else 
		{
			printf("\nIhr eingegebenes Datum ist nicht korrekt!");
		}

		
		scanf("%c", &response);
		i = 0;
		for (i = 0; i <= (monat - 2); i++) {

			r += monats_laenge[i];
		}
		r += tag;
		printf("\nDas Datum ist der %i. Tag im Jahr", r);
		//____________________________ [AUFGABE 4] __________________________________

		firstweekday(tag, monat, jahr);
		//____________________________ [AUFGABE 5] __________________________________
		wichweekday(tag, monat, jahr);


		printf("\n\nerneute Berechnung? (j/n)\n");

		scanf("%c", &response);
		
		
	


		//_________________________ [AUFGABE 6 | ZUSATZ] ____________________________
		printf("\n\nerneute Berechnung? (j/n)\n");
	} while (getchar() == 'j' || getchar() == 'J');

}

