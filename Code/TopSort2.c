///\file TopSort2.c
///
/// Creat de Brinzan Florinel - Razvan in data de 05/06/18.

#include "functii.h"///> topSortDFS(), dfs()

///Declarare vectorului de vizitare
int visitedB[MAX];
///Declarare vectorului de afisare
int Vector[lenghtM+1];
///Declarare matricea de adiacenta
int adjMatrix[MAX][MAX];

void dfs(int iterator_dfs, int pozitie){

    ///\fn void dfs(int iterator_dfs, int pozitie)
    ///\param iterator_dfs - varful din care se va incepe parcurgerea cu dfs.
    ///\param pozitie - parametru ce ajuta la scrierea nodurilor in Vector
    ///\brief Functia dfs.
    /// Functia dfs() parcurge graful in adancime.

    int iterator1;
    int nr = 0;
    int iterator2;
    /// aplicam dfs pentru parcurgerea varfurilor
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
        /// incepem scrierea in Vector de la primul -1 gasit
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

    ///\fn TopSortDFS(int adjMatrix[MAX][MAX])
    ///\param adjMatrix[MAX][MAX] - matricea de adiacenta
    ///\brief Functia TopSortDFS.
    /// Functia TopSortDFS() sorteaza nodurile in functie de parcurgerea lor cu dfs.

    int iterator1;
    int iterator2;
    int sw;
    int gradintern;
    /// initializam Vector cu -1
    for(iterator1 = 0; iterator1 < lenghtM; iterator1++){
        Vector[iterator1] = -1;
     }
    int pozitie = 0;

    while(1>0){
        sw = 0;

        for(iterator1 = 0;iterator1 < lenghtM; iterator1++){
            gradintern = 0;
    /// Daca nodul nu a fost vizitat si memorat in Vector atunci i se calculeaza gradul intern si daca acesta este 0 se aplica dfs plecand din el.
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
    /// Vector care memorase nodurile in ordine inversa sortarii lor topologice va fi afisat invers, aceasta fiind si ordinea topologica a nodurilor.
    for(iterator2 = lenghtM - 1; iterator2 >= 0 ;iterator2--){
        printf("%d ", Vector[iterator2]);
    }
}
