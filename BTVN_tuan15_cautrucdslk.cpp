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
int main() {
    
    themCanh(0, 1);  // Hà Nội - Thái Nguyên (Đ7)
    themCanh(0, 2);  // Hà Nội - Bắc Ninh (Đ8)
    themCanh(0, 6);  // Hà Nội - Hải Dương (Đ1)
    themCanh(0, 8);  // Hà Nội - Phủ Lý (Đ4)
    themCanh(0, 9);  // Hà Nội - Hòa Bình (Đ5)
    themCanh(0, 10); // Hà Nội - Sơn Tây (Đ6)
    themCanh(2, 3);  // Bắc Ninh - Bắc Giang (Đ9)
    themCanh(2, 4);  // Bắc Ninh - Uông Bí (Đ11)
    themCanh(3, 4);  // Bắc Giang - Uông Bí (Đ10)
    themCanh(4, 5);  // Uông Bí - Hải Phòng (Đ12)
    themCanh(5, 6);  // Hải Phòng - Hải Dương (Đ13)
    themCanh(6, 7);  // Hải Dương - Hưng Yên (Đ2)
    themCanh(7, 8);  // Hưng Yên - Phủ Lý (Đ3)

    cout << "Ket qua duyet BFS tu Ha Noi:\n";
    BFS(0);

    return 0;
}