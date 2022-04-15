#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<pii> prim (vector<pii> G[], int q){
    vector<bool> visited(G->size(), false);
    vector<pii> C;
    int t = 0;
    pq.push({0, q});
    while (!pq.empty()){
        int v = pq.top().second,
            cost = pq.top().first; pq.pop();
        if(!visited[v]){ visited[v] = true;
            C.emplace_back(v, cost);
            t += cost;
            for (auto &x: G[v])
                if(!visited[x.first])
                    pq.push({x.second, x.first});
        }
    }
    return C;
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<pii> G[N];

    for (int i = 0; i < E; ++i){
        int v,  u, cost;
        cin >> v >> u >> cost;
        G[v].emplace_back(u, cost);
        G[u].emplace_back(v, cost);
    }
    prim(G, 0);



  return 0;
}
