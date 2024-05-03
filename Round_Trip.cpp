#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &path)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis, path))
            {

                path.push_back(node);

                return true;
            }
        }
        else if (it != parent)
        {

            path.push_back(it);
            path.push_back(node);
            return true;
        }
    }

    return false;
}

int main()
{
    int city, road;
    cin >> city >> road;

    vector<int> adj[city + 1];

    for (int i = 0; i < road; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(city + 1, 0);
    vector<int> path;

    for (int i = 1; i <= city; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis, path))
            {

                reverse(path.begin(), path.end());

                int i = 0;

                while (path[i] != path[path.size() - 1])
                {
                    i++;
                }
                cout << path.size() - i << endl;
                for (int j = i; j < path.size(); j++)
                {
                    cout << path[j] << " ";
                }

                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}