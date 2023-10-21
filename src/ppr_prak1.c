#include <stdbool.h>
#include "ppr_prak1.h"

int ulam_max(int a0)
{
	int actual = a0;     /* Der aktuelle Wert der ULAM-Folge */
	int max = a0;        /* Der aktuell maximale Wert der ULAM-Folge */

	/* Erzeugen der ULAM-Folge, solange es sich um eine natürliche Zahl handelt. */
	while (actual > 0)
	{
		/* Wenn der aktuelle Wert der ULAM-Folge gerade ist, dann halbiere ihn. */
		if (actual % 2 == 0)
		{
			actual = actual / 2;
		}
			/* Wenn der aktuelle Wert der ULAM-Folge ungerade ist, dann verdreifache ihn und addiere 1 dazu. */
		else
		{
			actual = 3 * actual + 1;
		}

		/* Überprüfung, ob der aktuelle Wert größer ist, als der aktuell größte Wert. */
		if (actual > max)
		{
			max = actual;
		}
		/*
		 * Wenn der aktuelle Wert gleich Eins ist, dann ist die Folge terminiert und es soll der größte gespeicherte
		 * Wert zurückgegeben werden.
		 */
		if (actual == 1)
		{
			return max;
		}
	}
	return -1;    /* Wenn kein sinnvoller Wert aktuell ist, dann gib -1 zurück. */
}

int ulam_twins(int limit)
{
	int index;                /* Index, um alle Werte im Intervall durchlaufen zu können */
	int output = -1;            /* Der zurückgegebene Wert, wenn ein Zwilling gefunden wurde, sonst -1 */

	/* Durchlauf beginnend von 1 bis limit - 1, wo nach einem ULAM-Zwilling gesucht wird in der Schrittweite 1. */
	for (index = 1; index < limit; index++)
	{
		/*
		 * Prüfe, ob zwei benachbarte Werte denselben Max-Wert in ihrer ULAM-Folge haben.
		 * Falls true, dann setze output auf den aktuellen index.
		 */
		if (ulam_max(index) == ulam_max(index + 1))
		{
			output = index;
		}
	}

	return output;
}

int ulam_multiples(int limit, int number)
{
	/*
	 * Prüfe zunächst, ob die Eingaben sinnvoll sind.
	 * Dem ist nicht der Fall, wenn number gleich 1 ist, weil es automatisch auf den letzten Wert des Intervalles
	 * verweist oder number ausserhalb des Intervalles liegt.
	 */
	if (number == 1)
	{
		return limit;
	}
	else if (number < 1 || number > limit)
	{
		return -1;
	}

	int output = -1;            /* Der zurückgegebene Wert, wenn ein Mehrling gefunden wurde, sonst -1 */

	/*
	 * Durchlauf beginnend von 1 bis limit - number + 2, wo nach einem ULAM-Mehrling gesucht wird in der Schrittweite 1.
	 * Es kann nicht durch das gesamte Intervall iteriert werden, weil die innere for-Schleife sonst aus dem Intervall
	 * fällt.
	 */
	for (int index = 1; index < limit - number + 2; index++)
	{
		int count = 1;            /* Anzahl der Werte im aktuellen Mehrling */
		bool isTwin = true;        /* Definiert die Abbruchbedingung für die for-Schleife */

		/*
		 * Überprüft paarweise in einem Sub-Intervall mit der Größe number, ob alle ULAM-Werte gleich sind.
		 * Die for-Schleife stoppt, wenn es sich nicht um ein Mehrling handelt und setzt die äußere for-Schleife fort.
		 */
		for (int i = index; (i < index + number - 1) && isTwin; i++)
		{
			/*
			 * Überprüft, ob es sich beim aktuellen Paar um ein Zwilling handelt.
			 * Wenn true, dann erhöhe count um 1.
			 */
			isTwin = (ulam_max(i) == ulam_max(i + 1));
			if (isTwin)
			{
				count++;
			}

			/* Wenn count gleich number ist, dann wurde ein Mehrling gefunden und wird in output gespeichert. */
			if (count == number)
			{
				output = index;
			}
		}
	}

	return output;
}
