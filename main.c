#include <stdio.h>
#include <stdlib.h>
#define MAX 500
#define lenghtM 200
int adjMatrix[MAX][MAX];

///////////////////////////////////////////

int verificareCiclu(int adjMatrix[MAX][MAX]){
    int iterator1,iterator2,count=lenghtM,gradintern,sw,aux[MAX][MAX],flag[MAX];

    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
            aux[iterator1][iterator2]=adjMatrix[iterator1][iterator2];
        }
    }

    for(iterator1=0; iterator1 < lenghtM; iterator1++)
        flag[iterator1]=0;
    //printf("Sortarea topologica este: ");
    while(count!=0){
        sw=0;
        for(iterator1=0; iterator1 < lenghtM; iterator1++){
            gradintern=0;
            if(flag[iterator1]==0){
                for(iterator2=0; iterator2 < lenghtM; iterator2++){
                   gradintern+=aux[iterator2][iterator1];
                }
                if(gradintern==0){
                    sw=1;
                    //printf("%d",sw);
                    flag[iterator1]=1;
                    //printf("%d ",iterator1+1);
                    count--;
                    for(iterator2=0; iterator2 < lenghtM; iterator2++)
                        aux[iterator1][iterator2]=0;
                }
            }

        }
        //printf("\n");
        if(sw==0) return 0;
    }

    //printf("\n");

    return 1;

}
void randGraph(int adjMatrix[MAX][MAX]){

    int iterator1, iterator2;
    time_t t;
    srand((unsigned)time(&t));


    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
            if(iterator1==iterator2){
                continue;
            }
            if(adjMatrix[iterator2][iterator1]==0){
                adjMatrix[iterator1][iterator2]=rand() % 2;
                //printf("%d\n",adjMatrix[iterator1][iterator2]);
            }
            if(verificareCiclu(adjMatrix)==0){
                adjMatrix[iterator1][iterator2]=0;
            }

        }
    }
    for(iterator1=0; iterator1 < lenghtM; iterator1++){
        for(iterator2=0; iterator2 < lenghtM; iterator2++){
            printf("%d ",adjMatrix[iterator1][iterator2]);
        }
        printf("\n");
    }

}
void topSort(int adjMatrix[MAX][MAX]){
    int iterator1,iterator2,count=lenghtM,gradintern,flag2[MAX];
    for(iterator1=0; iterator1 < lenghtM; iterator1++)
        flag2[iterator1]=0;
    printf("Ordinea in care Alexanderr trebuie sa aseze piesele: ");
    while(count!=0){
        for(iterator1=0; iterator1 < lenghtM; iterator1++){
            gradintern=0;
            if(flag2[iterator1]==0){
                for(iterator2=0; iterator2 < lenghtM; iterator2++){
                   gradintern+=adjMatrix[iterator2][iterator1];
                }
                if(gradintern==0){
                    flag2[iterator1]=1;
                    printf("%d ",iterator1+1);
                    count--;
                    for(iterator2=0; iterator2 < lenghtM; iterator2++)
                        adjMatrix[iterator1][iterator2]=0;
                }
            }

        }

    }

    printf("\n");



}
int main()
{
    randGraph(adjMatrix);
    topSort(adjMatrix);
    return 0;
}
