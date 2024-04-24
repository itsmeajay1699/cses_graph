

#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &v, vector<vector<int>> &visited)
{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = p.first + dir[i].first;
            int y = p.second + dir[i].second;

            if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && !visited[x][y] && v[x][y] == '.')
            {
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }
}

// time complexity is O(n*m) and space complexity is O(n*m)

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = s[j];
        }
    }

    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (!visited[i][j] && v[i][j] == '.')
            {
                bfs(i, j, v, visited);
                count++;
            }
        }
    }

    cout << count << endl;
}

int main()
{
    solve();
}