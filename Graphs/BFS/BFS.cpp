//
// Created by br14n on 19/3/22.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[11];
vector<bool> visited(11, false);

void read_graph(const string &path){
    std::fstream _file;
    _file.open(path, std::ios::in);
    if (!_file) cout << "Error \n";
    int vx, vy, k;
    _file >> k;
    for (int i = 0; i < k; ++i){
        _file >> vx >> vy;
        adj[vx].push_back(vy);
    }
    _file.close();
}

void bfs (int u){
    queue<int> q;
    cout << u <<" ";
    visited[u] = true; q.push(u);
    while (!q.empty()){
        auto k = q.front(); q.pop();
        for (auto &x: adj[k]){
            if (!visited[x]){
                cout << x <<" ";
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    read_graph("ingraphread.txt");
    bfs(0);
    return 0;
}