/**
 * @file
 * In diesem Modul werden die Aufgaben aus dem ersten Praktikumsblatt umgesetzt. Dieses Blatt umfasst drei Aufgaben zu
 * der ULAM-Folge.
 *
 * @author Dennis Stroz
 * @date 2023-10-21
 */
#ifndef PPR_PPR_PRAK1_H
#define PPR_PPR_PRAK1_H

#endif //PPR_PPR_PRAK1_H

/**
 * Diese Funktion berechnet für eine ganze positive Zahl den maximalen Wert in der Folge ihrer ULAM-Werte.
 *
 * @param a0: Ganze positive Zahl, zu dem die ULAM-Folge gebildet wird.
 *
 * @return Der maximale Wert aus der berechneten ULAM-Folge. Bei einem ungültigem Wert oder einem Überlauf wird -1
 * zurückgegeben.
 */
int ulam_max(int a0);

/**
 * Diese Funktion prüft, ob es in einem Intervall von Werten ULAM-Zwillinge gibt.
 *
 * @param limit: Bestimmt das Intervall von 1 bis einschließlich limit.
 *
 * @return Gibt den letzten kleineren Wert für die ULAM-Folge zurück, für den ein Zwilling existiert. Es wird -1
 * zurückgegeben, wenn kein solches Zwillingspaar gefunden wurde.
 */
int ulam_twins(int limit);

/**
 * Diese Funktion prüft, ob in einem Intervall von Werten ULAM-Mehrlinge existieren.
 *
 * @param limit: Bestimmt das Intervall von 1 bis einschließlich limit.
 * @param number: Die vollständig enthaltene Anzahl eines ULAM-Mehrlings.
 *
 * @return Gibt den letzten kleineren Wert für die ULAM-Folge zurück, für den ein Mehrling existiert. Es wird -1
 * zurückgegeben, wenn kein solcher Mehrling gefunden wurde oder nicht Parameter nicht sinnvoll sind.
 */
int ulam_multiples(int limit, int number);
