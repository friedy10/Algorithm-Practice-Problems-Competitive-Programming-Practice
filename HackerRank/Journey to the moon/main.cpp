#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000000

int verts = 0;
vector<int> *graph;
vector<int> visited(MAX);

// Find all reachable nodes
void DFS(int v){
    visited[v] = 1;

    verts++;

    for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); ++it){
        if(!visited[*it]){
            visited[*it] = 1;
            DFS(*it);
        }
    }
}

int main(){
    int N, P, numC;
    cin >> N >> P;
    vector<int> repre;

    graph = new vector<int>[N];
    while(P--){
        int v, e;
        cin >> v >> e;
        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    for(int i = 0; i < N; i++){
        DFS(i); 
        repre.push_back(verts); 
        numC++;
        verts = 0; 
    }

    int totalWays = N * (N - 1) / 2;
    int sameWays = 0;
    
    for(int i = 0; i < numC; i++)
    {    
        sameWays = sameWays + (repre[i]*(repre[i]-1) / 2);
    }
    cout << (totalWays - sameWays) << endl;
    return 0;
}