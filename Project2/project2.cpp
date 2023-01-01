/**
 * @file project2.cpp
 * @author Simão Sanguinho - ist1102082, José Pereira - ist1103252
 * @group al023
 * @date 2022-01-03
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define edge pair<int, int> /* edge definition */

/* comparator to order edges reversely by their weight */
bool compareByWeight(const pair<edge, int> &a, const pair<edge, int> &b) {
  return a.second > b.second;
}

/* class to represent a graph */
class Graph {
private:
  vector<pair<edge, int>> G;   /* original graph */
  vector<pair<edge, int>> MST; /* resulting MST */
  int V;                       /* number of vertices in the graph */
  int *parent;                 /* to keep track of the parent of each node */

public:
  Graph(const int V); /* constructor */
  void AddEdge(const int vertex1, const int vertex2,
               const int weight);                      /* add an edge */
  void unionSet(const int vertex1, const int vertex2); /* union of two sets */
  int findSet(const int vertex); /* find the parent of a set */
  int getMST();                  /* getMST algorithm */
};

Graph::Graph(const int nVertices) {
  parent = new int[nVertices];
  iota(parent, parent + nVertices, 0); /* fill parent with 0 1 2 3 4 ... */
}

void Graph::AddEdge(const int vertex1, const int vertex2, const int weight) {
  G.push_back(make_pair(edge(vertex1, vertex2), (weight))); /* add the edge */
}

void Graph::unionSet(const int vertex1, const int vertex2) {
  parent[vertex1] = parent[vertex2]; /* make vertex1 as parent of vertex2 */
}

int Graph::findSet(const int vertex) {
  /* if i is not it's own parent, then call findSet on it's parent
      using path compression */
  return (vertex == parent[vertex]) ? vertex
                                    : parent[vertex] = findSet(parent[vertex]);
}

int Graph::getMST() {
  int res = 0;
  int graphSize = G.size();
  sort(G.begin(), G.end(), compareByWeight); /* sort the edges */
  for (int i = 0; i < graphSize; i++) {
    int vertex1 = findSet(G[i].first.first);  /* find the parent of vertex1 */
    int vertex2 = findSet(G[i].first.second); /* find the parent of vertex2 */
    if (vertex1 != vertex2) {     /* if they are not in the same set */
      MST.push_back(G[i]);        /* add the edge to the MST */
      unionSet(vertex1, vertex2); /* make them in the same set */
      res += G[i].second;         /* add the weight of the edge */
    }
  }
  return res;
}

int main() {
  int nEdges, nVertices;        /* number of edges and vertices */
  int vertex1, vertex2, weight; /* edge's vertices and it's weight */

  /* read the number of vertices and edges */
  scanf("%d %d", &nVertices, &nEdges);
  Graph g(nVertices); /* create a graph with nVertices vertices */

  for (int i = 0; i < nEdges; i++) {
    /* read the edge and it's weight */
    scanf("%d %d %d", &vertex1, &vertex2, &weight);
    g.AddEdge(vertex1, vertex2, weight); /* add the edge to the graph */
  }
  printf("%d\n", g.getMST()); /* print result */
  return 0;
}