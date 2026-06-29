#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
const int MAX_TINH = 11;
const int VO_CUNG = 1e9;  
const string TEN_TINH[MAX_TINH] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" };
// Cấu trúc lưu trữ đồ thị giao thông dưới dạng ma trận kề
struct DoThiGiaoThong {   
    int soDinh;
    int maTranKe[MAX_TINH][MAX_TINH];
};
// Khởi tạo ma trận
void khoiTaoDoThi(DoThiGiaoThong &dt, int n) { 
    dt.soDinh = n;
    for (int i = 0; i < n; i++) {     
        for (int j = 0; j < n; j++) {
            dt.maTranKe[i][j] = 0; 
        }
    }
}
// Thêm đường đi hai chiều giữa hai tỉnh
void themTuyenDuong(DoThiGiaoThong &dt, int u, int v, int trongSo) {
    dt.maTranKe[u][v] = trongSo;  
    dt.maTranKe[v][u] = trongSo; 
}
//một cạnh (tuyến đường) trong đồ thị
struct TuyenDuong { 
    int u, v, ts; 
};
// in ma trận
void hienThiMaTran(int matrix[MAX_TINH][MAX_TINH], int n) {
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) { 
        cout << setw(5) << TEN_TINH[j]; 
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(6) << TEN_TINH[i];
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }  
}
// THUẬT TOÁN PRIM 
void giaiThuatPrim(DoThiGiaoThong &dt) {
    int n = dt.soDinh;
    bool daKetNap[MAX_TINH] = {false};  
    daKetNap[9] = true;  // Bắt đầu (HB có index là 9)

    // lưu trữ riêng cho cây khung thu được
    int maTranCayKhung[MAX_TINH][MAX_TINH] = {0}; 

    cout << "\n==================================================\n";
    cout << "THUAT TOAN PRIM (Khoi hanh tu tinh Hoa Binh):\n";