///\file functii.h
///\brief Libraria C ce contine toate functiile folosite in rezolvarea problemei.
///
///Creat de Brinzan Florinel - Razvan in data de 05/06/18.

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 1001
#define lenghtM 1000

void topSort(int adjMatrix[MAX][MAX]);
void dfs(int iterator_dfs, int pozitie);
void TopSortDFS(int adjMatrix[MAX][MAX]);
int verificareCiclu(int adjMatrix[MAX][MAX]);
void randGraph(int adjMatrix[MAX][MAX]);
void citirefisier(int adjMatrix[MAX][MAX]);

#endif

