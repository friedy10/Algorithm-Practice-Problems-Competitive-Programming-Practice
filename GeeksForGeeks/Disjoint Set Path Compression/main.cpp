#include <iostream>
#include <stdio.h>

using namespace std;

struct Edge {
    int src, dest;
};

struct Graph {
    // Just store an array of edges
    struct Edge* edge;
    // Number of vertices and edges
    int V, E;
};

struct Subset {
    int root;
    // Uninon by rank to flatten the tree
    int rank; // size
}

struct Graph* 
createGraph(int V, int E){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    graph->V = V;
    graph->E = E;
    return graph;
}

int 
find(struct Subset sub[], int i){
    // Travel through the tree
    if(sub[i].parent != i){
        sub[i].parent = find(sub, sub[i].parent);
    }
    return sub[i].parent;
}

void union_subsets(struct Subset sub[], int x, int y){
    int rootx = find(sub, x);
    int rooty = find(sub, y);

    if (sub[rootx].parent < sub[rooty].parent){
        sub[rootx] = sub[rooty];
        sub[rootx].rank += sub[rooty].rank;
    }
}

