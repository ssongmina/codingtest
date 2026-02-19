#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int solution(int n, vector<vector<int>> road, int k) {

    vector<vector<pair<int,int>>> adj(n+1);

    for(auto r : road){
        int a = r[0];
        int b = r[1];
        int w = r[2];

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> dist(n+1, INF);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [cost, now] = pq.top();
        pq.pop();

        if(cost > dist[now]) continue;

        for(auto [next, w] : adj[now]){
            if(dist[next] > cost + w){
                dist[next] = cost + w;
                pq.push({dist[next], next});
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] <= k) answer++;
    }

    return answer;
}
