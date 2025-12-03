#include <stdio.h>
#define MAX 50

int main(void) {
    FILE *plik_quiz; 
    int wyniki[MAX][2];
    int powyzej_sredniej[MAX];
    int liczba_powyzej_sredniej = 0;



    plik_quiz = fopen("quiz.txt", "r");
    if (!plik_quiz) {
        printf("Nie mozna otworzyc pliku quiz.txt\n");
        return 1;
    }
    
    int suma = 0;
    for (int i = 0; i < MAX; i++){

        fscanf(plik_quiz, "%d %d", &wyniki[i][0],&wyniki[i][1]);

        suma = suma + wyniki[i][1];

        
    }
    printf("suma wynikow: %d\n", suma);
    double srednia = (double) suma / MAX;
    printf("Srednia liczba punktow: %.2lf\n", srednia);

     FILE  *plik_quiz_wynik = fopen ("quiz_wynik.txt", "w");
    if (!plik_quiz_wynik){

        printf("Nie udało się utwirzyc pliku quiz_wynik.txt \n");
        return 1;
    }
    for (int i = 0; i < MAX; i++){


        if(wyniki[i][1] > srednia){

            powyzej_sredniej[liczba_powyzej_sredniej] = wyniki[i][0];
            fprintf(plik_quiz_wynik, "%d %d\n", powyzej_sredniej[liczba_powyzej_sredniej], wyniki[i][1]);
            liczba_powyzej_sredniej = liczba_powyzej_sredniej + 1;

            

        }


    }

    fclose(plik_quiz_wynik);
    fclose(plik_quiz);


    return 0;
}
