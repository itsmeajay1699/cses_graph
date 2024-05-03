

#include <bits/stdc++.h>
using namespace std;

int shortestDistance(int row, int col, vector<vector<int>> A, int xe, int ye)
{
    if (A[0][0] != 1 || A[xe][ye] != 1) // Check if start or end points are invalid
        return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    vector<vector<int>> visited(row, vector<int>(col, 0));
    visited[0][0] = 1; // Mark the start point as visited

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int distance = 0;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            if (x == xe && y == ye)
                return distance;

            for (int j = 0; j < 4; j++)
            {
                int new_x = x + dir[j].first;
                int new_y = y + dir[j].second;

                if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && A[new_x][new_y] == 1 && visited[new_x][new_y] == 0)
                {
                    visited[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        distance++;
    }

    return -1; // Return -1 if end point is unreachable
}
int main()
{
    int N, M, X, Y;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    cin >> X >> Y;
    cout << shortestDistance(N, M, A, X, Y) << endl;
    return 0;
}