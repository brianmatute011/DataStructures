//
// Created by br14n on 20/3/22.
//
#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

typedef std::vector<std::vector<std::pair<int, int>>> vvp;
vvp Adjcost;
void  read_graph_cost(const std::string &path) {
    std::fstream _file;
    _file.open(path, std::ios::in);
    if (!_file) return;
    int v, v_ady, cost,  K, N;
    _file >> N >> K;
    Adjcost.resize(N);

    for  (int i = 0; i  < K; ++i){
        _file >> v >> v_ady >> cost;
        Adjcost[v].push_back({v_ady, cost});
    }

    _file.close();
}

vector<int> dijkstra_adj(int u){
    vector<int> SW(Adjcost.size(), INF);
    vector<bool> WF(Adjcost.size(), false);
    for (auto & i : Adjcost[u]) SW[i.first] = i.second;
    SW[u] = 0; WF[u] = true;
    for (int i = 0; i < Adjcost.size() - 1; ++i){
        int v, min_cost = INF;
        for (int j = 0; j < Adjcost.size(); ++j){ //FIND SMALL .W
            if (!WF[j]){
                if (SW[j] < min_cost){
                    v = j; min_cost = SW[j];
        }}}

        WF[v] = true; //Mark v as found

        for (auto x: Adjcost[v]) //For all vertex ady to v
            if(!WF[x.first])
                SW[x.first] = min(min_cost + x.second, SW[x.first]);
    }
    return SW;
}



int main() {
    read_graph_cost("inGC.txt");





    return 0;
}