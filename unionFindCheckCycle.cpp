#include <bits/stdc++.h>

using namespace std;


class Edge{
    public:
    int src, dest;
};
class Graph{
    public:
    int V;
    int E;
    Edge* edge;
    
};
Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
};

int find(int v, vector<int>& parent){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find(parent[v],parent);
}

void Union(int x, int y, vector<int>& parent){
    x = find(x,parent);
    y = find(y,parent);
    if (x != y) {
        parent[y] = x;
    }
}
int isCycle(Graph* graph){
    int V = graph->V;
    int E = graph->E;
    vector<int> parent(V,-1);
    for(int i = 0; i < V; ++i){
        parent[i] = i;
    }
    for(int i = 0; i < E; ++i){
        int x = find(graph->edge[i].src,parent);
        int y = find(graph->edge[i].dest,parent);
        if (x == y) {
            return 1;
        }
        Union(x,y,parent);
    }
    return 0;
};
int main(){
    int V = 3, E = 3;
    Graph* graph = createGraph(V,E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
