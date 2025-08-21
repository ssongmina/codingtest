#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int n, m, start, dest, cost, here;
vector<pair<int,int>> adj[1005];
int dist[1005];

void dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    fill(dist, dist+1005, INF);

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        tie(cost, here) = pq.top(); pq.pop();
        if (dist[here] < cost) continue;

        for(auto [next, w] : adj[here]) {
            if(dist[next] > dist[here] + w) {
                dist[next] = dist[here] + w;
                pq.push({dist[next], next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    cin >> start >> dest;

    dijkstra(start);
    cout << dist[dest] << "\n";
}
