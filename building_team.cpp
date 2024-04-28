
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int persons, relations;
    cin >> persons >> relations;

    vector<int> adj[persons + 1];
    for (int i = 0; i < relations; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(persons + 1, 0);
    bool isPossible = true;
    for (int i = 1; i <= persons; i++)
    {
        if (color[i] == 0)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int child : adj[node])
                {
                    if (color[child] == 0)
                    {
                        color[child] = 3 - color[node];
                        q.push(child);
                    }
                    else if (color[child] == color[node])
                    {
                        isPossible = false;
                        break;
                    }
                }
            }
        }
    }

    if (isPossible)
    {
        for (int i = 1; i <= persons; i++)
        {
            cout << color[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}