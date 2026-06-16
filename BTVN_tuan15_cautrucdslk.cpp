#include <iostream>
#include <queue>
using namespace std;

const int N = 11;
string tenTP[N] = {
    "Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi",
    "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"
};
// cau truc node
struct Node {
    int dest;
    Node* next;
};
Node* head[N] = {nullptr};
Node* tail[N] = {nullptr};

// chen mot dinh vao cuoi dslk dinh khac
void chenVaoCuoi(int u, int v) {
    Node* newNode = new Node;
    newNode->dest = v;
    newNode->next = nullptr;

    if (head[u] == nullptr) {
        head[u] = newNode;
        tail[u] = newNode;
    } else {
        tail[u]->next = newNode;
        tail[u] = newNode;
    }
}
void themCanh(int u, int v) {
    chenVaoCuoi(u, v);
    chenVaoCuoi(v, u);
}
// duyet theo chieu rong
void BFS(int start) {
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << tenTP[u] << " -> ";
        Node* temp = head[u];
        while (temp != nullptr) {
            int v = temp->dest;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
            temp = temp->next;
        }
    }
    cout << "END\n";
}