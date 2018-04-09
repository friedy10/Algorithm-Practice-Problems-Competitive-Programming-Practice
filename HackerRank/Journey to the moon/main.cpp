#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

vector<int> *graph;

void DFSUtil(int v, bool visited[]){
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjecent nodes
    vector<int>::iterator it;
    for(it = graph[v].begin(); it != graph[v].end(); ++it){
        if(!visited[*it]){
            visited[*it] = true;
        }
    }
}

// Find all reachable nodes
void DFS(int v, int number_of_ver){
    bool *visited = new bool[number_of_ver];
    for(int i = 0; i < number_of_ver; i++){
        visited[i] = false;
    }

    DFSUtil(v, visited);
}

int main(){
    int N, P;
    cin >> N >> P;

    graph = new vector<int>[N];
    while(P--){
        int v, e;
        graph[v].push_back(e);
    }
    return 0;
}