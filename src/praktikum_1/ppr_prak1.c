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

	int output = -1;                 /* Speichert den Index des letzten Mehrlings, falls gefunden, sonst -1 */
	int count = 1;                    /* Zählt die Anzahl der aufeinanderfolgenden gleichen Max-Werte */

	/* Durchlauf aller Indizes von 1 bis auschließlich limit */
	for (int i = 1; i < limit; i++)
	{
		/*
		 * Prüfe, ob zwei benachbarte Werte denselben Max-Wert haben.
		 * Wenn true, erhöhe count um 1 und prüfe, ob count der gesuchten Anzahl entspricht.
		 * Wenn false, setze count zurück auf 1.
		 */
		if (ulam_max(i) == ulam_max(i + 1))
		{
			count++;
			/*
			 * Falls count der gesuchten Anzahl entspricht, dann speichere den Startindex des Mehrlings.
			 * Reduziere count um 1, um eventuelle Sub-Mehrlinge zu finden.
			 */
			if (count == number)
			{
				output = i - number + 2;
				count--;
			}
		}
		else
		{
			count = 1;
		}

	}

	return output;
}
