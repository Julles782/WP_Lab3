#include <stdio.h>
#define MAX 50

int main(void) {
    FILE *fp; //
    char nazwisko[MAX];
    int indeks;
    int indeksy[MAX];
    int suma = 0;
    double srednia = 0;

    // -----------------------------
    // Krok 1: Wczytanie i wyświetlenie studentów z nieparzystym indeksem
    // -----------------------------
    fp = fopen("studenci.txt", "r");
    if (!fp) {
        printf("Nie mozna otworzyc pliku studenci.txt\n");
        return 1;
    }

    //printf("Studenci z nieparzystym indeksem:\n");
    // fscanf - czyta z pliku

    int i = 0;
    while (fscanf(fp, "%s %d", nazwisko, &indeks) == 2) {
        indeksy[i] = indeks; // 
        i = i + 1;
        
    }
    
    for(int j = 0; j < MAX; j++){

        suma = indeksy[j] + suma;

        
    }

    srednia = (double) suma / MAX;
    printf(" %.2lf\n", srednia);

    printf("INdeksy wieksze od sredniej \n");
    for(int k = 0; k < MAX; k++){

        if(indeksy[k] > srednia){

            printf(" %d\n", indeksy[k]);
            
        }
    }
    fclose(fp);

    // -----------------------------
    // Kolejne zadania do wykonania:
    // -----------------------------
    // 1. Wczytaj wszystkie indeksy studentów do tablicy 'indeksy[MAX]'.
    // 2. Oblicz średnią wartości indeksów i wypisz indeksy większe od średniej.
    // 3. Wczytaj dane z pliku 'egzamin.txt'.
    // 4. Na podstawie punktów oblicz oceny (np. >90% = 5, >75% = 4, >50% = 3, reszta 2).
    // 5. Zapisz wyniki do pliku 'wyniki.txt' w formacie: numer indeksu i ocena.

    int  tablica[10];

    tablica[3] = 5;

    return 0;
}
