#include <iostream>
#include <queue>
using namespace std;
const int N = 11;
string tenTP[N] = {
    "Ha Noi",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay"
};
int a[N][N] = {0};

void themCanh(int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
}
void BFS(int start)
{
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << tenTP[u] << " ";

        for(int v = 0; v < N; v++)
        {
            if(a[u][v] && !visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }