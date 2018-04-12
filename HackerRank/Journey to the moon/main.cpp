#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int verts = 0;
vector<int> *graph;
vector<bool> visited;

// Find all reachable nodes
void DFS(int v){
    visited[v] = true;

    verts++;

    for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); ++it){
        if(!visited[*it]){
            visited[*it] = true;
            DFS(*it);
        }
    }
}

int factorial(int n){
    if(n == 1){
        return n;
    }
    return n*factorial(n-1);
}

int main(){
    int N, P;
    cin >> N >> P;
    vector<int> repre;

    graph = new vector<int>[N];
    while(P--){
        int v, e;
        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    for(int i = 0; i < N; i++){
        DFS(i); 
        repre.push_back(verts); 
        verts = 0; 
    }
    return 0;
}