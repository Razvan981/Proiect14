///\file main.c
///\brief Documentatie proiect 14 - Doxygen
///
///Creat de Brinzan Florinel - Razvan in data de 05/06/18.

#include "functii.h"///> verificareCiclu(), randGraph(), citirefisier()
///Declarare matricea de adiacenta si matricea auxiliara
int adjMatrix[MAX][MAX];
int aux[MAX][MAX];

int verificareCiclu(int adjMatrix[MAX][MAX]){

    ///\fn int verificareCiclu(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief Functia VerificareCiclu.
    ///\brief Functia VerificareCiclu() verifica daca graful generat random este aciclic sau nu.

    int iterator1;
    int iterator2;
    int count=lenghtM;
    int gradintern;
    int sw;
    int flag[MAX];
    /** initializarea matricei auxiliare */
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            aux[iterator1][iterator2] = adjMatrix[iterator1][iterator2];
        }
    }
    /// initializarea vectorului flag cu 0
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        flag[iterator1]=0;
    }
    /// structura repetitiva while() parcurge fiecare nod al grafului si testeaza daca nodul respectiv formeaza sau nu ciclu cu un alt grup de noduri.
    while(count != 0){
        sw = 0;
        for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
            gradintern = 0;
            if(flag[iterator1] == 0){
                for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
                   gradintern += aux[iterator2][iterator1];
                }
                if(gradintern == 0){
                    sw = 1;
                    flag[iterator1] = 1;
                    count--;
                    for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
                        aux[iterator1][iterator2] = 0;
                    }
                }
            }

        }
        if(sw == 0){
            return 0;
        }
    }

    return 1;
}
void randGraph(int adjMatrix[MAX][MAX]){

    ///\fn void randGraph(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief randGraph.
    /// Functia randGraph() genereaza un graf random.

    int iterator1;
    int iterator2;
    time_t t;
    srand((unsigned)time(&t));

    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
    /// punem conditia ca nodul sa nu aiba drum catre el insusi.
            if(iterator1 == iterator2){
                continue;
            }
    /// vom genera 1 sau 0 in matricea de diacenta.
            if(adjMatrix[iterator2][iterator1] == 0){
                adjMatrix[iterator1][iterator2] = rand() % 2;
            }
    /// daca generarea anterioara de "1" a produs ciclu intre nodurile grafului vom reinitializa cu 0.
            if(verificareCiclu(adjMatrix) == 0){
                adjMatrix[iterator1][iterator2] = 0;
            }

        }
    }
    /// Afisarea matricei de adiacenta in consola.
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            printf("%d ",adjMatrix[iterator1][iterator2]);
        }
        printf("\n");
    }

}


void citirefisier(int adjMatrix[MAX][MAX]){

    ///\fn void citirefisier(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief citirefisier.
    /// Functia citirefisier() citim matricea de adiacenta din fisierul date.txt.
    ///
    ///Vom crea un pointer pe care il vom folosi la citirea din fisier.
    FILE *f;
    int iterator1;
    int iterator2;


    f = fopen("date.txt", "r");

    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            fscanf(f, "%d", &adjMatrix[iterator1][iterator2]);
        }
    }
}

int main(){

    ///\fn int main()
    ///\brief Functia Main
    /// Functia main() apeleaza functiile randGraph(), citirefisier(), topSort(), TopSortDFS()  din functii.h
    ///\var alegere alege metoda de citire(citire din fisier sau generare random a grafului)
    int alegere;
    printf("Alegeti metoda de citire:\n");
    printf("Apasati 1 pentru citirea din fisier.\n");
    printf("Apasati 2 pentru generarea random a unui graf.\n");
    scanf("%d", &alegere);
    /// Pentru alegere = 2 -> randGraph
    /// Pentru alegere = 1 -> citirefisier
    if(alegere == 2){
        randGraph(adjMatrix);
    }
    else{
        citirefisier(adjMatrix);
    }
    printf("\n");
    printf("Alegeti metoda de aranjare a pieselor:\n");
    printf("Apasati 1 pentru Sortarea Topologica bazata pe eliminarea de varfuri.\n");
    printf("Apasati 2 pentru Sortarea Topologica bazata pe DFS.\n");
    ///\var alegere alege metoda de sortare(topSort sau TopSortDFS).
    scanf("%d", &alegere);
    /// Pentru alegere = 1 -> topSort
    /// Pentru alegere = 2 -> TopSortDFS
    if(alegere == 1){
        printf("\n========== Sortarea Topologica bazata pe eliminarea de varfuri ==========");
        printf("\nOrdinea in care Alexander trebuie sa aseze piesele este: ");
        topSort(adjMatrix);
    }
    else{
    printf("\n========== Sortarea Topologica bazata pe DFS ==========");
    printf("\nOrdinea in care Alexander trebuie sa aseze piesele este: ");
    TopSortDFS(adjMatrix);
    }

    return 0;
}
