#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> G[11];

vector<int> top_sort(){
    vector<int> degree (N, 0), t_sort;
    queue<int> q;
    for (const auto &Gi : G)
        for (auto & x: Gi) degree[x]++;

    for (int i = 0; i < N; ++i)
        if(degree[i] == 0) q.push(i);

    while(!q.empty()){
        int v = q.front(); q.pop();
        t_sort.push_back(v);
        for (auto u: G[v]){
            degree[u]--;
            if (degree[u] == 0) q.push(u);
        }
    }
    return t_sort;
}

int main() {
    int  E;
    cin >> N >> E;
    for (int i = 0; i  < E; ++i){
        int v, u;
        cin >> v >> u;
        G[v - 1].push_back(u - 1);
    }

    for (int i : top_sort())
        cout << i + 1 <<" ";
    return 0;
}
