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