#include <stdio.h>
#define MAX 50

int main(void) {
    FILE *plik_wypozyczenia; 
    int biblio[MAX][2];
    int aktywni[MAX];
    int liczba_aktywnych = 0;



    plik_wypozyczenia = fopen("wypozyczenia.txt", "r");
    if (!plik_wypozyczenia) {
        printf("Nie mozna otworzyc pliku wypozyczenia.txt\n");
        return 1;
    }
    
    int suma = 0;
    for (int i = 0; i < MAX; i++){

        fscanf(plik_wypozyczenia, "%d %d", &biblio[i][0],&biblio[i][1]);

        suma = suma + biblio[i][1];

        if(biblio[i][1] > 2){

            aktywni[liczba_aktywnych] = biblio[i][0];
            liczba_aktywnych = liczba_aktywnych + 1;
            
        }
        
    }
    printf("suma wypozyczen: %d\n", suma);


    FILE  *plik_aktywni_czytelnicy = fopen ("aktywni_czytelnicy.txt", "w");
    if (!plik_aktywni_czytelnicy){

        printf("Nie udało się utwirzyc pliku aktywni czytelnicy.txt \n");
        return 1;
    }
    for (int i = 0; i < liczba_aktywnych; i++){

        
        fprintf(plik_aktywni_czytelnicy, "%d \n", aktywni[i]);
    }

    fclose(plik_aktywni_czytelnicy);
    fclose(plik_wypozyczenia);


    return 0;
}
