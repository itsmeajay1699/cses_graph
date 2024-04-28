
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int computers, connections;

    cin >> computers >> connections;

    vector<int> graph[computers + 1];

    for (int i = 0; i < connections; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> parent(computers + 1, -1);

    queue<int> q;
    q.push(1);
    parent[1] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (parent[graph[node][i]] == -1)
            {
                parent[graph[node][i]] = node;
                q.push(graph[node][i]);
            }
        }
    }

    if (parent[computers] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        path.push_back(computers);
        int node = computers;
        while (node != 1)
        {
            node = parent[node];
            path.push_back(node);
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}