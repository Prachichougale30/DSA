#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>>& adjList,
                    vector<pair<int,int>>& edges)
{
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>>& adjList,
         unordered_map<int, bool>& visited,
         vector<int>& ans,
         int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto neighbour : adjList[frontNode])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all components of graph
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main()
{
    int vertex = 5;

    vector<pair<int,int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({1,3});
    edges.push_back({2,4});

    vector<int> result = BFS(vertex, edges);

    cout << "BFS Traversal: ";
    for(int i : result)
    {
        cout << i << " ";
    }

    return 0;
}