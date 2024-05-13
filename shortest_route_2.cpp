#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n, m, q;

    cin >> n >> m >> q;

    vector<vector<long long>> matrix(n + 1, vector<long long>(n + 1, 2'000'000'000'000'000'000));

    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        matrix[a][b] = min(matrix[a][b], c);
        matrix[b][a] = min(matrix[b][a], c);
    }

    // Floyd Warshall Algorithm
    for (long long i = 1; i <= n; i++)
    {
        matrix[i][i] = 0;
    }

    for (long long k = 1; k <= n; k++)
    {
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                if (matrix[i][k] != 2'000'000'000'000'000'000 && matrix[k][j] != 2'000'000'000'000'000'000)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    for (long long i = 0; i < q; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (matrix[a][b] == 2'000'000'000'000'000'000)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << matrix[a][b] << endl;
        }
    }

    return 0;
}