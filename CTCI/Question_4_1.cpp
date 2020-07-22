#include<bits/stdc++.h>

using namespace std;


class Graph{
    public:
        map<int,vector<int>> g;
        int v;
        Graph(int v){
            this->v = v;
        }
        void insert(int v, int e){
            g[v].push_back(e);
        }
        void checkForLink(int s, int e){
            deque<int> q;
            bool visited[v];
            fill(visited, visited+v,false);
            q.push_back(s);
            visited[s] = true;
            bool isRoutePresent = false;
            while(!q.empty()){
                int n = q.front();
                q.pop_front();
                for(int i = 0; i < g[n].size();i++){
                    if(!visited[g[n][i]]){
                        if(g[n][i] == e){
                            isRoutePresent = true;
                            break;
                        }
                        q.push_back(g[n][i]);
                    }
                }
                if(isRoutePresent)
                    break;
                cout << "Queue not empty" << endl;
            }
            if (isRoutePresent) 
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
};


int main(){

    Graph g(4);
    g.insert(0, 1); 
    g.insert(0, 2); 
    g.insert(1, 2); 
    g.insert(2, 0); 
    g.insert(2, 3); 
    g.insert(3, 3); 
    g.checkForLink(0,3);

}