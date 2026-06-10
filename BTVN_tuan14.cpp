#include <iostream>
using namespace std;
struct NodeAVL {
    int giaTri;
    NodeAVL *conTrai;
    NodeAVL *conPhai;
    int chieuCao;

    // Khởi tạo một nút mới (nút lá) luôn có chiều cao bằng 0
    NodeAVL(int x) {
        giaTri = x;
        conTrai = NULL;
        conPhai = NULL;
        chieuCao = 0; 
    }
};
// Lấy chiều cao của nút (nếu NULL thì trả về -1)
int layChieuCao(NodeAVL *nut) {
    return (nut == NULL) ? -1 : nut->chieuCao;
}
// Tìm số lớn hơn
int timMax(int a, int b) {
    return (a > b) ? a : b;
}