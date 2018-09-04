
#include <vector>
using namespace std;
 
// GRAFO POR MATRIZ DE ADJACENCIA
 
struct node{
    int index, parent, cost;
};
 
struct graph{
    vector<node> nodes;
    vector<vector<int>> edges;
};
 
void init(graph &g, int n){
    g.nodes.resize(n);
    g.edges.resize(n);
 
    for (int i = 0; i < n; i++){
        g.nodes[i].index = i;
        g.nodes[i].parent = -1; //quer dizer que não existe nó pai
        g.nodes[i].cost = 0; //custo até chegar em i é iniciado com 0
        g.edges[i].resize(n, 0); //adicione esta linha para matriz de adjacencia
    }
}
 
/*
Suponha o seguinte grafo:
a -> b
a -> c
b -> c
c -> b
 
Vamos dar os seguintes indices para os nos:
a = 0
b = 1
c = 2
 
Logo, na funcao main ficaria:
*/
 
int main(){
    int n = 3; // numero de nós do grafo
    graph g;
   
    init(g, n); // inicializando grafo
   
    g.edges[0][1] = 1; // a -> b
    g.edges[0][2] = 1; // a -> c
    g.edges[1][2] = 1; // b -> c
    g.edges[2][1] = 1; // c -> b
   
    return 0;
}