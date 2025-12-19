#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

class Graph{
public:
    int num_stones;
    vector<pair<pair<int,int>,int>> coordinate;
    // <x_pos, y_pos>

    Graph(){/* void */}
    Graph(int n_stepstone){
        num_stones = n_stepstone;
        coordinate.reserve(num_stones);
    }

    void add_stepstone(int idx, int x_pos, int y_pos){
        coordinate.push_back({make_pair(x_pos, y_pos), idx});
    }

    void sort_stones(){
        sort(coordinate.begin(), coordinate.end());
    }
};

template<typename WT>
void Dijkstra(const char *_filename, Graph &_graph, int goal_y){
    int n = _graph.num_stones;
    bool *visit = new bool[n];
    WT *distance = new WT[n];

    for(int i = 0; i < _graph.num_stones; i++){
        visit[i] = false;
        distance[i] = numeric_limits<WT>::max();
    }


    priority_queue<pair<WT,int>, vector<pair<WT,int>>, greater<pair<WT,int>>> PQ;

    for(int i = 0; i < n; i++) {
        int start_x = _graph.coordinate[i].first.first;
        int start_y = _graph.coordinate[i].first.second;

        // 시작점 (0,0)에서의 제약 조건 확인
        if(abs(start_x) <= 2 && abs(start_y) <= 2) {
            WT d = sqrt((long long)start_x*start_x + (long long)start_y*start_y);
            distance[i] = d;
            PQ.push({d, i});
        }
    }

    WT final_dist = -1;

    while(!PQ.empty()){

        int curr_idx = PQ.top().second;
        WT curr_d = PQ.top().first;
        PQ.pop();

        if(visit[curr_idx]){
            continue;
        }

        visit[curr_idx] = true;

        int curr_x = _graph.coordinate[curr_idx].first.first;
        int curr_y = _graph.coordinate[curr_idx].first.second;

        if(curr_y >= goal_y){
            final_dist = curr_d;
            break;
        }

        for(int i = 0; i < n; i++){
            int next_x = _graph.coordinate[i].first.first;
            int next_y = _graph.coordinate[i].first.second;

            if(next_x < curr_x - 2) continue;
            if(next_x > curr_x + 2) break;

            if(abs(next_y - curr_y) <= 2){
                WT weight = sqrt(pow((long long)curr_x - next_x, 2) + pow((long long)curr_y - next_y, 2));
                if(distance[curr_idx] + weight < distance[i]){
                    distance[i] = distance[curr_idx] + weight;
                    PQ.push({WT(distance[i]), i});
                }
            }
        }
    }


    FILE *output = fopen(_filename, "w");
    fprintf(output, "%lld\n", (long long)round(final_dist));
    fclose(output);
    
    delete [] visit;
    delete [] distance;
}


int main(int argc, char **argv){
	if( argc != 3 ){
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}

    int n_stepstone, goal_y;

    FILE *input = fopen(argv[1], "r");

    if (!input) {
        perror("파일을 열 수 없습니다");
        return 1;
    }

    if (fscanf(input, "%d %d", &n_stepstone, &goal_y) != 2){}

    Graph g(n_stepstone);

    for (int i = 0; i < n_stepstone; i++) {
        int x_pos, y_pos;
        if (fscanf(input, "%d %d", &x_pos, &y_pos) == 2)
            g.add_stepstone(i, x_pos, y_pos);
    }

    fclose(input);

    g.sort_stones();
    Dijkstra<double> (argv[2], g, goal_y);
	return 1;
}