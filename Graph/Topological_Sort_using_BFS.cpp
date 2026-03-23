#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int V, int E) {

    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    // Step 2: Find indegree of all nodes
    vector<int> indegree(V, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 3: Push 0 indegree nodes into queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 4: BFS
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}