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
    for (int luotQuet = 0; luotQuet < n - 1; luotQuet++) { 
        int trongSoMin = VO_CUNG;
        int dinhU = -1, dinhV = -1;  

        for (int i = 0; i < n; i++) {
            if (daKetNap[i]) {   
                for (int j = 0; j < n; j++) {  
                    if (!daKetNap[j] && dt.maTranKe[i][j] > 0 && dt.maTranKe[i][j] < trongSoMin) { 
                        trongSoMin = dt.maTranKe[i][j];    
                        dinhU = i;
                        dinhV = j; 
                    }  
                } 
            }
        }
         
        if (dinhU != -1 && dinhV != -1) { 
            cout << "-> Chon tuyen: " << TEN_TINH[dinhU] << " - " << TEN_TINH[dinhV] << " (" << trongSoMin << ")\n";
            daKetNap[dinhV] = true;     
            
            // Cập nhật vào ma trận kề của cây khung
            maTranCayKhung[dinhU][dinhV] = trongSoMin; 
            maTranCayKhung[dinhV][dinhU] = trongSoMin;
        } else {
            break;  
        }
    }
    cout << "\nMA TRAN DINH KE CAY KHUNG MIN (PHUONG PHAP PRIM):\n";
    hienThiMaTran(maTranCayKhung, n);
}
//THUẬT TOÁN KRUSKAL
// Hàm tìm gốc
int timGocTapHop(int tapCha[], int i) {
    return (tapCha[i] == -1) ? i : timGocTapHop(tapCha, tapCha[i]);  
}

void giaiThuatKruskal(DoThiGiaoThong &dt) {
    int n = dt.soDinh;
    int tongSoCanh = 0;
    TuyenDuong danhSachCanh[100]; 
    
    int maTranCayKhung[MAX_TINH][MAX_TINH] = {0}; 

    // Trích xuất các cạnh
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (dt.maTranKe[i][j] > 0) {   
                danhSachCanh[tongSoCanh] = {i, j, dt.maTranKe[i][j]}; 
                tongSoCanh++;    
            } 
        }
    }

    // Sắp xếp danh sách các cạnh tăng dần theo trọng số
    for (int i = 0; i < tongSoCanh - 1; i++) {   
        for (int j = i + 1; j < tongSoCanh; j++) {
            if (danhSachCanh[i].ts > danhSachCanh[j].ts) {
                swap(danhSachCanh[i], danhSachCanh[j]);  
            }
        }
    }

    cout << "\n==================================================\n";
    cout << "THUAT TOAN KRUSKAL - Danh sach canh sau khi sap xep:\n"; 
    for (int i = 0; i < tongSoCanh; i++) {
        cout << TEN_TINH[danhSachCanh[i].u] << "-" << TEN_TINH[danhSachCanh[i].v] << ":" << danhSachCanh[i].ts << ((i < tongSoCanh - 1) ? ", " : "\n\n");
    }
    int tapCha[MAX_TINH];
    for (int i = 0; i < n; i++) {
        tapCha[i] = -1; 
    }

    cout << "Cac buoc phat trien cay khung:\n";
    for (int i = 0; i < tongSoCanh; i++) {
        int gocU = timGocTapHop(tapCha, danhSachCanh[i].u);
        int gocV = timGocTapHop(tapCha, danhSachCanh[i].v);

        // Nếu hai đỉnh không cùng gốc thì không tạo thành chu trình
        if (gocU != gocV) {  
            cout << "-> Them tuyen: " << TEN_TINH[danhSachCanh[i].u] << " - " << TEN_TINH[danhSachCanh[i].v] << " (" << danhSachCanh[i].ts << ")\n"; 
            
            // nhận cạnh này vào ma trận kề cây khung
            maTranCayKhung[danhSachCanh[i].u][danhSachCanh[i].v] = danhSachCanh[i].ts; 
            maTranCayKhung[danhSachCanh[i].v][danhSachCanh[i].u] = danhSachCanh[i].ts;
            
            // Hợp nhấtt 2 tập hợp lại với nhau
            tapCha[gocU] = gocV;            
        } 
    }

    // In ma trận 
    cout << "\nMA TRAN DINH KE CAY KHUNG MIN (PHUONG PHAP KRUSKAL):\n";
    hienThiMaTran(maTranCayKhung, n);
}
int main() {
    int n = MAX_TINH;
    DoThiGiaoThong doThi; 
    khoiTaoDoThi(doThi, n);
    
    //từ slide bài tập
    int cacTuyenGiaoThong[][3] = { 
        {0, 6, 1}, {6, 7, 2}, {8, 7, 3}, {0, 8, 4}, {0, 9, 5},    
        {0, 10, 6},{0, 1, 7}, {0, 2, 8}, {2, 3, 9}, {3, 4, 10}, 
        {2, 4, 11}, {4, 5, 12}, {6, 5, 13}   
    };
    int soLuongTuyen = sizeof(cacTuyenGiaoThong) / sizeof(cacTuyenGiaoThong[0]);
    
    for(int i = 0; i < soLuongTuyen; i++) { 
        themTuyenDuong(doThi, cacTuyenGiaoThong[i][0], cacTuyenGiaoThong[i][1], cacTuyenGiaoThong[i][2]);
    }
    
    cout << "               MA TRAN DO THI BAN DAU" << endl; 
    hienThiMaTran(doThi.maTranKe, n);

    //tính toán và in kết quả ma trận kề cây khung
    giaiThuatPrim(doThi);
    giaiThuatKruskal(doThi);
    
    return 0;
}