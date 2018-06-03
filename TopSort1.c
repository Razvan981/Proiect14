#include "functii.h"

int adjMatrix[MAX][MAX];

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
