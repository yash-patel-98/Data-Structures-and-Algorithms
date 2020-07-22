#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class GraphSim{
    public:
        map<int,vector<int>> graph;
        int vertex;
        GraphSim(int vertex){
            this->vertex = vertex;
        }
        void insertElements(int v, int e){
        graph[v].push_back(e);
        }
        void bfs(int s){
            deque<int> queue;
            bool visited[vertex];
            fill(visited,visited+vertex,false);
            visited[s] =true;
            queue.push_back(s);
            while(!queue.empty()){
                int c = queue.front();
                cout << c << " ";
                queue.pop_front();
                for(int i = 0; i < graph[c].size();i++){
                    if(!visited[graph[c][i]]){
                        queue.push_back(graph[c][i]);
                        visited[graph[c][i]] = true;
                    }
                }
            }
            cout << endl;
        }
};


int main(void){

    GraphSim g(4);
    g.insertElements(0, 1); 
    g.insertElements(0, 2); 
    g.insertElements(1, 2); 
    g.insertElements(2, 0); 
    g.insertElements(2, 3); 
    g.insertElements(3, 3); 
    g.bfs(2);

}