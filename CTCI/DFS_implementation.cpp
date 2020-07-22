#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        map<int,vector<int>> g;
        int v;
        Graph(int v){
            this->v = v;
        }
        void insertElements(int v, int e){
            g[v].push_back(e);
        }
        void dfsGo(int s, bool visited[]){
            visited[s] = true;
            cout << s << " ";
            for(int i = 0; i < g[s].size();i++){
                if(!visited[g[s][i]])
                    dfsGo(g[s][i], visited);
            }
            cout << endl;
        }
        void dfs(int s){
            bool visited[v];
            fill(visited,visited+v,false);
            dfsGo(s,visited);
        }
};


int main(void){
    Graph g(4);
    g.insertElements(0, 1); 
    g.insertElements(0, 2); 
    g.insertElements(1, 2); 
    g.insertElements(2, 0); 
    g.insertElements(2, 3); 
    g.insertElements(3, 3); 
    g.dfs(2);
}