#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void dfs(int node, const vector<vector<int>> &mat, vector<bool> &visited)
{
    visited[node] = true;
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[node][i] == 1 && !visited[i])
            dfs(i, mat, visited);
    }
}


bool isTree(const vector<vector<int>> &mat)
{
    int n = mat.size();
    int edgeCount = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j] == 1)
                edgeCount++;
        }
    }


    if (edgeCount != n - 1)
        return false;

    vector<bool> visited(n, false);
    dfs(0, mat, visited);

    for (bool v : visited)
    {
        if (!v)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    if (isTree(mat))
        cout << "The graph IS a Tree.\n";
    else
        cout << "The graph is NOT a Tree.\n";

    return 0;
}
