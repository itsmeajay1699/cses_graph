

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &comp)
{
    visited[node] = 1;
    comp.push_back(node);

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, comp);
        }
    }
}

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes + 1);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(nodes + 1, 0);

    vector<pair<int, int>> ans;
    int last = -1;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            dfs(i, adj, visited, comp);
            if (last != -1)
            {
                ans.push_back({last, comp[0]});
            }
            last = comp[0];
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
}