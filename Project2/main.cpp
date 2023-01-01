/*
 * File: proj2.cpp
 * Authors: Simão Sanguinho  - ist1102082
 *          José Pereira     - ist1103252
 * Description: Project 2 - ASA
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct node1 {

  int v1;     /* vertex 1 */
  int v2;     /* vertex 2 */
  int weight; /* edge weight */

} * edge;

typedef struct node2 {

  int rank; /* rank of the vertex */
  struct node2 *parent; /* parent of the vertex */
} * vertex;

/* comparator to order edges reversely by their weight */
bool compareByWeight(const edge &a, const edge &b) {
  return a->weight > b->weight;
}

int main() {

  int nEdges, nVertices;
  int v1, v2, w;

  /* read input */
  scanf("%d %d", &nVertices, &nEdges);

  vector<edge> edgesList;

  for (int i = 0; i < nEdges; i++) {
    edge currEdge = new node1;
    scanf("%d %d %d", &v1, &v2, &w);
    currEdge->v1 = v1;
    currEdge->v2 = v2;
    currEdge->weight = w;
    edgesList.push_back(currEdge);
  }

  for (int i = 0; i < nEdges; i++) {
    printf("...%d\n", edgesList[i]->weight);
  }

  /* sort the edges' vector in descending order by weight */
  sort(edgesList.begin(), edgesList.end(), compareByWeight);

  for (int i = 0; i < nEdges; i++) {
    printf("...%d\n", edgesList[i]->weight);
  }
}