#include "functii.h"

int adjMatrix[MAX][MAX];
int aux[MAX][MAX];
//int visitedB[MAX];
//int Vector[lenghtM+1];


int verificareCiclu(int adjMatrix[MAX][MAX]){

    int iterator1;
    int iterator2;
    int count=lenghtM;
    int gradintern;
    int sw;
    int flag[MAX];

    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            aux[iterator1][iterator2] = adjMatrix[iterator1][iterator2];
        }
    }

    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        flag[iterator1]=0;
    }
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

    int iterator1;
    int iterator2;
    time_t t;
    srand((unsigned)time(&t));

    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            if(iterator1 == iterator2){
                continue;
            }
            if(adjMatrix[iterator2][iterator1] == 0){
                adjMatrix[iterator1][iterator2] = rand() % 2;
            }
            if(verificareCiclu(adjMatrix) == 0){
                adjMatrix[iterator1][iterator2] = 0;
            }

        }
    }
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
            printf("%d ",adjMatrix[iterator1][iterator2]);
        }
        printf("\n");
    }

}


void citirefisier(int adjMatrix[MAX][MAX]){
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

int main()
{
    int alegere;
    printf("Alegeti metoda de citire:\n");
    printf("Apasati 1 pentru citirea din fisier.\n");
    printf("Apasati 2 pentru generarea random a unui graf.\n");
    scanf("%d", &alegere);
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
    scanf("%d", &alegere);
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
