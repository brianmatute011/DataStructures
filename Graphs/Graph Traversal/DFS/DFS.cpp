//
// Created by br14n on 13/4/22.
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

void dfs (int u){
    if (visited[u]) return;
    visited[u] = true;
    cout <<u <<" ";
    for (auto &x : adj[u])
        if(!visited[x]) dfs(x);
}



int main() {
    read_graph("ingraphread.txt");
    dfs(0);



    return 0;
}