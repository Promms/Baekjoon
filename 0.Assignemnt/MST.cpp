#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

template<typename WT>
class Graph{
public:
    int n_Vertex, n_Edge;

    vector<vector<pair<int, WT>>> edges;

    Graph(){/* void */}
    Graph(const char *_filename){
        FILE *input = fopen(_filename, "r");

        if (!input) {
            perror("파일을 열 수 없습니다");
            return;
        }

        if (fscanf(input, "%d %d", &n_Vertex, &n_Edge) != 2) {
            fclose(input);
            return;
        }

        edges.resize(n_Vertex);

        for (int i = 0; i < n_Edge; i++) {
            int u, v;
            double w;
            if (fscanf(input, "%d %d %lf", &u, &v, &w) == 3) {
                u--; v--;
                edges[u].push_back({v, static_cast<WT>(w)});
                edges[v].push_back({u, static_cast<WT>(w)});
            }
        }
        fclose(input);
    }
};

template<typename WT>
void Prim(const char *_filename, Graph<WT> &_graph){
    bool *visit = new bool[_graph.n_Vertex];
    int *parent = new int[_graph.n_Vertex];
    WT *distance = new WT[_graph.n_Vertex];

    for(int i = 0; i < _graph.n_Vertex; i++){
        visit[i] = false;
        parent[i] = -1;
        distance[i] = numeric_limits<WT>::max();
    }

    int root = 0;
    distance[root] = 0;
    parent[root] = -1;

    priority_queue<pair<WT,int>, vector<pair<WT,int>>, greater<pair<WT,int>>> PQ;
    PQ.push(make_pair((WT)0, root));

    while(true){
        if(PQ.empty()){
            break;
        }

        pair<WT,int> visit_vertex = PQ.top();
        PQ.pop();

        if(visit[visit_vertex.second]){
            continue;
        }

        visit[visit_vertex.second] = true;

        for(auto& edge : _graph.edges[visit_vertex.second]){
            int adj_vertex = edge.first;
            WT weight = edge.second;

            if(!visit[adj_vertex] && weight < distance[adj_vertex]){
                PQ.push(make_pair(weight, adj_vertex));
                parent[adj_vertex] = visit_vertex.second;
                distance[adj_vertex] = weight;
            }
        }
    }

    int cost_of_mst = 0;
    for(int i = 0; i < _graph.n_Vertex; i++){
        cost_of_mst += distance[i];
    }

    FILE *output = fopen(_filename, "w");
    fprintf(output, "%d\n", cost_of_mst);
    fclose(output);
    
    delete [] visit;
    delete [] parent;
    delete [] distance;
}


int main(int argc, char **argv){
	if( argc != 3 ){
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}
    Graph<int> g(argv[1]);
    Prim<int> (argv[2], g);
	return 1;
}