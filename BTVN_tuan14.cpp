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
// Tính độ lệch cân bằng
int doLech(NodeAVL *nut) {
    if (nut == NULL)
        return 0;
    return layChieuCao(nut->conTrai) - layChieuCao(nut->conPhai);
}
// Xoay phải (trường hợp LL)
void xoayPhai(NodeAVL *&nutMatCanBang) {
    NodeAVL *nutConTrai = nutMatCanBang->conTrai;

    nutMatCanBang->conTrai = nutConTrai->conPhai;
    nutConTrai->conPhai = nutMatCanBang;

    nutMatCanBang->chieuCao = timMax(layChieuCao(nutMatCanBang->conTrai),
                                     layChieuCao(nutMatCanBang->conPhai)) + 1;

    nutConTrai->chieuCao = timMax(layChieuCao(nutConTrai->conTrai),
                                   layChieuCao(nutConTrai->conPhai)) + 1;

    nutMatCanBang = nutConTrai;
}
// Xoay trái (trường hợp RR)
void xoayTrai(NodeAVL *&nutMatCanBang) {
    NodeAVL *nutConPhai = nutMatCanBang->conPhai;

    nutMatCanBang->conPhai = nutConPhai->conTrai;
    nutConPhai->conTrai = nutMatCanBang;

    nutMatCanBang->chieuCao = timMax(layChieuCao(nutMatCanBang->conTrai),
                                     layChieuCao(nutMatCanBang->conPhai)) + 1;

    nutConPhai->chieuCao = timMax(layChieuCao(nutConPhai->conTrai),
                                   layChieuCao(nutConPhai->conPhai)) + 1;

    nutMatCanBang = nutConPhai;
}
// Xoay kép trái phải (LR)
void xoayKepTraiPhai(NodeAVL *&nutGoc) {
    xoayTrai(nutGoc->conTrai);
    xoayPhai(nutGoc);
}
// Xoay kép phải trái (RL)
void xoayKepPhaiTrai(NodeAVL *&nutGoc) {
    xoayPhai(nutGoc->conPhai);
    xoayTrai(nutGoc);
}// Chèn một phần tử vào cây AVL
void chenAVL(int giaTriMoi, NodeAVL *&goc) {
    if (goc == NULL) {
        goc = new NodeAVL(giaTriMoi);
        return;
    }

    if (giaTriMoi < goc->giaTri) {
        chenAVL(giaTriMoi, goc->conTrai);

        if (doLech(goc) == 2) {
            if (giaTriMoi < goc->conTrai->giaTri)
                xoayPhai(goc);
            else
                xoayKepTraiPhai(goc);
        }
    }
    else if (giaTriMoi > goc->giaTri) {
        chenAVL(giaTriMoi, goc->conPhai);

        if (doLech(goc) == -2) {
            if (giaTriMoi > goc->conPhai->giaTri)
                xoayTrai(goc);
            else
                xoayKepPhaiTrai(goc);
        }
    }
    else {
        return; // Không chèn phần tử trùng
    }
    // Cập nhật lại chiều cao nút cha sau khi chèn/xoay xong
    goc->chieuCao = timMax(layChieuCao(goc->conTrai),
                           layChieuCao(goc->conPhai)) + 1;
}// Duyệt trước NLR
void duyetTruoc(NodeAVL *goc) {
    if (goc != NULL) {
        cout << goc->giaTri << " ";
        duyetTruoc(goc->conTrai);
        duyetTruoc(goc->conPhai);
    }
}
// Duyệt giữa LNR
void duyetGiua(NodeAVL *goc) {
    if (goc != NULL) {
        duyetGiua(goc->conTrai);
        cout << goc->giaTri << " ";
        duyetGiua(goc->conPhai);
    }
}
// Duyệt sau LRN
void duyetSau(NodeAVL *goc) {
    if (goc != NULL) {
        duyetSau(goc->conTrai);
        duyetSau(goc->conPhai);
        cout << goc->giaTri << " ";
    }
}