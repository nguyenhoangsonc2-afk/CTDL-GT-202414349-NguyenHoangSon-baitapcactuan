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
// duyet theo chieu sau
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
    }}
    int main()
{
    themCanh(0,1);

    themCanh(0,2);
    themCanh(2,3);

    themCanh(3,4);
    themCanh(2,4);
    themCanh(4,5);
    themCanh(0,6);
    themCanh(6,5);
    themCanh(6,7);
    themCanh(7,8);
    themCanh(0,8);
    themCanh(0,9);
    themCanh(0,10);

    cout << "BFS bat dau tu Ha Noi:\n";
    BFS(0);

    return 0;
}