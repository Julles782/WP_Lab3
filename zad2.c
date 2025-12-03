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

    FILE *egzamin = fopen("egzamin.txt", "r");
        if(!egzamin) {

            printf("Nie udało się otworzyć pliku \n");
            return 1;

    }
    int wyniki[MAX];
    for (int i = 0; i < MAX; i++){

        fscanf(egzamin, "%d %d", &indeks, &wyniki[i]);
        printf("Wyniki: %d ", wyniki[i]);
        double procent = (double) wyniki[i] / 90 * 100;
        /*if(wyniki[i] > 90){

            printf("- 5 \n");
        }


       else if(wyniki[i] > 75){

            printf("- 4 \n");
        }

        else if(wyniki[i] > 50){

            printf("- 3 \n");
        }

        else {

            printf("- 2 \n");
        }*/
        
        if(procent > 90){

            printf("- 5 \n");
        }


       else if(procent > 75){

            printf("- 4 \n");
        }

        else if(procent > 50){

            printf("- 3 \n");
        }

        else {

            printf("- 2 \n");
        }
    }

 
    fclose(egzamin);


    FILE *plik_z_wynikami = fopen ("wyniki.txt", "w");
    if(!plik_z_wynikami){

        printf("NIe udało się utworzyć pliku wyniki.txt");
        return 1;
    }

    for (int i = 0; i < MAX; i++){

        int ocena;
        double procent = (double) wyniki[i] / 90 * 100;
         if(procent > 90){

            ocena =5;
        }


       else if(procent > 75){

            ocena = 4;
        }

        else if(procent > 50){

            ocena = 3;
        }

        else {

            ocena = 2;
        }
        fprintf(plik_z_wynikami, "%d %d\n", indeksy[i], ocena);
    }
    fclose(plik_z_wynikami);
    // -----------------------------
    // Kolejne zadania do wykonania:
    // -----------------------------
    // 1. Wczytaj wszystkie indeksy studentów do tablicy 'indeksy[MAX]'.
    // 2. Oblicz średnią wartości indeksów i wypisz indeksy większe od średniej.
    // 3. Wczytaj dane z pliku 'egzamin.txt'.
    // 4. Na podstawie punktów oblicz oceny (np. >90% = 5, >75% = 4, >50% = 3, reszta 2).
    // 5. Zapisz wyniki do pliku 'wyniki.txt' w formacie: numer indeksu i ocena.

  

    return 0;
}
