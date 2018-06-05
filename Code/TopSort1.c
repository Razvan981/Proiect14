///\file TopSort1.c
///
/// Creat de Brinzan Florinel - Razvan in data de 05/06/18.

#include "functii.h"
///> topSort()

///Declarare matricea de adiacenta

int adjMatrix[MAX][MAX];

void topSort(int adjMatrix[MAX][MAX]){

    ///\fn void topSort(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief Functia topSort.
    /// Functia topSort() sorteaza nodurile din graf dupa gradul lor intern.

    int iterator1;
    int iterator2;
    int count = lenghtM;
    int gradintern;
    int flag2[MAX];
    /// initializarea vectorului flag2 cu 0.
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        flag2[iterator1] = 0;
    }
    /// Cat timp exista noduri din graf neafisate functia while le va parcurge, va calcula gradul intern si daca acesta este 0 va afisa nodul.
    /// Nodului afisat i se vor sterge legaturile catre celelalte noduri.
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
