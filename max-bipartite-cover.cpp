#include<bits/stdc++.h>
using namespace std;

int M,N;
bool Graph[10][10];
bool bpm(bool Graph[10][10], int u,
         bool seen[], int matchR[])
{
    for (int v = 0; v < N; v++)
    {
        if (Graph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(Graph, matchR[v],seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(bool Graph[10][10])
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        if (bpm(Graph, u, seen, matchR))
        {
            result++;
        }
    }
    return result;
}


int main()
{
    cout << "Enter the number of elements in the first and the second set" << endl;
    cin >> M >> N;

    cout << "Enter the matrix" << endl;
    for(int i = 0;i < M;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cin >> Graph[i][j];
        }
    }
    cout << "The maximum matching possible is " << maxBPM(Graph);
    return 0;
}
