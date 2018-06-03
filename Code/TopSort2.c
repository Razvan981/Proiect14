#include "functii.h"

int visitedB[MAX];
int Vector[lenghtM+1];
int adjMatrix[MAX][MAX];

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

void TopSortDFS(int adjMatrix[MAX][MAX]){
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
