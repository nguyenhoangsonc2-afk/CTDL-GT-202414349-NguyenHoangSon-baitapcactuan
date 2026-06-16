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