#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 500
#define lenghtM 8
int adjMatrix[MAX][MAX];
int visitedB[MAX];
int Vector[lenghtM+1];


int verificareCiclu(int adjMatrix[MAX][MAX]){

    int iterator1;
    int iterator2;
    int count=lenghtM;
    int gradintern;
    int sw;
    int aux[MAX][MAX];
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
                //printf("%d\n",adjMatrix[iterator1][iterator2]);
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
void topSort(int adjMatrix[MAX][MAX]){
    int iterator1;
    int iterator2;
    int count = lenghtM;
    int gradintern;
    int flag2[MAX];
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        flag2[iterator1] = 0;
    }
    while(count != 0){
        for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
            gradintern = 0;
            if(flag2[iterator1] == 0){
                for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
                   gradintern += adjMatrix[iterator2][iterator1];
                }
                if(gradintern == 0){
                    flag2[iterator1] = 1;
                    printf("%d ", iterator1);
                    count--;
                    for(iterator2 = 0; iterator2 < lenghtM; iterator2++)
                        adjMatrix[iterator1][iterator2] = 0;
                }
            }

        }

    }

    printf("\n");



}
void dfs(int iterator_dfs, int pozitie){


    int iterator1;
    int nr = 0;
    int iterator2;
        for(iterator1 = 0;iterator1 < lenghtM; iterator1++){
            if(adjMatrix[iterator_dfs][iterator1] == 1 && visitedB[iterator1] == 0){
                dfs(iterator1, pozitie);
            }
        }
        for(iterator2 = 0;iterator2 < lenghtM; iterator2++){
            if(adjMatrix[iterator_dfs][iterator1] == 1 && visitedB[iterator1] == 0){
                nr++;
            }
        }
        if(nr == 0){
            if(Vector[pozitie] == -1){
                Vector[pozitie] = iterator_dfs;
            }else{
                while(Vector[pozitie] != -1){
                    pozitie++;
                }
                Vector[pozitie] = iterator_dfs;
            }
            visitedB[iterator_dfs] = 1;
        }




}
void citirefisier(int adjMatrix[MAX][MAX])
{
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
void TopSortDFS(int adjMatrix[MAX][MAX])
{
    int iterator1;
    int iterator2;
    int sw;
    int gradintern;
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        Vector[iterator1] = -1;
     }
    int pozitie = 0;

    while(1>0){
        sw = 0;

        for(iterator1 = 0;iterator1 < lenghtM; iterator1++){
            gradintern = 0;
            if(visitedB[iterator1] == 0){
                for(iterator2 = 0; iterator2 < lenghtM; iterator2++){
                    gradintern += adjMatrix[iterator2][iterator1];
                }
                if(gradintern == 0){
                    dfs(iterator1, pozitie);
                    sw = 1;
                }
            }
        }
        if( !sw ){
            break;
        }
    }

    for(iterator2 = lenghtM - 1; iterator2 >= 0 ;iterator2--){
        printf("%d ", Vector[iterator2]);
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
