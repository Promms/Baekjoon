#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

class Task_DAG{
public:
    int n_tasks = 0, n_dependency = 0;
    vector<pair<pair<int,int>,vector<int>>> tasks;
    // <in-degree, task time>, adjacent

    Task_DAG(){/* void */}
    Task_DAG(const char *_filename){
        FILE *input = fopen(_filename, "r");

        if(!input){
            perror("파일을 열 수 없습니다");
            return;
        }

        if(fscanf(input, "%d %d", &n_tasks, &n_dependency) != 2){
            fclose(input);
            return;
        }

        tasks.resize(n_tasks);

        for(int i = 0; i < n_tasks; i++){
            int time;
            if(fscanf(input, "%d", &time) == 1)
                tasks[i].first.second = time;
        }

        for(int j = 0; j < n_dependency; j++){
            int leading_task, following_task;
            if(fscanf(input, "%d %d", &leading_task, &following_task) == 2){
                leading_task--; following_task--;
                tasks[leading_task].second.push_back({following_task});
                tasks[following_task].first.first++; // following_task의 indegree를 증가
            }
        }

        fclose(input);
    }
};

void Critical_Path(const char *_filename, Task_DAG &_task){
    int n = _task.n_tasks;
    int *indegree = new int[n];
    int *critical_times = new int[n];

    for(int i = 0; i < n; i++){
        indegree[i] = _task.tasks[i].first.first;
        critical_times[i] = 0;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    // idx, task time

    for(int i = 0; i < n; i++) {
        int in_degree = indegree[i];

        // in-degree가 0인 vertex
        if(in_degree == 0) {
            int task_time = _task.tasks[i].first.second;
            PQ.push({i, task_time});
        }
    }

    int complete_time = -1;
    int complete_task = 0;

    while(!PQ.empty()){
        int curr_task = PQ.top().first;
        int curr_task_time = PQ.top().second;
        PQ.pop();

        complete_task++;
        critical_times[curr_task] += curr_task_time;

        for(auto& following_task : _task.tasks[curr_task].second){
            indegree[following_task]--;
            critical_times[following_task] = max(critical_times[following_task], critical_times[curr_task]);
            if(indegree[following_task] == 0)
                PQ.push({following_task, _task.tasks[following_task].first.second});
        }
    }

    if(complete_task != n)
        complete_time = -1;
    else
        complete_time = *max_element(critical_times, critical_times + n);
    

    FILE *output = fopen(_filename, "w");
    fprintf(output, "%d\n", complete_time);
    fclose(output);
    
    delete [] indegree;
    delete [] critical_times;
}

int main(int argc, char **argv){
	if(argc != 3){
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}
    Task_DAG g(argv[1]);
    Critical_Path (argv[2], g);
	return 1;
}