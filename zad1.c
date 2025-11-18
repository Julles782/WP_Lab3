#include <stdio.h>
#define MAX 50

int main(void) {
    FILE *fp;
    char nazwisko[50];
    int indeks;

    // -----------------------------
    // Krok 1: Wczytanie i wyświetlenie studentów z nieparzystym indeksem
    // -----------------------------
    fp = fopen(/* ??? */);
    if (!fp) {
        printf("Nie mozna otworzyc pliku studenci.txt\n");
        return 1;
    }

    printf("Studenci z nieparzystym indeksem:\n");
    while (fscanf(fp, "%s %d", nazwisko, &indeks) == 2) {
        if (/* ??? */) {
            printf("%s %d\n", nazwisko, indeks);
        }
    }

    fclose(fp);

    // -----------------------------
    // Kolejne zadania do wykonania:
    // -----------------------------
    // 1. Wczytaj wszystkie indeksy studentów do tablicy 'indeksy[MAX]'.
    // 2. Posortuj tablicę indeksów rosnąco (np. sortowanie bąbelkowe).
    // 3. Oblicz średnią wartości indeksów i wypisz indeksy większe od średniej.
    // 4. Wczytaj dane z pliku 'egzamin.txt'.
    // 5. Na podstawie punktów oblicz oceny (np. >90% = 5, >75% = 4, >50% = 3, reszta 2).
    // 6. Zapisz wyniki do pliku 'wyniki.txt' w formacie: numer indeksu i ocena.

    return 0;
}
